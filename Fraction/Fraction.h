#pragma once
#include <iostream>

class Fraction {
public:
	int integerPart;
	int numerator;
	int denominator;
	Fraction(int integerPart, int numerator, int denominator);
	Fraction(const Fraction& other);
	int GCD(int value_1, int value_2);
	int LCM(int value_1, int value_2);
	void Preobrazovanie();
	void Print();
	int getIntegerPart() const;
	int getNumerator() const;
	int getDenominator() const;
	Fraction operator+(Fraction& other);
	Fraction& operator+=(Fraction& other);
	Fraction operator+(int chislo);
	Fraction& operator+=(int chislo);

	Fraction operator-(Fraction& other);
	Fraction& operator-=(Fraction& other);
	Fraction operator-(int chislo);
	Fraction& operator-=(int chislo);

	Fraction operator*(Fraction& other);
	Fraction& operator*=(Fraction& other);
	Fraction operator*(int chislo);
	Fraction& operator*=(int chislo);

	Fraction operator/(Fraction& other);
	Fraction& operator/=(Fraction& other);
	Fraction operator/(int chislo);
	Fraction& operator/=(int chislo);

	bool operator<(Fraction& other);
	bool operator>(Fraction& other);
	bool operator<=(Fraction& other);
	bool operator>=(Fraction& other);

	Fraction operator--(int);   
	Fraction operator++(int); 
	Fraction& operator--(); 
	Fraction& operator++(); 
	double Convert() const;
};