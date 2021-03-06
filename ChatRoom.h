//
// Created by nicco on 28/07/20.
//

#ifndef LAB_CHATROOM_H
#define LAB_CHATROOM_H

#include <string>
#include <list>
#include <vector>
#include <memory>

#include "Message.h"
#include "Subject.h"
#include "User.h"

class User;

class ChatRoom : public Subject {
public:
    virtual ~ChatRoom() = default;

    explicit ChatRoom(const User &user1, const User &user2);

    virtual void subscribe(std::shared_ptr<Observer> ob) override;

    virtual void remove(std::shared_ptr<Observer> ob) override;

    virtual void notifyAll() override;

    void attachMessage(const Message &newMsg);

    bool verifyUsersMsg(const std::string user1, const std::string user2);

    void readMessage(const int index);

    int getUnreadMessages() const;

    const Message &lastMessage() const;

    const std::string &getFirstUserName() const;

    void setFirstUserName(const std::string &firstUserName);

    const std::string &getSecondUserName() const;

    void setSecondUserName(const std::string &secondUserName);

    bool isNotificationChat() const;

    void setNotificationChat(bool notificationChat);

private:
    std::string firstUser_name;
    std::string secondUser_name;
    std::vector<Message> messages;
    bool notificationChat;
    std::list<std::shared_ptr<Observer>> observers;

};


#endif //LAB_CHATROOM_H
