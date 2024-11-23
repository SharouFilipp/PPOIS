#include "Child.h"


Child::Child(string name, int age) 
        : name(name), age(age) {}

bool Child::checkAge() {
    return age < 18;
}
void Child::updateAge(int newAge){
    age = newAge;
}
string Child::getName(){
    return name;
}
int Child::getAge(){
    return age;
}