#pragma once
#include <iostream>
#include <string>
using namespace std;
class Child{
private:
    string name; 
    int age; 

public:
    Child(string name, int age);
    void updateAge(int newAge);
    string getName();
    int getAge(); 
    bool checkAge();
};