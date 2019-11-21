#pragma once

#include "ValueMutator.h"

class FizzBuzzMutatorPriorityListFactory
{
public:
    static std::shared_ptr<ValueMutator> Create();
};

