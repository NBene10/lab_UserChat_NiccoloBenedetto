//
// Created by nicco on 27/07/20.
//

#ifndef LAB_OBSERVER_H
#define LAB_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {};

    virtual void attach() = 0;

    virtual void detach() = 0;

    virtual void update() = 0;

};


#endif //LAB_OBSERVER_H
