#pragma once

#include <gtest/gtest.h>
#include "Group.h"
#include "User.h"
#include "Profile.h" 

TEST(TestGroup, TestAddMember) {
    Group group(1, "Test Group");
    Profile profile("This is a bio", "photo.jpg", "New York", "1990-01-01", "premium");
    User user1(1, "2023-10-01", "alice@example.com", "Alice", profile);
    User user2(2, "2023-10-01", "bob@example.com", "Bob", profile);
    
    group.addMember(&user1);
    group.addMember(&user2);
    
    EXPECT_EQ(group.countMember(), 2); 
}

TEST(TestGroup, TestRemoveMember) {
    Group group(1, "Test Group");
    Profile profile("This is a bio", "photo.jpg", "New York", "1990-01-01", "premium");
    User user1(1, "2023-10-01", "alice@example.com", "Alice", profile);
    
    group.addMember(&user1);
    EXPECT_EQ(group.countMember(), 1); 
    
    group.removeMember(&user1);
    EXPECT_EQ(group.countMember(), 0); 
}

TEST(TestGroup, TestRemoveNonExistentMember) {
    Group group(1, "Test Group");
    Profile profile("This is a bio", "photo.jpg", "New York", "1990-01-01", "premium");
    User user1(1, "2023-10-01", "alice@example.com", "Alice", profile);
    User user2(2, "2023-10-01", "bob@example.com", "Bob", profile);
    
    group.addMember(&user1);
    group.removeMember(&user2); 
    EXPECT_EQ(group.countMember(), 1); 
}