#pragma once
#include <string>
#include <vector>

#include "Printer.h"

class PrinterSpy : public Printer
{
public:
	void Print(std::string text);
	std::string CallAtIndex(unsigned int index);
private:
	std::vector<std::string> printStatements;
};
