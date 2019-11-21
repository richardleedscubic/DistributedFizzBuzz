#include "FizzBuzzMutatorPriorityListFactory.h"
#include "UnchangedValueMutator.h"
#include "PriorityListValueMutator.h"

std::shared_ptr<ValueMutator> FizzBuzzMutatorPriorityListFactory::Create()
{
    auto priorityListValueMutator = std::make_shared<PriorityListValueMutator>();

    priorityListValueMutator->Register(std::make_shared<UnchangedValueMutator>());

    return priorityListValueMutator;
}
