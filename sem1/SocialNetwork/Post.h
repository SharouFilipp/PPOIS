#pragma once
#include <string>
#include <vector>
#include "Comment.h"
#include "Like.h"
using namespace std;

class Post {
private:
    int postId;
    string content;
    string timePost;
    int likeCount;
    vector<Comment> comments;
    vector<Like> likes;

public:
    Post(int postId, string content);
    
    void addComment(const Comment& comment);
    void removeComment(int commentId);
    void addLike(const Like& like);
    void removeLike(int likeId);
    
    int getLikeCount();
    void displayPost();

    int getPostId();
    string getContent();
    vector<Comment> getComments();
};