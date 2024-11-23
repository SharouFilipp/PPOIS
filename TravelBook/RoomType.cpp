#include "RoomType.h"
RoomType::RoomType(string name, string description, double price, int capacity)
    : name(name), description(description), price(price), capacity(capacity) {}

void RoomType::addMedia(Media* mediaFile) {
    media.push_back(mediaFile);
}

double RoomType::getPrice()  {
    return price;
}

void RoomType::setPrice(double newPrice) {
    price = newPrice;
}

int RoomType::getCapacity()  {
    return capacity;
}

void RoomType::removeMedia(int index) {
    if (index >= 0 && index < media.size()) {
        delete media[index];
        media.erase(media.begin() + index);
        cout << "Media removed at index " << index << ".\n";
    } else {
        cout << "Invalid index.\n";
    }
}

bool RoomType::hasMedia()  {
    return !media.empty();
}