#include <iostream>
#include "User.h"
#include "Message.h"
#include "NotificationCenter.h"
#include "UnreadMessage.h"

int main() {
    User nick("Nick");
    User peter("Peter");
    std::shared_ptr<ChatRoom> shptr = nick.createChat(peter); //nick crea una chat con peter
    std::shared_ptr<ChatRoom> shptr2 = nick.detectChat(peter);

    Message msg1("Nick", "Peter", "Hey Peter what's up?");
    Message msg2("Peter", "Nick", "Hi Nick, I'm fine!");
    Message msg3("Nick", "Peter", "Well, did you pass the programming test?");
    Message msg4("Peter", "Nick", "Yeah, finally. Now I'm so happy.");

    NotificationCenter notifier(true, shptr);
    UnreadMessage unreadNotification(shptr);

    notifier.attach();
    unreadNotification.attach();

    shptr->attachMessage(msg1);
    shptr->attachMessage(msg2);
    shptr->attachMessage(msg3);
    shptr->attachMessage(msg4);

    shptr->readMessage(0);
    shptr->readMessage(2);

    nick.removeChat(peter);


    return 0;
}

