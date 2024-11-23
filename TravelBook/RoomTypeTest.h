#include "RoomType.h"
#include "Media.h"


TEST(RoomTypeTest, Constructor) {
    RoomType roomType("Deluxe Room", "Spacious room with sea view", 150.0, 2);

    EXPECT_EQ(roomType.getPrice(), 150.0);
    EXPECT_EQ(roomType.getCapacity(), 2);
}

TEST(RoomTypeTest, AddMedia) {
    RoomType roomType("Standard Room", "Comfortable room", 100.0, 2);
    Media* media = new Media("http://example.com/image.jpg", "image");

    roomType.addMedia(media);
    EXPECT_TRUE(roomType.hasMedia()); 
}

TEST(RoomTypeTest, RemoveMedia) {
    RoomType roomType("Suite", "Luxurious suite", 250.0, 4);
     Media* media = new Media("http://example.com/video.mp4", "video");

    roomType.addMedia(media);
    EXPECT_EQ(roomType.hasMedia(), true); 

    roomType.removeMedia(0);
    EXPECT_FALSE(roomType.hasMedia()); 
}

TEST(RoomTypeTest, RemoveMediaInvalidIndex) {
    RoomType roomType("Economy Room", "Budget-friendly room", 80.0, 1);
     Media* media = new Media("http://example.com/image2.jpg", "image");

    roomType.addMedia(media);
    roomType.removeMedia(1); 

    EXPECT_EQ(roomType.hasMedia(), true); 
}

TEST(RoomTypeTest, SetPrice) {
    RoomType roomType("Family Room", "Room for families", 120.0, 4);
    roomType.setPrice(140.0);

    EXPECT_EQ(roomType.getPrice(), 140.0); 
}