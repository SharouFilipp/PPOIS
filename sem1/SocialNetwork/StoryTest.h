#pragma once
#include <gtest/gtest.h>
#include "Story.h"

TEST(TestStory, TestStoryCreation) {
    Story story(1, 1, "This is a test story.");
    EXPECT_EQ(story.getStoryId(), 1);
    EXPECT_EQ(story.getUserId(), 1);
    EXPECT_EQ(story.getContent(), "This is a test story.");
}

TEST(TestStory, TestStoryExpiration) {
    Story story(1, 1, "This is a test story.");
    sleep(2);
    EXPECT_FALSE(story.isExpired()); 
}

TEST(TestStory, TestDisplayStory) {
    Story story(1, 1, "This is a test story.");
    EXPECT_NO_THROW(story.displayStory());
}