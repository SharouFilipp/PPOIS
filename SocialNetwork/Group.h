#pragma once
#include <string>
#include <vector>
#include "User.h"
using namespace std;

class Group {
public:
    Group(int groupId, string nameGroup);
    
    void addMember(User* user);
    void removeMember(User* user);
    int countMember();
    
private:
    int groupId;       
    string nameGroup;
    string description;
    int membersCount;
    int adminId;
    vector<User*> members; 
};