#include "Booking.h"
#include "Hotel.h"
#include "User.h"


TEST(BookingTest, CreateBooking) {
    Hotel hotel("Test Hotel", "Location", 4.5);
    User user(1, "Alice", "alice@example.com", "password");
    Booking booking(&hotel, &user, "2024-11-01", "2024-11-10");

    EXPECT_EQ(booking.getCheckInDate(), "2024-11-01"); 
    EXPECT_EQ(booking.getHotel(), &hotel); 
    EXPECT_EQ(booking.getTotalPrice(), 0.0);

TEST(BookingTest, SetTotalPrice) {
    Hotel hotel("Test Hotel", "Location", 4.5);
    User user(1, "Alice", "alice@example.com", "password");
    Booking booking(&hotel, &user, "2024-11-01", "2024-11-10");

    booking.setTotalPrice(500.0);
    EXPECT_EQ(booking.getTotalPrice(), 500.0);
}

TEST(BookingTest, ValidBooking) {
    Hotel hotel("Test Hotel", "Location", 4.5);
    User user(1, "Alice", "alice@example.com", "password");
    Booking booking(&hotel, &user, "2024-11-01", "2024-11-10");

    EXPECT_TRUE(booking.isValidBooking()); 
}

TEST(BookingTest, InvalidBooking) {
    Hotel hotel("Test Hotel", "Location", 4.5);
    User user(1, "Alice", "alice@example.com", "password");
    Booking booking(&hotel, &user, "2024-11-10", "2024-11-01");

    EXPECT_FALSE(booking.isValidBooking());
}
