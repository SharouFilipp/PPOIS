#pragma once
#include <string>
using namespace std;

class Like
{
private:
    int userId;
    int likeId;
    string timeCreate;
    int postId;
    bool like;
public:
    Like(int likeId,int userId, int postId);
    Like(int likeId,int userId);
    bool getLike();
    string getTime();
    void setLike(bool likeStatus);
    int getLikeId();
};