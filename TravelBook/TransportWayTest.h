#include "Transport.h"
#include "TransportWay.h"

TEST(TransportWayTest, Constructor) {
    Transport transport("Car", 20000);
    TransportWay way(&transport, "Point A", "Point B", "10:00 AM");

    EXPECT_EQ(way.getStartPoint(), "Point A");
    EXPECT_EQ(way.getEndPoint(), "Point B");
    EXPECT_EQ(way.getTransport()->getType(), "Car");
    EXPECT_EQ(way.getTransport()->getPrice(), 20000);
    EXPECT_EQ(way.getDepartureTime(), "10:00 AM");
}

TEST(TransportWayTest, UpdateDepartureTime) {
    Transport transport("Bus", 15000);
    TransportWay way(&transport, "Point A", "Point B", "10:00 AM");

    way.updateDepartureTime("11:00 AM");
    EXPECT_EQ(way.getDepartureTime(), "11:00 AM");
}

TEST(TransportWayTest, DisplayInfo) {
    Transport transport("Train", 30000);
    TransportWay way(&transport, "Point A", "Point B", "12:00 PM");


    testing::internal::CaptureStdout();
    way.displayInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Transport: Train"), std::string::npos);
    EXPECT_NE(output.find("Start Point: Point A"), std::string::npos);
    EXPECT_NE(output.find("End Point: Point B"), std::string::npos);
    EXPECT_NE(output.find("Departure Time: 12:00 PM"), std::string::npos);
}