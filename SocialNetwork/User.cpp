#include "User.h"

User::User(int userId,string dateRegistation, string email, string username, Profile& profile):profile(profile) 
{
    this->userId = userId;
    this->dateRegistation = dateRegistation;
    this->email = email;
    this->username = username;
    this->password = ""; 
}

bool User::CheckPassword(string password) {
    return this->password == password;
}

void User::ChangePassword(string newPassword, string oldPassword) {
    if (CheckPassword(oldPassword)) {
        password = newPassword; 
    } 
    else {
        cout << "Старый пароль неверен." << endl;
    }
}

Profile& User::getProfile() {
    return profile;
}

int User::getUserId() {
    return userId;
}
string User::getEmail() {
    return email;
}
string User::getUsername() {
    return username;
}
