#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "UserTest.h"
#include "TransportWayTest.h"
#include "TransportTest.h"
#include "SupportTest.h"
#include "ServiceTest.h"
#include "ActivitiesTest.h"
#include "MediaTest.h"
#include "ChildTest.h"
#include "ReviewTest.h"
#include "RoomTypeTest.h"
#include "HotelTest.h"
#include "ReviewListTest.h"
#include "AdminTest.h"
#include "BookingTest.h"
#include "ExtendBookingTest.h"


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}
