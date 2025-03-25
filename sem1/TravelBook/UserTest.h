#include <gtest/gtest.h>
#include "User.h"

TEST(UserTest, Creation) {
    User user(1, "John Doe", "john@example.com", "securePassword123");
    EXPECT_EQ(user.getName(), "John Doe");
    EXPECT_EQ(user.getPassword(), "securePassword123");
}

TEST(UserTest, Authentication) {
    User user(2, "Jane Doe", "jane@example.com", "password456");
    EXPECT_TRUE(user.authenticate("password456"));
    EXPECT_FALSE(user.authenticate("wrongPassword"));
}

TEST(UserTest, ChangePassword) {
    User user(3, "Alice Smith", "alice@example.com", "oldPassword");
    user.changePassword("newPassword");
    EXPECT_TRUE(user.authenticate("newPassword"));
    EXPECT_FALSE(user.authenticate("oldPassword"));
}
