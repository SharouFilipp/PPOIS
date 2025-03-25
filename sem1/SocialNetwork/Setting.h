#pragma once
#include <string>
using namespace std;

class Setting {
public:
    Setting(int userId);
    
    void updateSettings(const Setting& settings);
    int getUserId();
    string getVisibility();
    string getFriendRequests();  
    string getTagging();
    void setVisibility(string newVisibility);
    void setFriendRequests(string newFriendRequests);  
    void setTagging(string newTagging); 
protected:
    int userId;        
    string visibility;
    string friendRequests; 
    string tagging;
};
