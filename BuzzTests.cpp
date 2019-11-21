// (C) 2019 Transport for London
// All rights reserved.  This information is confidential.  You may not
// reproduce, adapt or disclose this information or any part of the
// information, for any purpose without TfL’s written permission.  TfL
// makes no warranties or representations, and expressly disclaims all
// liability concerning this information

#include "BuzzMutator.h"
#include "PrinterSpy.h"
#include "FizzBuzzGenerator.h"

#include <gmock/gmock.h>

using ::testing::Eq;

class BuzzMutatorTests: public ::testing::Test
{
public:
    BuzzMutator mutator;
};

TEST_F(BuzzMutatorTests, FiveReturnsBuzz)
{
    EXPECT_THAT(mutator.Mutate(5), Eq("Buzz"));
}

TEST_F(BuzzMutatorTests, OneReturnsEmptyString)
{
    EXPECT_THAT(mutator.Mutate(1), Eq(""));
}

TEST(BuzzTests, FiveOutputsBuzz) {

    PrinterSpy printer;
    FizzBuzzGenerator fizzBuzzGenerator(printer);

    fizzBuzzGenerator.Generate();
    EXPECT_EQ("Buzz", printer.CallAtIndex(5));
}
