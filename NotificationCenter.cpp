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
    if (notification) {
        plot(subject->lastMessage());
    }
}

void NotificationCenter::plot(const Message &msg) {
    time_t time = msg.getCurrentTime();
    char buff[100];
    struct tm *localTime = localtime(&time);
    strftime(buff, 100, "%I:%M%p", localTime);
    std::cout << "[NOTIFICATION MESSAGE] " << std::endl;
    std::cout << "[Last message sent at " << buff << " ]" << " - [Sender] --> " << msg.getSender()
              << " [Receiver] --> " << msg.getReceiver() << " (You)" << std::endl;
    std::cout << "[Testo]: " << msg.getTextMsg() << std::endl;
}

bool NotificationCenter::isNotification() const {
    return notification;
}

void NotificationCenter::setNotification(bool notification) {
    NotificationCenter::notification = notification;
}

