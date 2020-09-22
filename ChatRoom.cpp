//
// Created by nicco on 28/07/20.
//
#include <iostream>
#include "ChatRoom.h"


ChatRoom::ChatRoom(const User &user1, const User &user2) : firstUser_name(user1.getUsername()),
                                                           secondUser_name(user2.getUsername()) {

}

void ChatRoom::subscribe(std::shared_ptr<Observer> ob) {
    observers.push_back(ob);
}

void ChatRoom::remove(std::shared_ptr<Observer> ob) {
    observers.remove(ob);
}

void ChatRoom::notifyAll() {
    for (auto itr : observers) {
        (itr)->update();
    }
}

bool ChatRoom::verifyUsersMsg(std::string sender, std::string receiver) {
    return ((firstUser_name == sender || firstUser_name == receiver) && (secondUser_name == sender ||
                                                                         secondUser_name == receiver));

}

void ChatRoom::attachMessage(const Message &newMsg) {
    if (verifyUsersMsg(newMsg.getSender(), newMsg.getReceiver())) {
        messages.push_back(newMsg);
    } else {
        throw std::out_of_range("ERROR: user not found.");
    }
    if (firstUser_name == newMsg.getReceiver()) {
        this->notifyAll();
    }
}

void ChatRoom::readMessage(const int index) {
    if (index >= 0 && index < messages.size()) {
        if (messages[index].getSender() == secondUser_name) {
            std::cout << messages[index].getReceiver() << " now is reading the following message: " << std::endl;
            std::cout << "[Sender] --> " << messages[index].getSender() << " - " << "[Receiver] --> " <<
                      messages[index].getReceiver() << std::endl;
            std::cout << "Text Message: '" << messages[index].getTextMsg() << "'" << std::endl;
            messages[index].setRead(true);
            this->notifyAll();
        }
    } else {
        throw std::out_of_range("ERROR: message isn't present in the chatroom");
    }
}

int ChatRoom::getUnreadMessages() const {
    int unreadMessages = 0;
    for (auto itr : messages) {
        if (itr.getReceiver() == firstUser_name) {
            if (!itr.isRead()) {
                unreadMessages++;
            }
        }
    }
    return unreadMessages;
}

const std::string &ChatRoom::getFirstUserName() const {
    return firstUser_name;
}

void ChatRoom::setFirstUserName(const std::string &firstUserName) {
    firstUser_name = firstUserName;
}

const std::string &ChatRoom::getSecondUserName() const {
    return secondUser_name;
}

void ChatRoom::setSecondUserName(const std::string &secondUserName) {
    secondUser_name = secondUserName;
}

const Message &ChatRoom::lastMessage() const {
    return messages.back();
}

bool ChatRoom::isNotificationChat() const {
    return notificationChat;
}

void ChatRoom::setNotificationChat(bool notificationChat) {
    ChatRoom::notificationChat = notificationChat;
}
