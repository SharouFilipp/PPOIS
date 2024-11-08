#pragma once

#include <gtest/gtest.h>
#include "NotificationMessage.h"

TEST(TestNotificationMessage, TestCreation) {
    NotificationMessage notification(1, 100, "This is a notification.");
    
    EXPECT_EQ(notification.getNotificationId(), 1);
    EXPECT_EQ(notification.getContent(), "This is a notification.");
    EXPECT_EQ(notification.getType(), "Notification");
}