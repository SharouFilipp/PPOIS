#pragma once
#include <iostream>
#include <string>
#include "Transport.h"
using namespace std;

class TransportWay {
private:
    Transport* transport; 
    string startPoint;     
    string endPoint;      
    string departureTime;  
public:
    TransportWay(Transport* transport, string startPoint, string endPoint, string depatureTime);
    void updateDepartureTime(string newDepartureTime);
    string getStartPoint();
    string getEndPoint();
    void displayInfo();
    string getDepartureTime();
    Transport* getTransport();
};