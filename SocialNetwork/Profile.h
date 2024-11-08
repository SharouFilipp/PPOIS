#pragma once
#include <iostream>
#include <string>
using namespace std;

class Profile
{
private:
    string bio;
    string photo;
    string location;
    string birthday;
    string premiumSettings;

public:
    Profile(string bio, string photo, string location, string birthday, string premiumSettings);
    void updateBio(string newBio);
    void updatePhoto(string newPhoto);

    string getBio();
    string getPhoto();
    string getLocation();
    string getBirthday();
    string getPremiumSettings();
};

