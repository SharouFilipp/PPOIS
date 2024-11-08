#pragma once

#include <gtest/gtest.h>
#include "Friendship.h"

TEST(TestFriendship, TestCreation) {
    Friendship friendship(1, 2, "Pending");
    
    EXPECT_EQ(friendship.getUserId1(), 1);
    EXPECT_EQ(friendship.getUserId2(), 2);
    EXPECT_EQ(friendship.getStatus(), "Pending");
}

TEST(TestFriendship, TestAcceptFriendRequest) {
    Friendship friendship(1, 2, "Pending");
    friendship.acceptFriendRequest();
    
    EXPECT_EQ(friendship.getStatus(), "Active");
}

TEST(TestFriendship, TestDisplayFriendship) {
    Friendship friendship(1, 2, "Active");
    friendship.displayFriendship();
}
TEST(TestFriendship, TestBlockFriend) {
    Friendship friendship(1, 2, "Active");
    friendship.blockFriend();
    
    EXPECT_EQ(friendship.getStatus(), "Blocked");
}