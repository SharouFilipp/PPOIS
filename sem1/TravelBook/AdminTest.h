#include "Admin.h"
#include "User.h"

TEST(AdminTest, AddUser) {
    Admin admin;
    User* user = new User(1, "Alice", "alice@example.com", "password");

    admin.addUser(user);
    EXPECT_EQ(admin.getUserCount(), 1); 
}

TEST(AdminTest, RemoveUser) {
    Admin admin;
    User* user = new User(1, "Alice", "alice@example.com", "password");

    admin.addUser(user);
    EXPECT_EQ(admin.getUserCount(), 1); 

    admin.removeUser(0);
    EXPECT_EQ(admin.getUserCount(), 0); 
}

TEST(AdminTest, RemoveUserInvalidIndex) {
    Admin admin;
    User* user = new User(1, "Alice", "alice@example.com", "password");

    admin.addUser(user);
    admin.removeUser(1); 

    EXPECT_EQ(admin.getUserCount(), 1); 
}

TEST(AdminTest, FindUserByName) {
    Admin admin;
    User* user = new User(1, "Alice", "alice@example.com", "password");

    admin.addUser(user);
    User* foundUser = admin.findUserByName("Alice");

    EXPECT_NE(foundUser, nullptr);
    EXPECT_EQ(foundUser->getName(), "Alice"); 
}

TEST(AdminTest, FindUserByNameNotFound) {
    Admin admin;
    User* user = new User(1, "Alice", "alice@example.com", "password");

    admin.addUser(user);
    User* foundUser = admin.findUserByName("Bob");

    EXPECT_EQ(foundUser, nullptr); 
}

TEST(AdminTest, ClearUsers) {
    Admin admin;
    User* user1 = new User(1, "Alice", "alice@example.com", "password");
    User* user2 = new User(2, "Bob", "bob@example.com", "password");

    admin.addUser(user1);
    admin.addUser(user2);
    EXPECT_EQ(admin.getUserCount(), 2); 
    admin.clearUsers();
    EXPECT_EQ(admin.getUserCount(), 0); 
}