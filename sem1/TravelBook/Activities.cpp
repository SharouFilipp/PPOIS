#include "Activities.h"


Activities::Activities(string name, string description, string location, double price) 
        : name(name), description(description), location(location), price(price) {}

string Activities::getLocation(){
    return location;
}

string Activities::getDescription(){
    return description;
}

double Activities::getPrice(){
    return price;
}
void Activities::setPrice(double newPrice){
    price = newPrice;
}
void Activities::setDescription(string newDescription){
    description = newDescription;
}