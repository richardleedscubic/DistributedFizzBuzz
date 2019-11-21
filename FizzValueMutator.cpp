
#include "FizzValueMutator.h"

FizzValueMutator::FizzValueMutator(const std::string& printIdentifier, unsigned int fizzFactor)
	: m_PrintIdentifier(printIdentifier), m_FizzFactor(fizzFactor)
{}

std::string FizzValueMutator::Mutate(unsigned int value)
{
	bool div5 = value % 5 == 0;
	return (value % m_FizzFactor == 0 && !div5) ? m_PrintIdentifier : "";
}