#pragma once

#include <gtest/gtest.h>
#include "Feed.h"

TEST(TestFeed, TestCreation) {
    Feed feed(1);
    EXPECT_EQ(feed.getUserId(), 1);
    EXPECT_EQ(feed.getFilters(), "");
}

TEST(TestFeed, TestRefreshFeed) {
    Feed feed(1);
    feed.refreshFeed();
}

TEST(TestFeed, TestApplyFilter) {
    Feed feed(1);
    feed.applyFilter("New Filter");
    EXPECT_EQ(feed.getFilters(), "New Filter");
}