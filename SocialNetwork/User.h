#pragma once
#include <string>
#include "Profile.h"

class User
{
private:
    int userId;
    string password;
    string dateRegistation;
    string email;
    string username;
    Profile profile;
public:
    User(int userId, string dateRegistation, string email, string username, Profile& profile);
    bool CheckPassword(string password);
    void ChangePassword(string newPassword, string oldPassword);
    Profile& getProfile();
    int getUserId();
    string getEmail();
    string getUsername();
};