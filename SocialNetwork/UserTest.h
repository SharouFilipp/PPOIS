#include <gtest/gtest.h>
#include "User.h"
#include "Profile.h" 

TEST(TestUser, TestUserCreation) {
    Profile profile("This is a bio", "photo.jpg", "New York", "1990-01-01", "premium");
    User user(1, "2023-11-08", "test@example.com", "testuser", profile);
    
    EXPECT_EQ(user.getUserId(), 1);
    EXPECT_EQ(user.getEmail(), "test@example.com");
    EXPECT_EQ(user.getUsername(), "testuser");
}

TEST(TestUser, TestPasswordChange) {
    Profile profile("This is a bio", "photo.jpg", "New York", "1990-01-01", "premium");
    User user(1, "2023-11-08", "test@example.com", "testuser", profile);
    
    user.ChangePassword("newpassword", ""); 
    EXPECT_TRUE(user.CheckPassword("newpassword")); 

    user.ChangePassword("newpassword2", "newpassword"); 
    EXPECT_TRUE(user.CheckPassword("newpassword2")); 
}


TEST(TestUser, TestWrongOldPassword) {
    Profile profile("This is a bio", "photo.jpg", "New York", "1990-01-01", "premium");
    User user(1, "2023-11-08", "test@example.com", "testuser", profile);
    
    user.ChangePassword("newpassword", "wrongpassword"); 
    EXPECT_FALSE(user.CheckPassword("newpassword"));
}
TEST(TestUser, TestGetProfile) {
    Profile profile("This is a bio", "photo.jpg", "New York", "1990-01-01", "premium");
    User user(1, "2023-01-01", "john@example.com", "johndoe", profile);
    
    Profile& returnedProfile = user.getProfile();
    EXPECT_EQ(returnedProfile.getBio(), "This is a bio");
}