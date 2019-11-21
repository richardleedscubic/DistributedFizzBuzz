# (C) 2017 Transport for London
# All rights reserved.  This information is confidential.  You may not 
# reproduce, adapt or disclose this information or any part of the 
# information, for any purpose without TfL’s written permission.  TfL 
# makes no warranties or representations, and expressly disclaims all 
# liability concerning this information
cmake_minimum_required(VERSION 3.4)

if(__add_integration_test)
    return()
endif()

set(__add_integration_test YES)

if(NOT TARGET all_test)
    add_custom_target(all_test)
endif()

if(NOT TARGET all_integration_test)
    add_custom_target(all_integration_test)
endif()

if(NOT TARGET all_coverage)
    add_custom_target(all_coverage)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux" AND ${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64" )
    set(BUILD_HOST ON)
    set(BUILD_TARGET OFF)
else()
    set(BUILD_HOST OFF)
    set(BUILD_TARGET ON)
endif()

# setup Integration Test options
option(INTEGRATION_TEST_HOST "enable integration test execution on host" OFF)
option(INTEGRATION_TEST_TARGET "enable integration test execution on target" OFF)
option(INTEGRATION_TEST_MEMCHECK_HOST "enable integration memory checks (valgrind) on host" OFF)
option(INTEGRATION_TEST_MEMCHECK_TARGET "enable integration memory checks (valgrind) on target" OFF)
option(INTEGRATION_TEST_CPP_TEST_HOST "enable integration cppcheck on host" ON)
option(INTEGRATION_TEST_CPP_TEST_TARGET "enable integration cppcheck on target" ON)
option(INTEGRATION_TEST_COVERAGE_TEST_HOST "enable integration coverage checks on host" OFF)
option(INTEGRATION_TEST_COVERAGE_TEST_TARGET "enable integration coverage checks on target" OFF)



if((BUILD_HOST AND INTEGRATION_TEST_HOST) OR
   (BUILD_TARGET AND INTEGRATION_TEST_TARGET) OR
   (BUILD_HOST AND INTEGRATION_TEST_MEMCHECK_HOST) OR
   (BUILD_TARGET AND INTEGRATION_TEST_MEMCHECK_TARGET) OR
   (BUILD_HOST AND INTEGRATION_TEST_CPP_TEST_HOST) OR
   (BUILD_TARGET AND INTEGRATION_TEST_CPP_TEST_TARGET) OR
   (BUILD_HOST AND INTEGRATION_TEST_COVERAGE_TEST_HOST) OR
   (BUILD_TARGET AND INTEGRATION_TEST_COVERAGE_TEST_TARGET)
  )
    set(INTEGRATION_TEST TRUE CACHE BOOL "Integration tests enabled" FORCE)
endif()

################################################################
# Adds the test as a integration test, cppcheck, valgrind and coverage 
# as required
# Options:
# NAME - name of the target eg ${PROJECT_NAME}
# DEPENDENCIES - source file dependencies
# TARGET_LINK_LIBRARIES - list of library dependencies
# TARGET_INCLUDE_DIRECTORIES - additional directory include folders
# TARGET_DEPENDENCIES - additional target dependencies eg generated files
# CPPCHECK_OPTIONS - additional Cppcheck options
# LCOV_EXCLUDE - coverage excludes eg "'*/libGoogleTest/*';'*/libProtoBuff/*'"
# VALGRIND_OPTIONS - additional Valgrind options
# WORKING_DIRECTORY - Working directory for Integration test
###############################################################
function(add_integration_test)

    set(INTEGRATION_TEST_SUFFIX "_IntegrationTest")
    set(INTEGRATION_TEST_CPP_CHECK_SUFFIX "_CppCheckIntegrationTest")
    set(INTEGRATION_TEST_VALGRIND_SUFFIX "_ValgrindIntegrationTest")
    set(INTEGRATION_TEST_VALGRIND_VERBOSE_SUFFIX "_ValgrindVerboseIntegrationTest")
    set(INTEGRATION_TEST_COVERAGE_SUFFIX "_CoverageIntegrationTest")


    set(oneValueArgs NAME WORKING_DIRECTORY)
    set(multiValueArgs VALGRIND_OPTIONS CPPCHECK_OPTIONS DEPENDENCIES TARGET_INCLUDE_DIRECTORIES
            TARGET_LINK_LIBRARIES TARGET_DEPENDENCIES LCOV_EXCLUDE)

    cmake_parse_arguments(ADD_INTEGRATION_TEST "${options}" "${oneValueArgs}" "${multiValueArgs}" "${ARGN}" )

    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux" AND ${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64" )
        set(BUILD_HOST ON)
        set(BUILD_TARGET OFF)
    else()
        set(BUILD_HOST OFF)
        set(BUILD_TARGET ON)
    endif()

    # check if we need to build the target
    # integration tests, cppcheck, valgrind and coverage all require
    # a target to test
    if((BUILD_HOST AND INTEGRATION_TEST_HOST) OR
       (BUILD_TARGET AND INTEGRATION_TEST_TARGET) OR
       (BUILD_HOST AND INTEGRATION_TEST_MEMCHECK_HOST) OR
       (BUILD_TARGET AND INTEGRATION_TEST_MEMCHECK_TARGET) OR
       (BUILD_HOST AND INTEGRATION_TEST_CPP_TEST_HOST) OR
       (BUILD_TARGET AND INTEGRATION_TEST_CPP_TEST_TARGET) OR
       (BUILD_HOST AND INTEGRATION_TEST_COVERAGE_TEST_HOST) OR
       (BUILD_TARGET AND INTEGRATION_TEST_COVERAGE_TEST_TARGET)
       )

        add_executable(
            ${ADD_INTEGRATION_TEST_NAME}
            ${ADD_INTEGRATION_TEST_DEPENDENCIES}
        )

        target_include_directories(
            ${ADD_INTEGRATION_TEST_NAME} PUBLIC
            ${ADD_INTEGRATION_TEST_TARGET_INCLUDE_DIRECTORIES}
        )

        target_link_libraries(
            ${ADD_INTEGRATION_TEST_NAME}
            ${ADD_INTEGRATION_TEST_TARGET_LINK_LIBRARIES}
        )

        # calls to add_dependencies cannot contain
        # empty lists so iterate and add these to the target
        foreach(_depends ${ADD_INTEGRATION_TEST_TARGET_DEPENDENCIES})
            add_dependencies(
                ${ADD_INTEGRATION_TEST_NAME}
                ${_depends}
            )
        endforeach()

        # integration test
        if((BUILD_HOST AND INTEGRATION_TEST_HOST) OR
           (BUILD_TARGET AND INTEGRATION_TEST_TARGET))
            add_test(
                NAME
                    ${ADD_INTEGRATION_TEST_NAME}${INTEGRATION_TEST_SUFFIX}
                COMMAND
                    ${ADD_INTEGRATION_TEST_NAME} ${ARGS}
                WORKING_DIRECTORY
                    ${ADD_INTEGRATION_TEST_WORKING_DIRECTORY}
            )
            add_dependencies(all_integration_test ${ADD_INTEGRATION_TEST_NAME})

            set(INTEGRATION_TEST_TARGET ${ADD_INTEGRATION_TEST_NAME}${INTEGRATION_TEST_SUFFIX})

            # check if working directory has been set and if not use default
            if( "${ADD_INTEGRATION_TEST_WORKING_DIRECTORY}" STREQUAL "")
                set(ADD_INTEGRATION_TEST_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
            endif()

            add_custom_target(${INTEGRATION_TEST_TARGET}
                COMMAND
                    ${ADD_INTEGRATION_TEST_NAME} ${ADD_INTEGRATION_TEST_ARGN}
                DEPENDS
                    ${ADD_INTEGRATION_TEST_NAME}
                WORKING_DIRECTORY
                    "${ADD_INTEGRATION_TEST_WORKING_DIRECTORY}"
                COMMENT
                    "${INTEGRATION_TEST_TARGET}: Running integration test  ${ADD_INTEGRATION_TEST_NAME} ${ADD_INTEGRATION_TEST_ARGN}"
                VERBATIM
                    )

            add_dependencies(all_integration_test ${INTEGRATION_TEST_TARGET})
            add_dependencies(all_test ${INTEGRATION_TEST_TARGET})
        endif()

        # valgrind check
        if((BUILD_HOST AND INTEGRATION_TEST_MEMCHECK_HOST) OR
           (BUILD_TARGET AND INTEGRATION_TEST_MEMCHECK_TARGET))
            add_memcheck(
                NAME
                    ${ADD_INTEGRATION_TEST_NAME}
                SUFFIX
                    ${INTEGRATION_TEST_VALGRIND_SUFFIX}
                OPTIONS
                    ${ADD_INTEGRATION_TEST_VALGRIND_OPTIONS}
                WORKING_DIRECTORY
                    ${ADD_INTEGRATION_TEST_WORKING_DIRECTORY}
            )
            add_memcheck(
                NAME
                    ${ADD_INTEGRATION_TEST_NAME}
                SUFFIX
                    ${INTEGRATION_TEST_VALGRIND_VERBOSE_SUFFIX}
                VERBOSE
                    "YES"
                OPTIONS
                    ${ADD_INTEGRATION_TEST_VALGRIND_OPTIONS}
                WORKING_DIRECTORY
                    ${ADD_INTEGRATION_TEST_WORKING_DIRECTORY}
            )
        endif()

        # cppcheck
        if((BUILD_HOST AND INTEGRATION_TEST_CPP_TEST_HOST) OR
           (BUILD_TARGET AND INTEGRATION_TEST_CPP_TEST_TARGET))
        endif()

        if((BUILD_HOST AND INTEGRATION_TEST_COVERAGE_TEST_HOST) OR
           (BUILD_TARGET AND INTEGRATION_TEST_COVERAGE_TEST_TARGET))
            set(LCOV_REMOVE_EXTRA ${ADD_INTEGRATION_TEST_LCOV_EXCLUDE} )
            set(LCOV_TARGET_NAME ${ADD_INTEGRATION_TEST_NAME}${INTEGRATION_TEST_COVERAGE_SUFFIX})
            setup_target_for_coverage(${LCOV_TARGET_NAME} ${ADD_INTEGRATION_TEST_NAME} ${LCOV_TARGET_NAME})
            add_dependencies(all_coverage ${LCOV_TARGET_NAME})
        endif()
    endif()
endfunction()


