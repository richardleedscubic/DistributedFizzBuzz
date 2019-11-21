#include "PriorityListValueMutator.h"



std::string PriorityListValueMutator::Mutate(unsigned int value)
{
    std::string mutatedValueText;
    for (auto& mutator : priorityListValueMutators)
    {
        mutatedValueText = mutator->Mutate(value);

        if (mutatedValueText != "")
        {
            break;
        }
    }

    return mutatedValueText;

}

void PriorityListValueMutator::Register(std::shared_ptr<ValueMutator> valueMutator)
{
    priorityListValueMutators.push_back(valueMutator);
}