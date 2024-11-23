#include "Admin.h"

void Admin::addUser(User* user) {
    users.push_back(user);
}

void Admin::removeUser(int index) {
    if (index >= 0 && index < users.size()) {
        delete users[index];
        users.erase(users.begin() + index);
        cout << "User removed at index " << index << ".\n";
    } else {
        cout << "Invalid index. Unable to remove user.\n";
    }
}

User* Admin::findUserByName( string name) {
    for (User* user : users) {
        if (user->getName() == name) { 
            return user;
        }
    }
    return nullptr;
}

int Admin::getUserCount()  {
    return users.size();
}

void Admin::clearUsers() {
    for (User* user : users) {
        delete user;
    }
    users.clear();
}