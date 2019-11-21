#pragma once
#include <string>

class ValueMutator
{
public:
    virtual std::string Mutate(unsigned int) = 0;
};
