// (C) 2019 Transport for London
// All rights reserved.  This information is confidential.  You may not
// reproduce, adapt or disclose this information or any part of the
// information, for any purpose without TfL’s written permission.  TfL
// makes no warranties or representations, and expressly disclaims all
// liability concerning this information

#ifndef BuzzMutator_H
#define BuzzMutator_H

#include "ValueMutator.h"

class BuzzMutator: public ValueMutator
{
public:
    std::string Mutate(unsigned int i) override;
};

#endif
