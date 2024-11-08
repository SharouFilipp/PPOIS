#include "Friendship.h"
#include <iostream>
Friendship::Friendship(int userId1, int userId2, string status)
{
    this->userId1=userId1;
    this->userId2=userId2;
    this->status=status;
    startDate = time(0);
}

void Friendship::acceptFriendRequest() {
    status = "Active";
}

void Friendship::blockFriend() {
    status = "Blocked";
}

void Friendship::displayFriendship() {
    cout << "Friendship between User " << userId1 << " and User " << userId2 
         << "\nStatus: " << status 
         << "\nSince: " << ctime(&startDate);
}
int Friendship::getUserId1(){
    return userId1;
}
int Friendship::getUserId2(){
    return userId2;
}
string Friendship::getStatus(){
    return status;
}