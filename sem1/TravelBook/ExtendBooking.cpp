#include "ExtendBooking.h"


ExtendBooking::ExtendBooking(Hotel* hotel, User* user, string checkInDate, string checkOutDate)
    : Booking(hotel, user, checkInDate, checkOutDate), extendPrice(0.0) {}


void ExtendBooking::addService(Service* service) {
    additionalServices.push_back(service);
}

void ExtendBooking::removeService(int index) {
    if (index >= 0 && index < additionalServices.size()) {
        delete additionalServices[index]; 
        additionalServices.erase(additionalServices.begin() + index);
        cout << "Service removed at index " << index << "." << endl;
    } else {
        cout << "Invalid index. Unable to remove service." << endl;
    }
}

double ExtendBooking::calculateTotalServiceCost()  {
    double totalPrice = 0.0;
    for (const auto& service : additionalServices) {
        totalPrice += service->getPrice();
    }
    totalPrice += extendPrice;
    return totalPrice;
}