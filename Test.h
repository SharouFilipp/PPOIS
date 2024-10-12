#include <gtest/gtest.h>
#include "NaturalDrob.h"

TEST(NaturalDrobtest, SummaDrobei) {
    NaturalDrob drob1(1, 1, 2);
    NaturalDrob drob2(0, 1, 3);

    NaturalDrob result = drob1 + drob2; 
    EXPECT_EQ(result.getCelayaCzast(), 1);
    EXPECT_EQ(result.getCzislitel(), 5);
    EXPECT_EQ(result.getZnamenatel(), 6);
}

TEST(NaturalDrobtest, SummaDrobei2) {
    NaturalDrob drob1(1, 1, 2);
    NaturalDrob drob2(0, 1, 3);
    drob1 += drob2; 

    EXPECT_EQ(drob1.getCelayaCzast(), 1);
    EXPECT_EQ(drob1.getCzislitel(), 5);
    EXPECT_EQ(drob1.getZnamenatel(), 6);
}

TEST(NaturalDrobtest, RaznostDrobei) {
    NaturalDrob drob1(1, 1, 2);
    NaturalDrob drob2(0, 1, 3);
    NaturalDrob result = drob1 - drob2; 
    EXPECT_EQ(result.getCelayaCzast(), 1);
    EXPECT_EQ(result.getCzislitel(), 1);
    EXPECT_EQ(result.getZnamenatel(), 6);
}

TEST(NaturalDrobtest, RaznostDrobei2) {
    NaturalDrob drob1(1, 1, 2);
    NaturalDrob drob2(0, 1, 3);
    drob1 -= drob2; 

    EXPECT_EQ(drob1.getCelayaCzast(), 1);
    EXPECT_EQ(drob1.getCzislitel(), 1);
    EXPECT_EQ(drob1.getZnamenatel(), 6);
}

TEST(NaturalDrobtest, UmnozhenieDrobei) {
    NaturalDrob drob3(2, 1, 3); 
    NaturalDrob drob1(1, 1, 2);
    NaturalDrob result = drob1 * drob3;
    EXPECT_EQ(result.getCelayaCzast(), 3);
    EXPECT_EQ(result.getCzislitel(), 1);
    EXPECT_EQ(result.getZnamenatel(), 2);
}

TEST(NaturalDrobtest, UmnozhenieDrobei2) {
    NaturalDrob drob3(2, 1, 3); 
    NaturalDrob drob1(1, 1, 2);
    drob1 *= drob3;
    EXPECT_EQ(drob1.getCelayaCzast(), 3);
    EXPECT_EQ(drob1.getCzislitel(), 1);
    EXPECT_EQ(drob1.getZnamenatel(), 2);
}

TEST(NaturalDrobtest, DelenieDrobei) {
    NaturalDrob drob1(1, 1, 2);
    NaturalDrob drob2(0, 1, 3);
    NaturalDrob result = drob1 / drob2; 
    EXPECT_EQ(result.getCelayaCzast(), 4);
    EXPECT_EQ(result.getCzislitel(), 1);
    EXPECT_EQ(result.getZnamenatel(), 2);
}

TEST(NaturalDrobtest, DelenieDrobei2) {
    NaturalDrob drob1(1, 1, 2);
    NaturalDrob drob2(0, 1, 3);
    drob1 /= drob2;
    EXPECT_EQ(drob1.getCelayaCzast(),4);
    EXPECT_EQ(drob1.getCzislitel(), 1);
    EXPECT_EQ(drob1.getZnamenatel(), 2);
}

TEST(NaturalDrobTests, Sravnenie) {
    NaturalDrob drob1(1, 1, 2);
    NaturalDrob drob2(0, 1, 3); 

    EXPECT_EQ(drob1 > drob2, 0);
    EXPECT_EQ(drob1 >= drob2, 1);
    EXPECT_EQ(drob2 < drob1, 0);
    EXPECT_EQ(drob2 <= drob1,1);
}

TEST(NaturalDrobTests, SummaInteger) {
    NaturalDrob drob(1, 1, 2);
    NaturalDrob result = drob + 2; 

    EXPECT_EQ(result.getCelayaCzast(), 3);
    EXPECT_EQ(result.getCzislitel(), 1);
    EXPECT_EQ(result.getZnamenatel(), 2);
}

TEST(NaturalDrobTests, RaznostInteger) {
    NaturalDrob drob(3, 1, 2); 
    NaturalDrob result = drob - 1; 

    EXPECT_EQ(result.getCelayaCzast(), 2);
    EXPECT_EQ(result.getCzislitel(), 1);
    EXPECT_EQ(result.getZnamenatel(), 2);
}

TEST(NaturalDrobTests, UmnozhInteger) {
    NaturalDrob drob(3, 1, 2); 
    NaturalDrob result = drob * 5; 
    EXPECT_EQ(result.getCelayaCzast(), 17);
    EXPECT_EQ(result.getCzislitel(), 1);
    EXPECT_EQ(result.getZnamenatel(), 2);
}



TEST(NaturalDrobTests, ZeroDenominator) {
    EXPECT_THROW(NaturalDrob(1, 1, 0), std::invalid_argument);
}

TEST(NaturalDrobTests, SummaZero) {
    NaturalDrob drob(1, 1, 2); 
    NaturalDrob result = drob + 0; 

    EXPECT_EQ(result.getCelayaCzast(), 1);
    EXPECT_EQ(result.getCzislitel(), 1);
    EXPECT_EQ(result.getZnamenatel(), 2);
}

TEST(NaturalDrobTests, RaznostZero) {
    NaturalDrob drob(1, 1, 2); 
    NaturalDrob result = drob - 0; 

    EXPECT_EQ(result.getCelayaCzast(), 1);
    EXPECT_EQ(result.getCzislitel(), 1);
    EXPECT_EQ(result.getZnamenatel(), 2);
}