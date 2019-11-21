#include "gtest/gtest.h"
#include "FizzBuzzGenerator.h"
#include "PrinterSpy.h"
TEST(OneOutputsItself, UnchangedNumberTests) {
  
	PrinterSpy printer;
	FizzBuzzGenerator fizzBuzzGenerator(printer);

	fizzBuzzGenerator.Generate();
	EXPECT_EQ("1", printer.CallAtIndex(0));
}

TEST(TwoOutputsItself, UnchangedNumberTests) {

    PrinterSpy printer;
    FizzBuzzGenerator fizzBuzzGenerator(printer);

    fizzBuzzGenerator.Generate();
    EXPECT_EQ("2", printer.CallAtIndex(1));
}
