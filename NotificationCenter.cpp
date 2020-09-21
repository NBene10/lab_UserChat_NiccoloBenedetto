//
// Created by nicco on 28/07/20.
//

#include <iostream>
#include "NotificationCenter.h"

NotificationCenter::NotificationCenter(bool notif, std::shared_ptr<ChatRoom> sub) : notification(notif),
                                                                                    subject(sub) {

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
    if (notification) {
        if (mexAlreadyNotif.empty()) {
            plot(subject->lastMessage());
            messageNotified = true;
        } else {
            for (auto itr : mexAlreadyNotif) {
                if (itr == subject->lastMessage()) {
                    messageNotified = true;
                }
            }
        }
        if (!mexAlreadyNotif.empty() && !messageNotified) {
            plot(subject->lastMessage());
        }
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

void NotificationCenter::setNotification(bool notification) {
    NotificationCenter::notification = notification;
}

