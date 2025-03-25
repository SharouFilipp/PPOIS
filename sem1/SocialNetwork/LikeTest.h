#pragma once

#include <gtest/gtest.h>
#include "Like.h"

TEST(TestLike, TestCreation) {
    Like like(1, 100, 200);
    
    EXPECT_EQ(like.getLikeId(), 1);
    EXPECT_FALSE(like.getLike()); 
}

TEST(TestLike, TestSetLike) {
    Like like(1, 100, 200);
    
    like.setLike(true);
    
    EXPECT_TRUE(like.getLike());
}

TEST(TestLike, TestGetTime) {
    Like like(1, 100, 200);
    
    string time = like.getTime();
    
    EXPECT_FALSE(time.empty()); 
}