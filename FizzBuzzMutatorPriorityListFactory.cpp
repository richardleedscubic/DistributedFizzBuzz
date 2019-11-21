#include "FizzBuzzMutatorPriorityListFactory.h"

#include "FizzBuzzValueMutator.h"
#include "FizzValueMutator.h"
#include "UnchangedValueMutator.h"
#include "PriorityListValueMutator.h"
#include "BuzzMutator.h"

std::shared_ptr<ValueMutator> FizzBuzzMutatorPriorityListFactory::Create()
{
    auto priorityListValueMutator = std::make_shared<PriorityListValueMutator>();

    priorityListValueMutator->Register(std::make_shared<FizzBuzzValueMutator>());
	priorityListValueMutator->Register(std::make_shared<FizzValueMutator>("Fizz", 3));
    priorityListValueMutator->Register(std::make_shared<BuzzMutator>());
    priorityListValueMutator->Register(std::make_shared<UnchangedValueMutator>());

    return priorityListValueMutator;
}
