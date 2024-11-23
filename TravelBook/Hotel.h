#pragma once
#include <iostream>
#include <vector>
#include "Media.h"
#include "Review.h"
using namespace std; 

class Hotel {
private:
    string name;                
    string location;           
    double rating;                   
    vector<Review*> reviews;
    vector<Media*> media;
public:
    Hotel(string name, string location, double rating);
    void addReview(Review* review);
    void removeReview(int index);
    double getAverageRating();
    string getName();
};
