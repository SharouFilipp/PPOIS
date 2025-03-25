#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "Media.h"
using namespace std;

class RoomType {
private:
    string name;            
    string description;
    double price;
    int capacity;
    vector<Media*> media;
public:
    RoomType(string name, string description, double price, int capacity);
    void addMedia(Media* media);
    double getPrice();
    void setPrice(double newPrice);
    int getCapacity();
    void removeMedia(int index);
    bool hasMedia();
};