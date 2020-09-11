//
// Created by nicco on 27/07/20.
//

#ifndef LAB_SUBJECT_H
#define LAB_SUBJECT_H

#include <memory>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {};

    virtual void subscribe(std::shared_ptr<Observer> ob) = 0;

    virtual void remove(std::shared_ptr<Observer> ob) = 0;

    virtual void notifyAll() = 0;
};


#endif //LAB_SUBJECT_H
