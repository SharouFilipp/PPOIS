#include "Hotel.h"
#include "Review.h"
#include "User.h"


TEST(ReviewTest, Constructor) {
    User user(1, "John Doe", "john@example.com", "password123");
    Hotel hotel("Test Hotel", "Test Location", 4.5);
    Review review(&user, &hotel, 5, "Great stay!");

    EXPECT_EQ(review.getRating(), 5);
    EXPECT_EQ(review.getComment(), "Great stay!");
    EXPECT_EQ(review.getUser()->getName(), "John Doe");
    EXPECT_EQ(review.getHotel()->getName(), "Test Hotel");
}

TEST(ReviewTest, SetComment) {
    User user(2, "Jane Doe", "jane@example.com", "password456");
    Hotel hotel("Another Hotel", "Another Location", 4.0);
    Review review(&user, &hotel, 4, "Good service.");

    review.setComment("Excellent service!");
    EXPECT_EQ(review.getComment(), "Excellent service!");
}