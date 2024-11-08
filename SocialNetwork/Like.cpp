#include "Like.h"
#include <ctime>

Like::Like(int likeId, int userId, int postId)
    : likeId(likeId), userId(userId), postId(postId), like(false) {
    time_t now = time(0);
    timeCreate = ctime(&now); 
}

Like::Like(int likeId, int userId)
    : likeId(likeId), userId(userId), like(false) {
    time_t now = time(0);
    timeCreate = ctime(&now); 
}

void Like::setLike(bool likeStatus) {
    like = likeStatus;
}

bool Like::getLike()  {
    return like;
}

string Like::getTime()  {
    return timeCreate;
}
int Like::getLikeId() {
    return likeId;
}