#include "Setting.h" 


Setting::Setting(int userId)
{
    this->userId = userId;
    this->visibility = "public";
    this->friendRequests = "everyone";
    this->tagging = "enabled";
}


void Setting::updateSettings(const Setting& settings) {
    this->visibility = settings.visibility;
    this->friendRequests = settings.friendRequests; 
    this->tagging = settings.tagging;
}

int Setting::getUserId() {return userId;}
string Setting::getVisibility(){return visibility;}
string Setting::getFriendRequests(){return friendRequests;} 
string Setting::getTagging(){return tagging;}
void Setting::setVisibility(string newVisibility){ visibility = newVisibility;}
void Setting::setFriendRequests(string newFriendRequests){friendRequests = newFriendRequests;}
void Setting::setTagging(string newTagging){tagging = newTagging;}