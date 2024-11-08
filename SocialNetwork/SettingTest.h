#pragma once

#include <gtest/gtest.h>
#include "Setting.h"

TEST(TestSetting, TestSettingCreation) {
    Setting setting(1);
    
    EXPECT_EQ(setting.getUserId(), 1);
    EXPECT_EQ(setting.getVisibility(), "public");
    EXPECT_EQ(setting.getFriendRequests(), "everyone");
    EXPECT_EQ(setting.getTagging(), "enabled");
}

TEST(TestSetting, TestUpdateSettings) {
    Setting setting(1);
    Setting newSettings(2);
    newSettings.setVisibility("private");
    newSettings.setFriendRequests("friends");
    newSettings.setTagging("disabled");

    setting.updateSettings(newSettings);
    
    EXPECT_EQ(setting.getVisibility(), "private");
    EXPECT_EQ(setting.getFriendRequests(), "friends");
    EXPECT_EQ(setting.getTagging(), "disabled");
}