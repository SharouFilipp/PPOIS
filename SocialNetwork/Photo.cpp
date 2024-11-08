#include "Photo.h" 
#include <iostream>
#include <ctime> 

Photo::Photo(int photoId, string url)
{
    this->photoId = photoId;
    this->url = url;
    time_t now = time(0);
    timeCreate = ctime(&now);
}

void Photo::setPhoto(string photoPath) {
    url = photoPath; 
}

void Photo::deletePhoto() {
    url.clear();
}
string Photo::getUrl(){
    return url;
}