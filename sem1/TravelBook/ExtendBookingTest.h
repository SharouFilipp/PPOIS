#include "ExtendBooking.h"
#include "Service.h"


TEST(ExtendBookingTest, AddService) {
    Hotel hotel("Test Hotel", "Location", 4.5);
    User user(1, "Alice", "alice@example.com", "password");
    ExtendBooking booking(&hotel, &user, "2024-11-01", "2024-11-10");
    
    Service* service = new Service("Spa", 100.0, "Relaxing spa treatment");

    booking.addService(service);
    EXPECT_EQ(booking.calculateTotalServiceCost(), 100.0); 
}

TEST(ExtendBookingTest, RemoveService) {
    Hotel hotel("Test Hotel", "Location", 4.5);
    User user(1, "Alice", "alice@example.com", "password");
    ExtendBooking booking(&hotel, &user, "2024-11-01", "2024-11-10");

    Service* service1 = new Service("Spa", 100.0, "Relaxing spa treatment");
    Service* service2 = new Service("Gym", 50.0, "Access to gym facilities");

    booking.addService(service1);
    booking.addService(service2);
    EXPECT_EQ(booking.calculateTotalServiceCost(), 150.0); 

    booking.removeService(0); 
    EXPECT_EQ(booking.calculateTotalServiceCost(), 50.0); 
}

TEST(ExtendBookingTest, RemoveServiceInvalidIndex) {
    Hotel hotel("Test Hotel", "Location", 4.5);
    User user(1, "Alice", "alice@example.com", "password");
    ExtendBooking booking(&hotel, &user, "2024-11-01", "2024-11-10");

    Service* service = new Service("Spa", 100.0, "Relaxing spa treatment");

    booking.addService(service);
    booking.removeService(1); 

    EXPECT_EQ(booking.calculateTotalServiceCost(), 100.0); 
}

TEST(ExtendBookingTest, CalculateTotalServiceCost) {
    Hotel hotel("Test Hotel", "Location", 4.5);
    User user(1, "Alice", "alice@example.com", "password");
    ExtendBooking booking(&hotel, &user, "2024-11-01", "2024-11-10");

    Service* service1 = new Service("Spa", 100.0, "Relaxing spa treatment");
    Service* service2 = new Service("Gym", 50.0, "Access to gym facilities");

    booking.addService(service1);
    booking.addService(service2);
    EXPECT_EQ(booking.calculateTotalServiceCost(), 150.0); 
}