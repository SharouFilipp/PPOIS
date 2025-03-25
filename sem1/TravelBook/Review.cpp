#include "Review.h"

Review::Review(User* user, Hotel* hotel, int rating, string comment)
    : user(user), hotel(hotel), rating(rating), comment(comment) {}

int Review::getRating() {
    return rating;
}

string Review::getComment()  {
    return comment;
}

User* Review::getUser()  {
    return user;
}

Hotel* Review::getHotel()  {
    return hotel;
}

void Review::setComment(string newComment) {
    comment = newComment;
}