#pragma once
#include <iostream>
#include <vector>
#include "Booking.h"
#include "Service.h"
using namespace std; 

class ExtendBooking : public Booking {
private:
    vector<Service*> additionalServices; 
    double extendPrice;
public:
    ExtendBooking(Hotel* hotel, User* user, string checkInDate, string checkOutDate);
    void addService(Service* service);
    void removeService(int index);
    double calculateTotalServiceCost();
};