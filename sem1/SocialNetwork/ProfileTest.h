#pragma once

#include <gtest/gtest.h>
#include "Profile.h"

TEST(TestProfile, TestProfileCreation) {
    Profile profile("Hello!", "photo.jpg", "New York", "1990-01-01", "premium");
    
    EXPECT_EQ(profile.getBio(), "Hello!");
    EXPECT_EQ(profile.getPhoto(), "photo.jpg");
    EXPECT_EQ(profile.getLocation(), "New York");
    EXPECT_EQ(profile.getBirthday(), "1990-01-01");
    EXPECT_EQ(profile.getPremiumSettings(), "premium");
}

TEST(TestProfile, TestUpdateBio) {
    Profile profile("Hello!", "photo.jpg", "New York", "1990-01-01", "premium");
    
    profile.updateBio("New bio");
    
    EXPECT_EQ(profile.getBio(), "New bio");
}

TEST(TestProfile, TestUpdatePhoto) {
    Profile profile("Hello!", "photo.jpg", "New York", "1990-01-01", "premium");
    
    profile.updatePhoto("new_photo.jpg");
    
    EXPECT_EQ(profile.getPhoto(), "new_photo.jpg");
}