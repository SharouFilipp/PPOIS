#pragma once
#include <iostream>
#include "User.h"
#include "Hotel.h"
using namespace std;

class Booking {
protected:
    Hotel* hotel;                  
    User* user;          
    string checkInDate;            
    string checkOutDate;          
    double totalPrice;
public:
    Booking(Hotel* hotel, User* user, string checkInDate, string checkOutDate);
    double getTotalPrice();
    void setTotalPrice(double price);
    string getCheckInDate();
    Hotel* getHotel();
    bool isValidBooking();
};