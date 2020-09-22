//
// Created by nicco on 28/07/20.
//

#include <iostream>
#include "NotificationCenter.h"

NotificationCenter::NotificationCenter(std::shared_ptr<ChatRoom> sub) : subject(sub) {

}

void NotificationCenter::attach() {
    std::shared_ptr<NotificationCenter> shptr = std::make_shared<NotificationCenter>(*this);
    subject->subscribe(shptr);
}

void NotificationCenter::detach() {
    std::shared_ptr<NotificationCenter> shptr = std::make_shared<NotificationCenter>(*this);
    subject->remove(shptr);
}

void NotificationCenter::update() {
    bool messageNotified = false;
    if (mexAlreadyNotif.empty()) {
        subject->setNotificationChat(true);
        plot(subject->lastMessage());
        messageNotified = true;
    } else {
        for (auto itr : mexAlreadyNotif) {
            if (itr == subject->lastMessage()) {
                messageNotified = true; //messaggio già notificato
                subject->setNotificationChat(false);//non c'è bisogno di lanciare una notifica
            }
        }
    }
    if (!mexAlreadyNotif.empty() && !messageNotified) {
        subject->setNotificationChat(true);
        plot(subject->lastMessage());
    }

}

void NotificationCenter::plot(const Message &msg) {
    time_t time = msg.getCurrentTime();
    char buff[100];
    struct tm *localTime = localtime(&time);
    strftime(buff, 100, "%I:%M%p", localTime);
    std::cout << "[MESSAGE NOTIFICATION] " << std::endl;
    std::cout << "[Last message sent at " << buff << " ]" << " - [Sender] --> " << msg.getSender()
              << " [Receiver] --> " << msg.getReceiver() << std::endl;
    std::cout << "[Text]: '" << msg.getTextMsg() << "'" << std::endl;
    mexAlreadyNotif.push_back(msg);
    //std::cout << std::endl;
}

bool NotificationCenter::isNotification() const {
    return notification;
}


