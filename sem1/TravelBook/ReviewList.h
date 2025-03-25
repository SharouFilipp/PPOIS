#pragma once
#include <iostream>
#include <vector>
#include "Review.h"
using namespace std;

class ReviewList {
private:
    vector<Review*> reviews;
public:
    void addReview(Review* review);
    void findReviewsByHotel(Hotel* hotel);
    void removeReview(int index);
    void clearReviews();
    size_t getCount();
};
