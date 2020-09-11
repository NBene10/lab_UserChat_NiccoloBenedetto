//
// Created by nicco on 10/09/20.
//

#include "gtest/gtest.h"
#include "../User.h"

TEST(User, GetterSetter) {
    User luke("Luke");
    ASSERT_EQ(luke.getUsername(), "Luke");
    luke.setUsername("Paul");
    ASSERT_EQ(luke.getUsername(), "Paul");
}
