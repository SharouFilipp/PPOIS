#pragma once
#include <iostream>
#include <vector>
#include "User.h"
using namespace std; 

class Admin{
private:
    vector<User*> users;
public:
    void addUser(User* user);
    void removeUser(int index);
    User* findUserByName(string name);
    int getUserCount();
    void clearUsers();
};
