#pragma once 
#include <iostream>
#include <string>
using namespace std;

class Media{
private:
    string url;
    string type;
public:
    Media(string url,string type);
    void upddateUrl(string newUrl);
    string getUrl();
    string getType();
};