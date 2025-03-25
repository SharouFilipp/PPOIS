#include "Group.h"
#include <algorithm>

Group::Group(int groupId, string nameGroup)
{ 
    this->groupId = groupId;
    this->nameGroup = nameGroup;
    this->adminId = -1;
    description = "";
}

void Group::addMember(User* user) {
    if (user != nullptr) {
        members.push_back(user);
    }
}

void Group::removeMember(User* user) {
    auto it = find(members.begin(), members.end(), user);
    if (it != members.end()) {
        members.erase(it);
    }
}


int Group::countMember() {
    return members.size(); 
}