#pragma once
#include <iostream>
#include <string>
using namespace std;
class Support {
private:  
    string email;  
    string phone;
    string workingHours;
    string adress;
public:
    Support(string email, string phone, string workingHours, string adress);
    void updateAddress(string newAddress);
    bool isAvailable(string time);
    string getAdress();
};