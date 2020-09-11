//
// Created by nicco on 10/09/20.
//

#include "gtest/gtest.h"
#include "../Message.h"


TEST(Message, GetterSetter) {
    Message mex("Nick", "Peter", "Hi Peter, what's up?");
    ASSERT_EQ(mex.getSender(), "Nick");
    ASSERT_EQ(mex.getReceiver(), "Peter");
    ASSERT_EQ(mex.getTextMsg(), "Hi Peter, what's up?");
    ASSERT_EQ(mex.isRead(), false);
    mex.setRead(true);
    ASSERT_EQ(mex.isRead(), true);

}
