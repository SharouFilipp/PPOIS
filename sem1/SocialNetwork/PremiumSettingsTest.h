#pragma once

#include <gtest/gtest.h>
#include "PremiumSetting.h"

TEST(TestPremiumSetting, TestCreation) {
    PremiumSetting premiumSetting("Gold");
    
    EXPECT_EQ(premiumSetting.getLevel(), "Gold");
}

TEST(TestPremiumSetting, TestSetLevel) {
    PremiumSetting premiumSetting("Gold");
    
    premiumSetting.setLevel("Platinum");
    
    EXPECT_EQ(premiumSetting.getLevel(), "Platinum");
}

TEST(TestPremiumSetting, TestSetLevelToSame) {
    PremiumSetting premiumSetting("Gold");
    
    premiumSetting.setLevel("Gold");
    
    EXPECT_EQ(premiumSetting.getLevel(), "Gold");
}