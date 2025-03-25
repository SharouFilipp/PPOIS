#include "Transport.h"

Transport::Transport(string type, int price) 
        : type(type), price(price) {}

void Transport::updateType(string newType) {
    type = newType;
}

string Transport::getType() {
    return type;
}

int Transport::getPrice() {
    return price;
}

