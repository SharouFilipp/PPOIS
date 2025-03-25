#include "User.h"
User::User(int id, string name, string email, string password) 
        : id(id), name(name), email(email), password(password) {}

void User::changePassword(string newPassword) {
    password = newPassword;
}

bool User::authenticate(string inputPassword) {
    return password == inputPassword;
}

string User::getPassword() {
    return password;
}
string User::getName() {
    return name;
}