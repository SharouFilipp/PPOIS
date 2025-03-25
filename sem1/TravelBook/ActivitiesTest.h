#include "Activities.h"

TEST(ActivitiesTest, Constructor) {
    Activities activity("Hiking", "Outdoor adventure", "Mountain Trail", 50.0);

    EXPECT_EQ(activity.getLocation(), "Mountain Trail");
    EXPECT_EQ(activity.getPrice(), 50.0);
}

TEST(ActivitiesTest, SetPrice) {
    Activities activity("Cooking Class", "Learn to cook", "Culinary School", 100.0);

    activity.setPrice(120.0);
    EXPECT_EQ(activity.getPrice(), 120.0);
}

TEST(ActivitiesTest, SetDescription) {
    Activities activity("Yoga Session", "Relaxing yoga", "City Park", 30.0);

    activity.setDescription("Advanced yoga session");
    EXPECT_EQ(activity.getDescription(), "Advanced yoga session");
}