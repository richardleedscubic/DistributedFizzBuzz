#include "gtest/gtest.h"
#include "FizzBuzzGenerator.h"
#include "PrinterSpy.h"

TEST(ThreeOutputsFizz, FizzTests) {

    PrinterSpy printer;
    FizzBuzzGenerator fizzBuzzGenerator(printer);

    fizzBuzzGenerator.Generate();
    EXPECT_EQ("Fizz", printer.CallAtIndex(2));
}
