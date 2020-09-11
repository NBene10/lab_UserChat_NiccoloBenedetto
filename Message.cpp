//
// Created by nicco on 27/07/20.
//

#include "Message.h"

Message::Message(std::string send, std::string rec, std::string text, bool reading) : sender(send),
                                                                                      receiver(rec), textMsg(text),
                                                                                      read(reading) {
    time(&currentTime);
}

bool Message::operator==(const Message &msg) const {
    return (sender == msg.sender && receiver == msg.receiver && textMsg == msg.textMsg);
}

bool Message::operator!=(const Message &msg) const {
    return !(*this == msg);
}

