#include "Profile.h" 

Profile::Profile(string bio, string photo, string location, string birthday, string premiumSettings)
{
    this->bio = bio;
    this->photo = photo;
    this->location = location;
    this->birthday = birthday;   
    this->premiumSettings=premiumSettings;
}

void Profile::updateBio(string newBio) {
    bio = newBio; 
}


void Profile::updatePhoto(string newPhoto) {
    photo = newPhoto;
}

string Profile::getBio(){return bio;}
string Profile::getPhoto(){return photo;}
string Profile::getLocation(){return location;}
string Profile::getBirthday(){return birthday;}
string Profile::getPremiumSettings(){return premiumSettings;}