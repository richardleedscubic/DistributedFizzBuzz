cmake_minimum_required(VERSION 3.5)

project(DistributedFizzBuzz)

set(CMAKE_CXX_STANDARD 14)

include(IntegrationTestTarget.cmake)

add_subdirectory(libGoogleTest)

set(SRCS
    FizzBuzzGenerator.h
    FizzBuzzMutatorPriorityListFactory.h
    Printer.h
    PrinterSpy.h
    PriorityListValueMutator.h
    UnchangedValueMutator.h
    ValueMutator.h
    ValueMutatorFactory.h
    FizzBuzzGenerator.cpp
    FizzBuzzMutatorPriorityListFactory.cpp
    FizzTests.cpp
    PrinterSpy.cpp
    PriorityListValueMutator.cpp
    UnchangedNumberTests.cpp
    UnchangedValueMutator.cpp
    ValueMutatorFactory.cpp
    )

add_integration_test(
    NAME
        ${PROJECT_NAME}

    DEPENDENCIES
        ${SRCS}

    TARGET_LINK_LIBRARIES
        gmock
        gmock_main

    TARGET_INCLUDE_DIRECTORIES
        libGoogleTest/googletest/include
    )
