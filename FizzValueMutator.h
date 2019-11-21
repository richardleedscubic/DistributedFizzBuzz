#pragma once

#include "ValueMutator.h"

class FizzValueMutator : public ValueMutator
{
public:
	FizzValueMutator(const std::string& printIdentifier, unsigned int fizzFactor);
	std::string Mutate(unsigned int) override;

private:
	const std::string m_PrintIdentifier;
	const unsigned int m_FizzFactor;
};