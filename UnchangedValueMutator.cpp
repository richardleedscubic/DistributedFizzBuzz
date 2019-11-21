#include "UnchangedValueMutator.h"

std::string UnchangedValueMutator::Mutate(unsigned int value)
{
    return (std::to_string(value));
}

