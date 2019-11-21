#include "PrinterSpy.h"
#include <exception>
#include <stdexcept>

void PrinterSpy::Print(std::string text)
{
	printStatements.push_back(text);
}

std::string PrinterSpy::CallAtIndex(unsigned int callIndex)
{
	if (callIndex >= printStatements.size())
	{
        std::string errorText = "Requested call ";
        errorText += std::to_string(callIndex);
        errorText += " when ";
        errorText += std::to_string(printStatements.size());
        errorText += " calls were made";

        throw std::runtime_error(errorText.c_str());
	}
	return (printStatements[callIndex]);
}