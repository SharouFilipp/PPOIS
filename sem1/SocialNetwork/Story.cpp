#include "Story.h"
#include <iostream>

Story::Story(int storyId, int userId, string content)
{
    this->storyId = storyId;
    this->userId=userId;
    this->content=content;
    timePost = time(0);
}

bool Story::isExpired() const {
    time_t now = time(0);
    return difftime(now, timePost) > 86400;
}

void Story::displayStory() const {
    cout << "Story ID: " << storyId << "\nUser ID: " << userId 
         << "\nContent: " << content << endl;
}

int Story::getStoryId() {
    return storyId;
}
int Story::getUserId() {
    return userId;
}
string Story::getContent() {
    return content;
}
