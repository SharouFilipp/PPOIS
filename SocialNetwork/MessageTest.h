#pragma once

#include <gtest/gtest.h>
#include "Message.h"

TEST(TestMessage, TestCreation) {
    Message message(1, 100, 200, "Hello, World!");
    
    EXPECT_EQ(message.getMessageId(), 1);
    EXPECT_EQ(message.getSenderId(), 100);
    EXPECT_EQ(message.getGetterId(), 200);
    EXPECT_EQ(message.getContent(), "Hello, World!");
    EXPECT_FALSE(message.getStatus()); 
}

TEST(TestMessage, TestStatusRead) {
    Message message(1, 100, 200, "Hello, World!");
    
    message.statusRead();
    
    EXPECT_TRUE(message.getStatus()); 
}

TEST(TestMessage, TestDeleteMessage) {
    Message message(1, 100, 200, "Hello, World!");
    
    message.deleteMessage();
    
    EXPECT_EQ(message.getContent(), ""); 
    EXPECT_FALSE(message.getStatus());
}