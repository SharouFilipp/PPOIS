#pragma once
#include <string>
#include <iostream>
using namespace std;

class Activities {
private:                        
    string name;               
    string description;        
    string location;           
    double price; 
public:
    Activities(string name, string description, string location, double price);
    string getLocation() ;
    double getPrice() ;
    void setPrice(double newPrice);
    void setDescription(string newDescription);
    string getDescription();
};