#include "Feed.h"
#include <iostream>
Feed::Feed(int userId){
    this->userId=userId;
}

void Feed::refreshFeed() {
    cout << "Feed Update";
}

void Feed::applyFilter(string filter) {
    filters = filter;
}
int Feed::getUserId(){
    return userId;
}
string Feed::getFilters(){
    return filters;
}