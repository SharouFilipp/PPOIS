#include "Hotel.h"
#include "Review.h"
#include "User.h" 
const int TEST_USER_ID = 1;
const std::string TEST_PASSWORD = "password123";

TEST(HotelTest, AddReview) {
    Hotel hotel("Test Hotel", "Test Location", 4.5);
    User user(TEST_USER_ID, "John Doe", "john@example.com", TEST_PASSWORD); 
    Review* review = new Review(&user, &hotel, 5, "Excellent stay!"); 
    hotel.addReview(review);
    EXPECT_EQ(hotel.getAverageRating(), 5.0);
}

TEST(HotelTest, RemoveReview) {
    Hotel hotel("Test Hotel", "Test Location", 4.5);
    User user1(TEST_USER_ID, "John Doe", "john@example.com", TEST_PASSWORD);
    User user2(TEST_USER_ID + 1, "Jane Doe", "jane@example.com", TEST_PASSWORD);

    Review* review1 = new Review(&user1, &hotel, 5, "Excellent stay!");
    Review* review2 = new Review(&user2, &hotel, 4, "Very good!");

    hotel.addReview(review1);
    hotel.addReview(review2);

    hotel.removeReview(0);
    EXPECT_EQ(hotel.getAverageRating(), 4.0);
}

TEST(HotelTest, RemoveReviewInvalidIndex) {
    Hotel hotel("Test Hotel", "Test Location", 4.5);
    User user(TEST_USER_ID, "John Doe", "john@example.com", TEST_PASSWORD);
    Review* review = new Review(&user, &hotel, 5, "Excellent stay!");
    hotel.addReview(review);
    hotel.removeReview(1); 

    EXPECT_EQ(hotel.getAverageRating(), 5.0);
}

TEST(HotelTest, GetAverageRatingNoReviews) {
    Hotel hotel("Test Hotel", "Test Location", 4.5);
    EXPECT_EQ(hotel.getAverageRating(), 0.0);
}