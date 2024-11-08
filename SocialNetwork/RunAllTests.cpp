#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "UserTest.h"
#include "StoryTest.h"
#include "SettingTest.h"
#include "ReportTest.h"
#include "ProfileTest.h"
#include "PremiumSettingsTest.h"
#include "PostTest.h"
#include "PhotoTest.h"
#include "NotificationMessageTest.h"
#include "MessageTest.h"
#include "LikeTest.h"
#include "GroupTest.h"
#include "FriendshipTest.h"
#include "FeedTest.h"
#include "CommentTest.h"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}
