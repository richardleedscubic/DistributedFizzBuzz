// Copyright: This software is the copyright of Cubic Transportation Systems Limited
// and the information therein may be the subject of a pending or granted
// patent. It may not be reproduced or used for any other purpose than that
// for which it is supplied without the written permission of Cubic
// Transportation Systems Limited.
// (C) CUBIC TRANSPORTATION SYSTEMS LTD 2019

#ifndef DISTRIBUTEDFIZZBUZZ_FIZZBUZZVALUEMUTATOR_H
#define DISTRIBUTEDFIZZBUZZ_FIZZBUZZVALUEMUTATOR_H

#include "ValueMutator.h"

class FizzBuzzValueMutator : public ValueMutator
{
public:
     std::string Mutate(unsigned int) override;
};


#endif //DISTRIBUTEDFIZZBUZZ_FIZZBUZZVALUEMUTATOR_H
