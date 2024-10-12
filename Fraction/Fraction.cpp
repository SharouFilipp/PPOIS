#include <iostream>
#include "Fraction.h"
using namespace std;


Fraction::Fraction(int integerPart, int numerator, int denominator) : integerPart(integerPart), numerator(numerator), denominator(denominator)
{
    if (denominator != 0) 
    {
    this->numerator = numerator;
    this->denominator = denominator;
    this->integerPart = integerPart;
    Preobrazovanie();
    }
    else throw invalid_argument("Знаменатель не может быть равен нулю");
}
Fraction::Fraction(const Fraction& other) : integerPart(other.integerPart), numerator(other.numerator), denominator(other.denominator)
{
    if (denominator != 0) 
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        this->integerPart = other.integerPart;
        Preobrazovanie();
    }
    else throw invalid_argument("Знаменатель не может быть равен нулю");
}

void Fraction::Print()
{
    cout << integerPart << " " << numerator << "/" << denominator << endl;
}
void Fraction::Preobrazovanie()
{
    integerPart += int(numerator / denominator);
    numerator -= int(numerator / denominator) * denominator;
    int gcd = GCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int Fraction::GCD(int value_1, int value_2)
{
    int gcd = 0;
    while (value_2 != 0) {
        gcd = value_2;
        value_2 = value_1 % value_2;
        value_1 = gcd;
    }
    return value_1;
}

int Fraction::getIntegerPart() const {
    return integerPart;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::LCM(int value_1, int value_2)
{
    return (value_1 / GCD(value_1, value_2)) * value_2;
}

Fraction Fraction::operator+(Fraction& other)
{
    int lcm = LCM(denominator, other.denominator);
    return Fraction(integerPart + other.integerPart, numerator * int(lcm / denominator) + other.numerator * int(lcm / other.denominator), lcm );
}

Fraction& Fraction::operator+=(Fraction& other)
{
    Fraction natural = *this + other;
    *this = natural;
    return *this;
}

Fraction Fraction::operator+(int chislo) {
    return Fraction(integerPart + chislo, numerator, denominator);
}

Fraction& Fraction::operator+=(int chislo) {
    Fraction natural = *this + chislo;
    *this = natural;
    return *this;
}


Fraction Fraction::operator-(Fraction& other)
{
    int lcm = LCM(denominator, other.denominator);
    return Fraction(integerPart - other.integerPart, numerator * int(lcm / denominator) - other.numerator * int(lcm / other.denominator), lcm);
}

Fraction& Fraction::operator-=(Fraction& other)
{
    Fraction natural = *this - other;
    *this = natural;
    return *this;
}

Fraction Fraction::operator-(int chislo) {
    return Fraction(integerPart - chislo, numerator, denominator);
}

Fraction& Fraction::operator-=(int chislo) {
    Fraction natural = *this - chislo;
    *this = natural;
    return *this;
}



Fraction Fraction::operator*(Fraction& other)
{
    return Fraction(0, (numerator + integerPart * denominator) * (other.numerator + other.integerPart * other.denominator), denominator * other.denominator);
}

Fraction& Fraction::operator*=(Fraction& other)
{
    Fraction natural = *this * other;
    *this = natural;
    return *this;
}

Fraction Fraction::operator*(int chislo) {
    return Fraction(0, (numerator + integerPart * denominator) * chislo, denominator);
}

Fraction& Fraction::operator*=(int chislo) {
    Fraction natural = *this * chislo;
    *this = natural;
    return *this;
}


Fraction Fraction::operator/(Fraction& other)
{
    return Fraction(0, (numerator + integerPart * denominator) * other.denominator, denominator * (other.numerator + other.integerPart * other.denominator));
}

Fraction& Fraction::operator/=(Fraction& other)
{
    Fraction natural = *this / other;
    *this = natural;
    return *this;
}

Fraction Fraction::operator/(int chislo) {
    return Fraction(0, (numerator + integerPart * denominator) , denominator * chislo);
}

Fraction& Fraction::operator/=(int chislo) {
    Fraction natural = *this / chislo;
    *this = natural;
    return *this;
}




bool Fraction::operator<(Fraction& other)
{
    int lcm = LCM(denominator, other.denominator);
    numerator += integerPart * denominator;
    numerator *= lcm / denominator;
    other.numerator += other.integerPart * other.denominator;
    other.numerator *= lcm / other.denominator;
    return numerator > other.numerator;
}

bool Fraction::operator>(Fraction& other)
{
    int lcm = LCM(denominator, other.denominator);
    numerator += integerPart * denominator;
    numerator *= lcm / denominator;
    other.numerator += other.integerPart * other.denominator;
    other.numerator *= lcm / other.denominator;
    return numerator < other.numerator;
}

bool Fraction::operator>=(Fraction& other)
{
    int lcm = LCM(denominator, other.denominator);
    numerator += integerPart * denominator;
    numerator *= lcm / denominator;
    other.numerator += other.integerPart * other.denominator;
    other.numerator *= lcm / other.denominator;
    return numerator >= other.numerator;
}

bool Fraction::operator<=(Fraction& other) {
    
    int lcm = LCM(denominator, other.denominator);
    numerator += integerPart * denominator;
    numerator *= lcm / denominator;
    other.numerator += other.integerPart * other.denominator;
    other.numerator *= lcm / other.denominator;
    return numerator <= other.numerator;
}
/*
int main(){
    Fraction natural_1(1,23,2);
    natural_1.Print();

}
*/