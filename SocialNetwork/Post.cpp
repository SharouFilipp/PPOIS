#include "Post.h"
#include <ctime>
#include <algorithm>
#include <iostream>

Post::Post(int postId, string content):likeCount(0) 
{
    this->postId = postId;
    this->content = content;
    time_t now = time(0);
    timePost = ctime(&now);
}

void Post::addComment(const Comment& comment) {
    comments.push_back(comment);
}

void Post::removeComment(int commentId) {
    auto it = remove_if(comments.begin(), comments.end(), 
                         [commentId]( Comment& c) { return c.getId() == commentId; });
    comments.erase(it, comments.end());
}

void Post::addLike(const Like& like) {
    likes.push_back(like);
    likeCount++;
}

void Post::removeLike(int likeId) {
    auto it = remove_if(likes.begin(), likes.end(), 
                        [likeId](Like& l) { return l.getLikeId() == likeId; });
    likes.erase(it, likes.end());
    likeCount--;
}

void Post::displayPost()  {
    cout << "Post ID: " << postId << "\nContent: " << content 
         << "\nLikes: " << likeCount << "\nComments: " << comments.size() 
         << "\nPosted on: " << timePost << endl;
}

int Post::getLikeCount()  {
    return likeCount;
}
int Post::getPostId()  {
    return postId;
}
string Post::getContent()  {
    return content;
}

vector<Comment> Post::getComments() {
    return comments;
}