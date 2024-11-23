#include "Media.h"
#include <string>

Media::Media(string url, string type) 
        : url(url), type(type) {}

void Media::upddateUrl(string newUrl){
    url = newUrl;
}
string Media::getUrl(){
    return url;
}
string Media::getType(){
    return type;
}
