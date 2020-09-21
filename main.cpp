#include <iostream>
#include "User.h"
#include "Message.h"
#include "NotificationCenter.h"
#include "UnreadMessage.h"

int main() {
    User nick("Nick");
    User peter("Peter");
    std::shared_ptr<ChatRoom> shptr = nick.createChat(peter); //nick crea una chat con peter

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

    try {
        shptr->readMessage(1);
        shptr->readMessage(3);
        shptr->readMessage(5); //EXCEPTION
    } catch (std::out_of_range &e) {
        std::cerr << "Out of range error:" << e.what() << std::endl;
    }

    nick.removeChat(peter);

    return 0;
}

