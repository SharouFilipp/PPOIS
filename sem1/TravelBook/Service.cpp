#include "Service.h"

Service::Service(string name, double price, string description)
    : name(name), price(price), description(description) {}

void Service::updatePrice(double newPrice) {
    price = newPrice;
}

double Service::getPrice()  {
    return price;
}

string Service::getDescription()  {
    return description;
}
string Service::getName()  {
    return name;
}