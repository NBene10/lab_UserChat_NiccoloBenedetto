//
// Created by nicco on 29/07/20.
//
#ifndef LAB_UNREADMESSAGE_H
#define LAB_UNREADMESSAGE_H

#include "ChatRoom.h"

class UnreadMessage : public Observer {
public:

    explicit UnreadMessage(std::shared_ptr<ChatRoom> subj) : subject(subj) {}

    virtual ~UnreadMessage() = default;

    virtual void attach() override;

    virtual void detach() override;

    virtual void update() override;

    void plot(int unreadMessage);

private:
    std::shared_ptr<ChatRoom> subject;

};


#endif //LAB_UNREADMESSAGE_H
