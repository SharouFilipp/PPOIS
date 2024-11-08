#pragma once
#include <string>
#include <ctime>
using namespace std;

class Friendship {
private:
    int userId1;
    int userId2;
    string status; 
    time_t startDate;

public:
    Friendship(int userId1, int userId2, string status);
    
    void acceptFriendRequest();
    void blockFriend();
    void displayFriendship();
    int getUserId1();
    int getUserId2();
    string getStatus();
};