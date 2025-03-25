#include "Support.h"

Support::Support(string email, string phone, string workingHours, string adress) 
        : email(email), phone(phone), workingHours(workingHours), adress(adress) {}

bool Support::isAvailable(string time) {
    return (time >= "09:00" && time <= "17:30");
}
void Support::updateAddress(string newAdress){
    adress = newAdress;
}
string Support::getAdress(){
    return adress;
}