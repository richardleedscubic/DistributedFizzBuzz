// Copyright: This software is the copyright of Cubic Transportation Systems Limited
// and the information therein may be the subject of a pending or granted
// patent. It may not be reproduced or used for any other purpose than that
// for which it is supplied without the written permission of Cubic
// Transportation Systems Limited.
// (C) CUBIC TRANSPORTATION SYSTEMS LTD 2019

#include "FizzBuzzValueMutator.h"

std::string FizzBuzzValueMutator::Mutate(unsigned int value)
{
   if (value == 15)
   {
       return "FizzBuzz";
   }
   return "";
}
