#include "gtest/gtest.h"
#include "FizzBuzzGenerator.h"
#include "PrinterSpy.h"

TEST(ThreeOutputsFizz, FizzTests) {

    PrinterSpy printer;
    FizzBuzzGenerator fizzBuzzGenerator(printer);

    fizzBuzzGenerator.Generate();
	std::string ans = printer.CallAtIndex(2);
    EXPECT_EQ("Fizz", printer.CallAtIndex(2));
}

TEST(FizzTests, NineOutputsFizz) {

	PrinterSpy printer;
	FizzBuzzGenerator fizzBuzzGenerator(printer);

	fizzBuzzGenerator.Generate();
	std::string ans = printer.CallAtIndex(8);
	EXPECT_EQ("Fizz", printer.CallAtIndex(8));
}

TEST(FizzTests, FifteenOutputsEmptyString) {

	PrinterSpy printer;
	FizzBuzzGenerator fizzBuzzGenerator(printer);

	fizzBuzzGenerator.Generate();
	std::string ans = printer.CallAtIndex(14);
	EXPECT_EQ("FizzBuzz", printer.CallAtIndex(14));
}
