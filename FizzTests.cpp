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
