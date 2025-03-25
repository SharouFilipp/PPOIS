#include "Hotel.h"
Hotel::Hotel(string name,  string location, double rating)
    : name(name), location(location), rating(rating) {}

void Hotel::addReview(Review* review) {
    reviews.push_back(review);
}

void Hotel::removeReview(int index) {
    if (index >= 0 && index < reviews.size()) {
        delete reviews[index]; 
        reviews.erase(reviews.begin() + index);
        cout << "Review removed" << index << ".\n";
    } else {
        cout << "Invalid index.\n";
    }
}

double Hotel::getAverageRating()  {
    if (reviews.empty()) return 0.0;

    double totalRating = 0.0;
    for (const auto& review : reviews) {
        totalRating += review->getRating(); 
    }
    return totalRating / reviews.size();
}
/*
void Hotel::displayInfo()  {
    cout << "Hotel Name: " << name << "\n";
    cout << "Location: " << location << "\n";
    cout << "Rating: " << rating << "\n";
    cout << "Average Review Rating: " << getAverageRating() << "\n";
}
*/
string Hotel::getName() {
    return name;
}