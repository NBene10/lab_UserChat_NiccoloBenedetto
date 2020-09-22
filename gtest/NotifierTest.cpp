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
    NotificationCenter notCent(Chptr);
    notCent.attach();
    ASSERT_FALSE(Chptr->isNotificationChat());//nessun messaggio inviato a Nick, quindi nessuna notifica
    Message mex("Peter", "Nick", "Hi Nick, what's up?");
    Chptr->attachMessage(mex);//mando un messaggio a Peter
    ASSERT_TRUE(Chptr->isNotificationChat());//deve arrivare la notifica
}
