#pragma once
#include "ValueMutator.h"

class UnchangedValueMutator : public ValueMutator
{
public:
    std::string Mutate(unsigned int);
};

