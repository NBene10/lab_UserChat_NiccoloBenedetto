//
// Created by nicco on 27/07/20.
//


#ifndef LAB_MESSAGE_H
#define LAB_MESSAGE_H

#include <string>

class Message {
public:
    Message(std::string send, std::string rec, std::string text, bool reading = false);

    bool isRead() const {
        return read;
    }

    void setRead(bool read) {
        Message::read = read;
    }

    const std::string &getSender() const {
        return sender;
    }

    void setSender(const std::string &sender) {
        Message::sender = sender;
    }

    const std::string &getReceiver() const {
        return receiver;
    }

    void setReceiver(const std::string &receiver) {
        Message::receiver = receiver;
    }

    const std::string &getTextMsg() const {
        return textMsg;
    }

    void setTextMsg(const std::string &textMsg) {
        Message::textMsg = textMsg;
    }

    time_t getCurrentTime() const {
        return currentTime;
    }

    void setCurrentTime(time_t currentTime) {
        Message::currentTime = currentTime;
    }

    bool operator==(const Message &msg) const;

    bool operator!=(const Message &msg) const;

private:
    bool read;
    std::string sender, receiver, textMsg;
    time_t currentTime;
};


#endif //LAB_MESSAGE_H
