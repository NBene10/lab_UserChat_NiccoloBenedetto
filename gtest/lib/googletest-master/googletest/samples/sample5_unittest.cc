// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


// This sample teaches how to reuse a gtest fixture in multiple gtest
// cases by deriving sub-fixtures from it.
//
// When you define a gtest fixture, you specify the name of the gtest
// case that will use this fixture.  Therefore, a gtest fixture can
// be used by only one gtest case.
//
// Sometimes, more than one gtest cases may want to use the same or
// slightly different gtest fixtures.  For example, you may want to
// make sure that all tests for a GUI library don't leak important
// system resources like fonts and brushes.  In Google Test, you do
// this by putting the shared logic in a super (as in "super class")
// gtest fixture, and then have each gtest case use a fixture derived
// from this super fixture.

#include <limits.h>
#include <time.h>
#include "gtest/gtest.h"
#include "sample1.h"
#include "sample3-inl.h"

namespace {
// In this sample, we want to ensure that every gtest finishes within
// ~5 seconds.  If a gtest takes longer to run, we consider it a
// failure.
//
// We put the code for timing a gtest in a gtest fixture called
// "QuickTest".  QuickTest is intended to be the super fixture that
// other fixtures derive from, therefore there is no gtest case with
// the name "QuickTest".  This is OK.
//
// Later, we will derive multiple gtest fixtures from QuickTest.
    class QuickTest : public testing::Test {
    protected:
        // Remember that SetUp() is run immediately before a gtest starts.
        // This is a good place to record the start time.
        void SetUp() override { start_time_ = time(nullptr); }

        // TearDown() is invoked immediately after a gtest finishes.  Here we
        // check if the gtest was too slow.
        void TearDown() override {
            // Gets the time when the gtest finishes
            const time_t end_time = time(nullptr);

            // Asserts that the gtest took no more than ~5 seconds.  Did you
            // know that you can use assertions in SetUp() and TearDown() as
            // well?
            EXPECT_TRUE(end_time - start_time_ <= 5) << "The gtest took too long.";
        }

        // The UTC time (in seconds) when the gtest starts
        time_t start_time_;
    };


// We derive a fixture named IntegerFunctionTest from the QuickTest
// fixture.  All tests using this fixture will be automatically
// required to be quick.
    class IntegerFunctionTest : public QuickTest {
        // We don't need any more logic than already in the QuickTest fixture.
        // Therefore the body is empty.
    };


// Now we can write tests in the IntegerFunctionTest gtest case.

// Tests Factorial()
    TEST_F(IntegerFunctionTest, Factorial
    ) {
    // Tests factorial of negative numbers.
    EXPECT_EQ(1, Factorial(-5));
    EXPECT_EQ(1, Factorial(-1));
    EXPECT_GT(Factorial(-10),
    0);

    // Tests factorial of 0.
    EXPECT_EQ(1, Factorial(0));

    // Tests factorial of positive numbers.
    EXPECT_EQ(1, Factorial(1));
    EXPECT_EQ(2, Factorial(2));
    EXPECT_EQ(6, Factorial(3));
    EXPECT_EQ(40320, Factorial(8));
}


// Tests IsPrime()
TEST_F(IntegerFunctionTest, IsPrime
) {
// Tests negative input.
EXPECT_FALSE(IsPrime(-1)
);
EXPECT_FALSE(IsPrime(-2)
);
EXPECT_FALSE(IsPrime(INT_MIN)
);

// Tests some trivial cases.
EXPECT_FALSE(IsPrime(0)
);
EXPECT_FALSE(IsPrime(1)
);
EXPECT_TRUE(IsPrime(2)
);
EXPECT_TRUE(IsPrime(3)
);

// Tests positive input.
EXPECT_FALSE(IsPrime(4)
);
EXPECT_TRUE(IsPrime(5)
);
EXPECT_FALSE(IsPrime(6)
);
EXPECT_TRUE(IsPrime(23)
);
}


// The next gtest case (named "QueueTest") also needs to be quick, so
// we derive another fixture from QuickTest.
//
// The QueueTest gtest fixture has some logic and shared objects in
// addition to what's in QuickTest already.  We define the additional
// stuff inside the body of the gtest fixture, as usual.
class QueueTest : public QuickTest {
protected:
    void SetUp() override {
        // First, we need to set up the super fixture (QuickTest).
        QuickTest::SetUp();

        // Second, some additional setup for this fixture.
        q1_.Enqueue(1);
        q2_.Enqueue(2);
        q2_.Enqueue(3);
    }

    // By default, TearDown() inherits the behavior of
    // QuickTest::TearDown().  As we have no additional cleaning work
    // for QueueTest, we omit it here.
    //
    // virtual void TearDown() {
    //   QuickTest::TearDown();
    // }

    Queue<int> q0_;
    Queue<int> q1_;
    Queue<int> q2_;
};


// Now, let's write tests using the QueueTest fixture.

// Tests the default constructor.
TEST_F(QueueTest, DefaultConstructor
) {
EXPECT_EQ(0u, q0_.

Size()

);
}

// Tests Dequeue().
TEST_F(QueueTest, Dequeue
) {
int *n = q0_.Dequeue();
EXPECT_TRUE(n
== nullptr);

n = q1_.Dequeue();
EXPECT_TRUE(n
!= nullptr);
EXPECT_EQ(1, *n);
EXPECT_EQ(0u, q1_.

Size()

);
delete
n;

n = q2_.Dequeue();
EXPECT_TRUE(n
!= nullptr);
EXPECT_EQ(2, *n);
EXPECT_EQ(1u, q2_.

Size()

);
delete
n;
}
}  // namespace
// If necessary, you can derive further gtest fixtures from a derived
// fixture itself.  For example, you can derive another fixture from
// QueueTest.  Google Test imposes no limit on how deep the hierarchy
// can be.  In practice, however, you probably don't want it to be too
// deep as to be confusing.
