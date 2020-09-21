//
// Created by nicco on 28/07/20.
//

#include "User.h"


std::shared_ptr<ChatRoom> User::createChat(User &user) {
    ChatRoom *chat = new ChatRoom((*this), user);
    std::shared_ptr<ChatRoom> shptr = std::make_shared<ChatRoom>(*chat);
    user.addChat(shptr, *this);
    return shptr;
}


void User::addChat(std::shared_ptr<ChatRoom> chat, User &user) {
    chats.insert(std::make_pair(user.getUsername(), chat));
}

void User::removeChat(const User &user) {
    auto itr = chats.find(user.getUsername());
    chats.erase(itr);
}




