#include "gtest/gtest.h"
#include "FizzBuzzGenerator.h"
#include "PrinterSpy.h"

class FizzBuzzTests : public ::testing::Test
{
public:
    FizzBuzzTests()
        : fizzBuzzGenerator(printer)
    {}

    void SetUp() override
    {
        fizzBuzzGenerator.Generate();
    }

public:
    PrinterSpy printer;
    FizzBuzzGenerator fizzBuzzGenerator;
};

TEST_F(FizzBuzzTests, FifteenOutputsFizzBuzz)
{
    EXPECT_EQ("FizzBuzz", printer.CallAtIndex(14));
}

TEST_F(FizzBuzzTests, ThirtyOutputsFizzBuzz)
{
    EXPECT_EQ("FizzBuzz", printer.CallAtIndex(29));
}

TEST_F(FizzBuzzTests, FortyFiveOutputsFizzBuzz)
{
    EXPECT_EQ("FizzBuzz", printer.CallAtIndex(44));
}
