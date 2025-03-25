#pragma once

#include <gtest/gtest.h>
#include "Comment.h"

TEST(TestComment, TestCreation) {
    Comment comment(1, "This is a test comment.", 100);
    EXPECT_EQ(comment.getId(), 1);
    EXPECT_EQ(comment.getContent(), "This is a test comment.");
    EXPECT_EQ(comment.getTimePost().length(), 25); 
}

TEST(TestComment, TestChangeComment) {
    Comment comment(1, "This is a test comment.", 100);
    comment.ChangeComment("This is an updated comment.");
    
    EXPECT_EQ(comment.getContent(), "This is an updated comment.");
}

TEST(TestComment, TestDeleteComment) {
    Comment comment(1, "This is a test comment.", 100);
    comment.DeleteComment();
    
    EXPECT_EQ(comment.getContent(), ""); 
}