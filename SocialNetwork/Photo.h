#pragma once
#include <string>
using namespace std;

class Photo {
public:
    Photo(int photoId, string url);
    
    void setPhoto(string photoPath);
    void deletePhoto();
    string getUrl();
private:
    int photoId;
    string url; 
    int uploaderId; 
    string timeCreate;
};