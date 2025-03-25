#include "Service.h"

TEST(ServiceTest, Constructor) {
    Service service("Web Development", 150.0, "Building and maintaining websites.");

    EXPECT_EQ(service.getName(), "Web Development");
    EXPECT_EQ(service.getPrice(), 150.0);
    EXPECT_EQ(service.getDescription(), "Building and maintaining websites.");
}

TEST(ServiceTest, UpdatePrice) {
    Service service("Graphic Design", 100.0, "Creating visual content.");

    service.updatePrice(120.0);
    EXPECT_EQ(service.getPrice(), 120.0);
}

TEST(ServiceTest, GetDescription) {
    Service service("Consulting", 200.0, "Providing expert advice.");

    EXPECT_EQ(service.getDescription(), "Providing expert advice.");
}