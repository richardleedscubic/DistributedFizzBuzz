#include "gtest/gtest.h"
#include "FizzBuzzGenerator.h"
#include "PrinterSpy.h"
TEST(UnchangedNumberTests, OneOutputsItself) {
  
	PrinterSpy printer;
	FizzBuzzGenerator fizzBuzzGenerator(printer);

	fizzBuzzGenerator.Generate();
	EXPECT_EQ("1", printer.CallAtIndex(0));
}

TEST(UnchangedNumberTests, TwoOutputsItself) {

    PrinterSpy printer;
    FizzBuzzGenerator fizzBuzzGenerator(printer);

    fizzBuzzGenerator.Generate();
    EXPECT_EQ("2", printer.CallAtIndex(1));
}
