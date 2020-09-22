//
// Created by nicco on 28/07/20.
//


#ifndef LAB_NOTIFICATIONCENTER_H
#define LAB_NOTIFICATIONCENTER_H

#include "ChatRoom.h"

class NotificationCenter : public Observer {
public:

    virtual ~NotificationCenter() = default;

    explicit NotificationCenter(std::shared_ptr<ChatRoom> sub);

    virtual void attach() override;

    virtual void detach() override;

    virtual void update() override;

    void plot(const Message &msg);

    bool isNotification() const;


private:
    bool notification = true;
    std::shared_ptr<ChatRoom> subject;
    std::vector<Message> mexAlreadyNotif;
};

#endif //LAB_NOTIFICATIONCENTER_H
