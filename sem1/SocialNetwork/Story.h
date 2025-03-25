#pragma once

#include <string>
#include <ctime>
using namespace std;

class Story {
private:
    int storyId;
    int userId;
    string content;
    int timePost;

public:
    Story(int id, int userId, string content);
    bool isExpired() const;
    void displayStory() const;
    int getStoryId();
    int getUserId();
    string getContent();
};