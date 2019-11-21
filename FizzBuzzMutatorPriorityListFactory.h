#pragma once

#include "ValueMutator.h"

#include <memory>

class FizzBuzzMutatorPriorityListFactory
{
public:
    static std::shared_ptr<ValueMutator> Create();
};

