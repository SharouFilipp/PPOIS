#include "ReviewList.h"
#include "Review.h"
#include "Hotel.h"
#include "User.h"


TEST(ReviewListTest, AddReview) {
    ReviewList reviewList;
    User user(1, "Alice", "alice@example.com", "password");
    Hotel hotel("Test Hotel", "Location", 4.5);
    Review* review = new Review(&user, &hotel, 5, "Excellent stay!");

    reviewList.addReview(review);
    EXPECT_EQ(reviewList.getCount(), 1);
}

TEST(ReviewListTest, FindReviewsByHotel) {
    ReviewList reviewList;
    User user(1, "Alice", "alice@example.com", "password");
    Hotel hotel1("Test Hotel", "Location", 4.5);
    Hotel hotel2("Another Hotel", "Location", 3.5);
    
    reviewList.addReview(new Review(&user, &hotel1, 5, "Excellent stay at Test Hotel!"));
    reviewList.addReview(new Review(&user, &hotel2, 4, "Good experience at Another Hotel."));

    testing::internal::CaptureStdout(); 
    reviewList.findReviewsByHotel(&hotel1);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Excellent stay at Test Hotel!"), std::string::npos); // Проверяем, что отзыв найден
}

TEST(ReviewListTest, RemoveReview) {
    ReviewList reviewList;
    User user(1, "Alice", "alice@example.com", "password");
    Hotel hotel("Test Hotel", "Location", 4.5);
    Review* review = new Review(&user, &hotel, 5, "Excellent stay!");

    reviewList.addReview(review);
    EXPECT_EQ(reviewList.getCount(), 1); 

    reviewList.removeReview(0);
    EXPECT_EQ(reviewList.getCount(), 0); 
}

TEST(ReviewListTest, RemoveReviewInvalidIndex) {
    ReviewList reviewList;
    User user(1, "Alice", "alice@example.com", "password");
    Hotel hotel("Test Hotel", "Location", 4.5);
    Review* review = new Review(&user, &hotel, 5, "Excellent stay!");

    reviewList.addReview(review);
    reviewList.removeReview(1); 

    EXPECT_EQ(reviewList.getCount(), 1); 
}

TEST(ReviewListTest, ClearReviews) {
    ReviewList reviewList;
    User user(1, "Alice", "alice@example.com", "password");
    Hotel hotel("Test Hotel", "Location", 4.5);

    reviewList.addReview(new Review(&user, &hotel, 5, "Excellent stay!"));
    reviewList.addReview(new Review(&user, &hotel, 4, "Good experience!"));

    reviewList.clearReviews();
    EXPECT_EQ(reviewList.getCount(), 0); 
}

