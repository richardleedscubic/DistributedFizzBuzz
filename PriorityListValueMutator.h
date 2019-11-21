#pragma once

#include <vector>
#include "ValueMutator.h"

class PriorityListValueMutator : public ValueMutator
{
public:
    std::string Mutate(unsigned int);
    void Register(std::shared_ptr<ValueMutator> valueMutator);
private:
    std::vector<std::shared_ptr<ValueMutator> > priorityListValueMutators;
};

