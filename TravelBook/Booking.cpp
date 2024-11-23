#include "Booking.h"

Booking::Booking(Hotel* hotel, User* user,  string checkInDate,  string checkOutDate)
    : hotel(hotel), user(user), checkInDate(checkInDate), checkOutDate(checkOutDate), totalPrice(0.0) {}

double Booking::getTotalPrice() {
    return totalPrice;
}

void Booking::setTotalPrice(double price) {
    totalPrice = price;
}

string Booking::getCheckInDate()  {
    return checkInDate;
}

Hotel* Booking::getHotel()  {
    return hotel;
}

bool Booking::isValidBooking()  {
    return checkInDate < checkOutDate;
}