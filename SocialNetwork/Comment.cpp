#include "Comment.h"
#include <ctime>

Comment::Comment(int commentId, string content, int authorId)
{
    this->authorId=authorId;
    this->content=content;
    this->commentId=commentId;
    time_t now = time(0);
    timePost = ctime(&now);
}

void Comment::ChangeComment(string newContent) {
    content = newContent;
}

void Comment::DeleteComment() {
    content.clear();
}
int Comment::getId(){
    return commentId;
}
string Comment::getContent(){
    return content;
}
string Comment::getTimePost(){
    return timePost;
}