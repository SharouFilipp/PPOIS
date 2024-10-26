#include <gtest/gtest.h>
#include <sstream>
#include "Fraction.h"

TEST(Fractiontest, SumFraction) {
    Fraction fraction1(1, 1, 2);
    Fraction fraction2(0, 1, 3);
    Fraction result = fraction1 + fraction2; 

    EXPECT_EQ(result.getIntegerPart(), 1);
    EXPECT_EQ(result.getNumerator(), 5);
    EXPECT_EQ(result.getDenominator(), 6);
}

TEST(Fractiontest, SumFraction2) {
    Fraction fraction1(1, 1, 2);
    Fraction fraction2(0, 1, 3);
    fraction1 += fraction2; 

    EXPECT_EQ(fraction1.getIntegerPart(), 1);
    EXPECT_EQ(fraction1.getNumerator(), 5);
    EXPECT_EQ(fraction1.getDenominator(), 6);
}

TEST(Fractiontest, DifferenceFraction) {
    Fraction fraction1(1, 1, 2);
    Fraction fraction2(0, 1, 3);
    Fraction result = fraction1 - fraction2; 

    EXPECT_EQ(result.getIntegerPart(), 1);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 6);
}

TEST(Fractiontest, DifferenceFraction2) {
    Fraction fraction1(1, 1, 2);
    Fraction fraction2(0, 1, 3);
    fraction1 -= fraction2; 

    EXPECT_EQ(fraction1.getIntegerPart(), 1);
    EXPECT_EQ(fraction1.getNumerator(), 1);
    EXPECT_EQ(fraction1.getDenominator(), 6);
}

TEST(Fractiontest, MultiplicationFraction) {
    Fraction fraction(2, 1, 3); 
    Fraction fraction1(1, 1, 2);
    Fraction result = fraction1 * fraction;

    EXPECT_EQ(result.getIntegerPart(), 3);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(Fractiontest, MultiplicationFraction2) {
    Fraction fraction2(2, 1, 3); 
    Fraction fraction1(1, 1, 2);
    fraction1 *= fraction2;

    EXPECT_EQ(fraction1.getIntegerPart(), 3);
    EXPECT_EQ(fraction1.getNumerator(), 1);
    EXPECT_EQ(fraction1.getDenominator(), 2);
}

TEST(Fractiontest, DivisionFraction) {
    Fraction fraction1(1, 1, 2);
    Fraction fraction2(0, 1, 3);
    Fraction result = fraction1 / fraction2; 
    EXPECT_EQ(result.getIntegerPart(), 4);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(Fractiontest, DivisionFraction2) {
    Fraction fraction1(1, 1, 2);
    Fraction fraction2(0, 1, 3);
    fraction1 /= fraction2;

    EXPECT_EQ(fraction1.getIntegerPart(),4);
    EXPECT_EQ(fraction1.getNumerator(), 1);
    EXPECT_EQ(fraction1.getDenominator(), 2);
}

TEST(FractionTests, Comparison) {
    Fraction fraction1(1, 1, 2);
    Fraction fraction2(0, 1, 3); 

    EXPECT_EQ(fraction1 > fraction2, 0);
    EXPECT_EQ(fraction1 >= fraction2, 1);
    EXPECT_EQ(fraction2 < fraction1, 0);
    EXPECT_EQ(fraction2 <= fraction1,1);
}

TEST(FractionTests, SumInteger) {
    Fraction fraction(1, 1, 2);
    Fraction result = fraction + 2; 

    EXPECT_EQ(result.getIntegerPart(), 3);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(FractionTests, DifferenceInteger) {
    Fraction fraction(3, 1, 2); 
    Fraction result = fraction - 1; 

    EXPECT_EQ(result.getIntegerPart(), 2);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(FractionTests, MultiplicationInteger) {
    Fraction fraction(3, 1, 2); 
    Fraction result = fraction * 5; 

    EXPECT_EQ(result.getIntegerPart(), 17);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(FractionTests, MultiplicationInteger2) {
    Fraction fraction(3, 1, 2); 
    fraction *= 5; 

    EXPECT_EQ(fraction.getIntegerPart(), 17);
    EXPECT_EQ(fraction.getNumerator(), 1);
    EXPECT_EQ(fraction.getDenominator(), 2);
}

TEST(FractionTests, DivisionInteger) {
    Fraction fraction(3, 1, 2); 
    Fraction result = fraction / 5; 

    EXPECT_EQ(result.getIntegerPart(), 0);
    EXPECT_EQ(result.getNumerator(), 7);
    EXPECT_EQ(result.getDenominator(), 10);
}

TEST(FractionTests, DivisionInteger2) {
    Fraction fraction(3, 1, 2); 
    fraction /= 5; 

    EXPECT_EQ(fraction.getIntegerPart(), 0);
    EXPECT_EQ(fraction.getNumerator(), 7);
    EXPECT_EQ(fraction.getDenominator(), 10);
}

TEST(FractionTests, ZeroDenominator) {
    EXPECT_THROW(Fraction(1, 1, 0), std::invalid_argument);
}


TEST(FractionTests, Constructor) {
    Fraction fraction(1, 1, 2); 
    Fraction result = fraction; 

    EXPECT_EQ(result.getIntegerPart(), 1);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(FractionTests, SumZero) {
    Fraction fraction(1, 1, 2); 
    Fraction result = fraction + 0; 

    EXPECT_EQ(result.getIntegerPart(), 1);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(FractionTests, SumZero2) {
    Fraction fraction(1, 1, 2); 
    fraction += 0; 

    EXPECT_EQ(fraction.getIntegerPart(), 1);
    EXPECT_EQ(fraction.getNumerator(), 1);
    EXPECT_EQ(fraction.getDenominator(), 2);
}

TEST(FractionTests, DifferenceZero) {
    Fraction fraction(1, 1, 2); 
    fraction -= 0; 

    EXPECT_EQ(fraction.getIntegerPart(), 1);
    EXPECT_EQ(fraction.getNumerator(), 1);
    EXPECT_EQ(fraction.getDenominator(), 2);
}

TEST(FractionTests, DifferenceZero2) {
    Fraction fraction(1, 1, 2); 
    Fraction result = fraction - 0; 

    EXPECT_EQ(result.getIntegerPart(), 1);
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(FractionTests, TestOutput) {
    Fraction fraction(1,1,2);
    std::ostringstream sss;
    std::streambuf* originalCoutBuf = std::cout.rdbuf(sss.rdbuf());
    fraction.Print(); 
    std::cout.rdbuf(originalCoutBuf);

    EXPECT_EQ(sss.str(), "1 1/2\n");
}

TEST(FractionTests, PostIncriment) {
    Fraction fraction(1, 1, 2); 
    Fraction fract_1 = fraction++; 
    fraction.Preobrazovanie();
    fract_1.Preobrazovanie();

    EXPECT_EQ(fract_1.getIntegerPart(), 1);
    EXPECT_EQ(fract_1.getNumerator(), 1);
    EXPECT_EQ(fract_1.getDenominator(), 2);
    EXPECT_EQ(fraction.getIntegerPart(), 2);
    EXPECT_EQ(fraction.getNumerator(), 1);
    EXPECT_EQ(fraction.getDenominator(), 2);
}
TEST(FractionTests, PostDecriment) {
    Fraction fraction(1, 1, 2); 
    Fraction fract_1 = fraction--; 
    fraction.Preobrazovanie();
    fract_1.Preobrazovanie();

    EXPECT_EQ(fract_1.getIntegerPart(), 1);
    EXPECT_EQ(fract_1.getNumerator(), 1);
    EXPECT_EQ(fract_1.getDenominator(), 2);
    EXPECT_EQ(fraction.getIntegerPart(), 0);
    EXPECT_EQ(fraction.getNumerator(), 1);
    EXPECT_EQ(fraction.getDenominator(), 2);
}
TEST(FractionTests, PreIncriment) {
    Fraction fraction(1, 1, 2); 
    Fraction fract_1 = ++fraction; 
    fraction.Preobrazovanie();
    fract_1.Preobrazovanie();

    EXPECT_EQ(fract_1.getIntegerPart(), 2);
    EXPECT_EQ(fract_1.getNumerator(), 1);
    EXPECT_EQ(fract_1.getDenominator(), 2);
    EXPECT_EQ(fraction.getIntegerPart(), 2);
    EXPECT_EQ(fraction.getNumerator(), 1);
    EXPECT_EQ(fraction.getDenominator(), 2);
}
TEST(FractionTests, PreDecriment) {
    Fraction fraction(1, 1, 2); 
    Fraction fract_1 = --fraction; 
    fraction.Preobrazovanie();
    fract_1.Preobrazovanie();

    EXPECT_EQ(fract_1.getIntegerPart(), 0);
    EXPECT_EQ(fract_1.getNumerator(), 1);
    EXPECT_EQ(fract_1.getDenominator(), 2);
    EXPECT_EQ(fraction.getIntegerPart(), 0);
    EXPECT_EQ(fraction.getNumerator(), 1);
    EXPECT_EQ(fraction.getDenominator(), 2);
}

TEST(FractionTests, Convert_double) {
    Fraction fraction(1, 1, 2); 
    double value = fraction.Convert();
     
    EXPECT_EQ(value, 1.5);
}