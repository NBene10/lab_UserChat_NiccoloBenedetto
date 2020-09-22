//
// Created by nicco on 29/07/20.
//

#include <iostream>
#include "UnreadMessage.h"

void UnreadMessage::attach() {
    std::shared_ptr<UnreadMessage> shptr = std::make_shared<UnreadMessage>(*this);
    subject->subscribe(shptr);
}

void UnreadMessage::detach() {
    std::shared_ptr<UnreadMessage> shptr = std::make_shared<UnreadMessage>(*this);
    subject->remove(shptr);
}

void UnreadMessage::update() {
    this->plot(subject->getUnreadMessages());
}

void UnreadMessage::plot(int unreadMessages) {
    std::cout << "[There are " << unreadMessages << " unread messages for " << subject->getFirstUserName() <<
              "]" << std::endl;
    std::cout << std::endl;
}

bool UnreadMessage::isUnreadMessage() const {
    if (subject->getUnreadMessages() > 0) {
        return true;
    } else {
        return false;
    }
}


