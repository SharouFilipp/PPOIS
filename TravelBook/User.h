#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int id;                          
    string name;                
    string email;               
    string password; 
public:
    User(int id, string name, string email, string password);
    void changePassword(string newPassword);
    bool authenticate(string inputPassword);
    string getPassword();
    string getName();
};