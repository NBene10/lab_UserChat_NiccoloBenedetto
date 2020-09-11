//
// Created by nicco on 10/09/20.
//

#include "gtest/gtest.h"
#include "../ChatRoom.h"


User nick("Nick");
User peter("Peter");

TEST(Chat, GetterSetter) {
    ChatRoom chat(nick, peter);
    ASSERT_EQ(chat.getFirstUserName(), "Nick");
    chat.setFirstUserName("Jack");
    ASSERT_EQ(chat.getFirstUserName(), "Jack");
    ASSERT_EQ(chat.getSecondUserName(), "Peter");
    chat.setSecondUserName("Frank");
    ASSERT_EQ(chat.getSecondUserName(), "Frank");
}

TEST(Chat, functions) {
    ChatRoom chat(nick, peter);
    Message mex("Peter", "Nick", "Hi Nick, what's up?");
    chat.attachMessage(mex);
    ASSERT_EQ(chat.lastMessage(), mex);
    ASSERT_THROW(chat.readMessage(2), std::out_of_range);
    ASSERT_THROW(chat.readMessage(1), std::out_of_range);
}