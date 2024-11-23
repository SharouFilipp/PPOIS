#include "TransportWay.h"

TransportWay::TransportWay(Transport* transport,  string startPoint,  string endPoint,  string departureTime)
    : transport(transport), startPoint(startPoint), endPoint(endPoint), departureTime(departureTime) {}

void TransportWay::updateDepartureTime( string newDepartureTime) {
    departureTime = newDepartureTime;
}

string TransportWay::getStartPoint()  {
    return startPoint;
}

string TransportWay::getEndPoint()  {
    return endPoint;
}

string TransportWay::getDepartureTime() {
    return departureTime;
}

Transport* TransportWay::getTransport() {
    return transport; 
}

void TransportWay::displayInfo() {
    cout << "Transport: " << transport->getType() << endl; 
    cout << "Start Point: " << startPoint << endl;
    cout << "End Point: " << endPoint << endl;
    cout << "Departure Time: " << departureTime << endl;
}