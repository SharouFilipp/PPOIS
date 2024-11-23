#include "Child.h"

TEST(ChildTest, Constructor) {
    Child child("Alice", 10);

    EXPECT_EQ(child.getName(), "Alice");
    EXPECT_EQ(child.getAge(), 10);
    
}

TEST(ChildTest, CheckAge) {
    Child childUnder18("Bob", 15);
    Child childAdult("Charlie", 18);

    EXPECT_TRUE(childUnder18.checkAge());  
    EXPECT_FALSE(childAdult.checkAge());    
}

TEST(ChildTest, UpdateAge) {
    Child child("Daisy", 12);

    child.updateAge(20);
    EXPECT_EQ(child.getAge(), 20);
    EXPECT_FALSE(child.checkAge()); 
}