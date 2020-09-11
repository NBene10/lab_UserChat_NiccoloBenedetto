//
// Created by nicco on 10/09/20.
//

#include "gtest/gtest.h"
#include "../NotificationCenter.h"

TEST(MessageNotifier, isActive) {
    User nick("Nick");
    User peter("Peter");
    ChatRoom *chat = new ChatRoom(nick, peter);
    std::shared_ptr<ChatRoom> Chptr = std::make_shared<ChatRoom>(*chat);
    NotificationCenter notCent(true, Chptr);
    ASSERT_TRUE(notCent.isNotification());
    notCent.setNotification(false);
    ASSERT_FALSE(notCent.isNotification());
}
