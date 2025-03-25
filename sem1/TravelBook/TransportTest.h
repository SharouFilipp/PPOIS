#include "Transport.h"

TEST(TransportTest, Constructor) {
    Transport transport("Car", 20000);
    EXPECT_EQ(transport.getType(), "Car");
    EXPECT_EQ(transport.getPrice(), 20000);
}

TEST(TransportTest, UpdateType) {
    Transport transport("Car", 20000);
    transport.updateType("Bike");
    EXPECT_EQ(transport.getType(), "Bike");
}

TEST(TransportTest, GetPrice) {
    Transport transport("Bus", 15000);
    EXPECT_EQ(transport.getPrice(), 15000);
}

TEST(TransportTest, TypeChangeDoesNotAffectPrice) {
    Transport transport("Train", 30000);
    transport.updateType("Boat");
    EXPECT_EQ(transport.getPrice(), 30000);
}