
#include "FizzValueMutator.h"

FizzValueMutator::FizzValueMutator(const std::string& printIdentifier, unsigned int fizzFactor)
	: m_PrintIdentifier(printIdentifier), m_FizzFactor(fizzFactor)
{}

std::string FizzValueMutator::Mutate(unsigned int value)
{
	return ((value + 1) % m_FizzFactor == 0 && !((value + 1) % 15 == 0)) ? m_PrintIdentifier : "";
}