#include "Media.h"

TEST(MediaTest, Constructor) {
    Media media("http://example.com/video.mp4", "video");

    EXPECT_EQ(media.getUrl(), "http://example.com/video.mp4");
    EXPECT_EQ(media.getType(), "video");
}

TEST(MediaTest, UpddateUrl) {
    Media media("http://example.com/image.png", "image");

    media.upddateUrl("http://example.com/new_image.png");
    EXPECT_EQ(media.getUrl(), "http://example.com/new_image.png");
}

TEST(MediaTest, GetType) {
    Media media("http://example.com/audio.mp3", "audio");

    EXPECT_EQ(media.getType(), "audio");
}