#pragma once
#include <string>
using namespace std;

class Comment
{
private:
    int commentId;
    string content;
    string timePost;
    int authorId;
public:
    Comment(int commentId, string content,int authorId);

    void ChangeComment(string newContent);
    void DeleteComment();
    int getId();
    string getContent();
    string getTimePost();
};