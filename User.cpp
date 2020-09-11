//
// Created by nicco on 28/07/20.
//

#include "User.h"


std::shared_ptr<ChatRoom> User::createChat(User &user) {
    ChatRoom *chat = new ChatRoom((*this), user); //crea una chat dove il primo utente è colui
    //che apre la chat e il secondo è il ricevitore
    std::shared_ptr<ChatRoom> shptr = std::make_shared<ChatRoom>(*chat); //creo lo smart pointer shared
    //che contiene l'oggeto chat
    //instanziato sopra
    chats.insert(std::make_pair(user.getUsername(), shptr)); //inserisce nella mappa associativa
    //la coppia
    //(utente ricevitore;chat)
    user.addChat(shptr, *this);
    return shptr;
}

std::shared_ptr<ChatRoom> User::detectChat(const User &user) {
    auto itr = chats.find(user.getUsername());
    return (itr->second); //ottengo un puntatore alla chat trovata
    //si tenga presente che chats è una mappa associativa
}

void User::addChat(std::shared_ptr<ChatRoom> chat, User &user) {
    chats.insert(std::make_pair(user.getUsername(), chat));
}

void User::removeChat(const User &user) {
    auto itr = chats.find(user.getUsername());
    chats.erase(itr);
}




