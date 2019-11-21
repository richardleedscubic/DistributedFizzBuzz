#pragma once

#include "Printer.h"

class FizzBuzzGenerator
{
public:
	FizzBuzzGenerator(Printer& initPrinter) : printer(initPrinter) {}
	void Generate();
private:
	Printer& printer;
};
