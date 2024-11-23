#pragma once
#include <iostream>
#include <string>
using namespace std;

class Transport
{
private:
    string type;
    int price;
public:
    Transport(string type,int price);
    void updateType(string newType);
    int getPrice();
    string getType();
};