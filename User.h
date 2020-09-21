//
// Created by nicco on 27/07/20.
//

#ifndef LAB_USER_H
#define LAB_USER_H

#include <map>
#include "ChatRoom.h"
#include <memory>

class ChatRoom;

class User {
public:

    ~User() = default;

    explicit User(const std::string &name) : username(name) {};

    const std::string &getUsername() const {
        return username;
    }

    void setUsername(const std::string &username) {
        User::username = username;
    }

    std::shared_ptr<ChatRoom> createChat(User &user);

    void addChat(std::shared_ptr<ChatRoom> chat, User &user);

    void removeChat(const User &user);


private:
    std::string username;
    std::map<std::string, std::shared_ptr<ChatRoom>> chats; //mappa associativa stringa-chatroom
};

#endif //LAB_USER_H
