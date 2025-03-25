#pragma once
#include <iostream>
#include <string>
using namespace std;

class Service {
private:
    string name;
    double price;
    string description;   
public:
    Service(string name, double price, string description);
    void updatePrice(double newPrice);
    double getPrice();
    string getDescription();
    string getName();
};
