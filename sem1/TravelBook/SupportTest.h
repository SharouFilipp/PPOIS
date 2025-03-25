#include "Support.h"

TEST(SupportTest, Constructor) {
    Support support("support@example.com", "123-456-7890", "09:00 - 17:30", "123 Main St");

    EXPECT_EQ(support.getAdress(), "123 Main St");
}

TEST(SupportTest, IsAvailableDuringWorkingHours) {
    Support support("support@example.com", "123-456-7890", "09:00 - 17:30", "123 Main St");

    EXPECT_TRUE(support.isAvailable("10:00"));  
    EXPECT_TRUE(support.isAvailable("17:00"));  
    EXPECT_FALSE(support.isAvailable("08:30")); 
    EXPECT_FALSE(support.isAvailable("17:45")); 
}

TEST(SupportTest, UpdateAddress) {
    Support support("support@example.com", "123-456-7890", "09:00 - 17:30", "123 Main St");
    
    support.updateAddress("456 Elm St");
    EXPECT_EQ(support.getAdress(), "456 Elm St");
}