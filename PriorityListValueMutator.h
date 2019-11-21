#pragma once

#include "ValueMutator.h"

#include <memory>
#include <vector>

class PriorityListValueMutator : public ValueMutator
{
public:
    std::string Mutate(unsigned int);
    void Register(std::shared_ptr<ValueMutator> valueMutator);
private:
    std::vector<std::shared_ptr<ValueMutator> > priorityListValueMutators;
};

