#include "FizzBuzzGenerator.h"
#include "FizzBuzzMutatorPriorityListFactory.h"

void FizzBuzzGenerator::Generate()
{
    FizzBuzzMutatorPriorityListFactory factory;

    std::shared_ptr<ValueMutator> priorityListValueMutator = factory.Create();

    for (int index = 1; index <= 100; index++)
    {
        printer.Print(priorityListValueMutator->Mutate(index));
    }
}
