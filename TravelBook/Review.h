#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "Hotel.h"
using namespace std;

class Hotel;

class Review {
private:                         
    User* user;             
    Hotel* hotel;                
    int rating;                  
    string comment;  
public:
    Review(User* user, Hotel* hotel, int rating, string comment);
    int getRating();
    string getComment();
    User* getUser();
    Hotel* getHotel() ;
    void setComment(string newComment);    
};