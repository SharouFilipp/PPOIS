#pragma once

#include <gtest/gtest.h>
#include "Post.h"
#include "Comment.h"
#include "Like.h"

TEST(TestPost, TestCreation) {
    Post post(1, "This is a test post.");
    
    EXPECT_EQ(post.getPostId(), 1);
    EXPECT_EQ(post.getContent(), "This is a test post.");
    EXPECT_EQ(post.getLikeCount(), 0);
    EXPECT_EQ(post.getComments().size(), 0); 
}

TEST(TestPost, TestAddComment) {
    Post post(1, "This is a test post.");
    Comment comment(1, "This is a comment.", 100);
    
    post.addComment(comment);
    
    EXPECT_EQ(post.getComments().size(), 1);
    EXPECT_EQ(post.getComments()[0].getContent(), "This is a comment.");
}

TEST(TestPost, TestRemoveComment) {
    Post post(1, "This is a test post.");
    Comment comment(1, "This is a comment.", 100);
    
    post.addComment(comment);
    EXPECT_EQ(post.getComments().size(), 1);

    post.removeComment(1);
    EXPECT_EQ(post.getComments().size(), 0);
}

TEST(TestPost, TestAddLike) {
    Post post(1, "This is a test post.");
    Like like(1, 100);

    post.addLike(like);
    
    EXPECT_EQ(post.getLikeCount(), 1);
}

TEST(TestPost, TestRemoveLike) {
    Post post(1, "This is a test post.");
    Like like(1, 100);
    
    post.addLike(like);
    EXPECT_EQ(post.getLikeCount(), 1);
    
    post.removeLike(1);
    EXPECT_EQ(post.getLikeCount(), 0);
}

TEST(TestPost, TestDisplayPost) {
    Post post(1, "This is a test post.");
    post.displayPost();
}