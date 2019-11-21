#include "gtest/gtest.h"
#include "FizzBuzzGenerator.h"
#include "PrinterSpy.h"

TEST(FizzBuzzTests, FifteenOutputsFizzBuzz)
{
    PrinterSpy printer;
    FizzBuzzGenerator fizzBuzzGenerator(printer);

    fizzBuzzGenerator.Generate();
    EXPECT_EQ("FizzBuzz", printer.CallAtIndex(14));
}
