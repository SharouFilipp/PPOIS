#pragma once
#include <iostream>

class NaturalDrob {
public:
	int celaya_czast;
	int czislitel;
	int znamenatel;
	NaturalDrob(int celaya_czast, int czislitel, int znamenatel);
	NaturalDrob(const NaturalDrob& other);
	int Nod(int value_1, int value_2);
	int Nok(int value_1, int value_2);
	void Preobrazovanie();
	void Print();
	int getCelayaCzast() const;
	int getCzislitel() const;
	int getZnamenatel() const;
	NaturalDrob operator+(NaturalDrob& other);
	NaturalDrob& operator+=(NaturalDrob& other);
	NaturalDrob operator+(int chislo);
	NaturalDrob& operator+=(int chislo);

	NaturalDrob operator-(NaturalDrob& other);
	NaturalDrob& operator-=(NaturalDrob& other);
	NaturalDrob operator-(int chislo);
	NaturalDrob& operator-=(int chislo);

	NaturalDrob operator*(NaturalDrob& other);
	NaturalDrob& operator*=(NaturalDrob& other);
	NaturalDrob operator*(int chislo);
	NaturalDrob& operator*=(int chislo);


	NaturalDrob operator/(NaturalDrob& other);
	NaturalDrob& operator/=(NaturalDrob& other);
	NaturalDrob operator/(int chislo);
	NaturalDrob& operator/=(int chislo);

	bool operator<(NaturalDrob& other);
	bool operator>(NaturalDrob& other);
	bool operator<=(NaturalDrob& other);
	bool operator>=(NaturalDrob& other);
};