#include "ReviewList.h"

void ReviewList::addReview(Review* review) {
    reviews.push_back(review);
}

void ReviewList::findReviewsByHotel(Hotel* hotel)  {
    cout << "Reviews for hotel: " << hotel->getName() << endl; 
    bool found = false;
    for (const auto& review : reviews) {
        if (review->getHotel() == hotel) { 
            cout << "Rating: " << review->getRating() << ", Comment: " << review->getComment() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No reviews found for this hotel." << endl;
    }
}

void ReviewList::removeReview(int index) {
    if (index >= 0 && index < reviews.size()) {
        delete reviews[index];
        reviews.erase(reviews.begin() + index);
        cout << "Review removed at index " << index << "." << endl;
    } else {
        cout << "Invalid index. Unable to remove review." << endl;
    }
}

void ReviewList::clearReviews() {
    for (auto review : reviews) {
        delete review; 
    }
    reviews.clear();
    cout << "All reviews have been cleared." << endl;
}

size_t ReviewList::getCount()  {
    return reviews.size();
}