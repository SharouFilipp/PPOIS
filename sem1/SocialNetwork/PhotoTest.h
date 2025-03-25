#pragma once

#include <gtest/gtest.h>
#include "Photo.h"

TEST(TestPhoto, TestCreation) {
    Photo photo(1, "http://example.com/photo.jpg");
    
    EXPECT_EQ(photo.getUrl(), "http://example.com/photo.jpg");
}

TEST(TestPhoto, TestSetPhoto) {
    Photo photo(1, "http://example.com/photo.jpg");
    
    photo.setPhoto("http://example.com/new_photo.jpg");
    
    EXPECT_EQ(photo.getUrl(), "http://example.com/new_photo.jpg");
}

TEST(TestPhoto, TestDeletePhoto) {
    Photo photo(1, "http://example.com/photo.jpg");
    
    photo.deletePhoto();
    
    EXPECT_EQ(photo.getUrl(), ""); 
}