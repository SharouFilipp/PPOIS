// natural_drob.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "NaturalDrob.h"
using namespace std;




NaturalDrob::NaturalDrob(int celaya_czast, int czislitel, int znamenatel) : celaya_czast(celaya_czast), czislitel(czislitel), znamenatel(znamenatel)
{
    this->czislitel = czislitel;
    this->znamenatel = znamenatel;
    this->celaya_czast = celaya_czast;
    Preobrazovanie();
}
NaturalDrob::NaturalDrob(const NaturalDrob& other) : celaya_czast(other.celaya_czast), czislitel(other.czislitel), znamenatel(other.znamenatel)
{
    this->czislitel = other.czislitel;
    if (znamenatel != 0) this->znamenatel = other.znamenatel;
    else throw invalid_argument("Знаменатель не может быть равен нулю");
    this->znamenatel = other.znamenatel;
    this->celaya_czast = other.celaya_czast;
    Preobrazovanie();
}

void NaturalDrob::Print()
{
    cout << celaya_czast << " " << czislitel << "/" << znamenatel << endl;
}
void NaturalDrob::Preobrazovanie()
{
    celaya_czast += int(czislitel / znamenatel);
    czislitel -= int(czislitel / znamenatel) * znamenatel;
    int nod = Nod(czislitel, znamenatel);
    czislitel /= nod;
    znamenatel /= nod;
}

int NaturalDrob::Nod(int value_1, int value_2)
{
    int nod = 0;
    while (value_2 != 0) {
        nod = value_2;
        value_2 = value_1 % value_2;
        value_1 = nod;
    }
    return value_1;
}

int NaturalDrob::getCelayaCzast() const {
    return celaya_czast;
}

int NaturalDrob::getCzislitel() const {
    return czislitel;
}

int NaturalDrob::getZnamenatel() const {
    return znamenatel;
}

int NaturalDrob::Nok(int value_1, int value_2)
{
    return (value_1 / Nod(value_1, value_2)) * value_2;
}

NaturalDrob NaturalDrob::operator+(NaturalDrob& other)
{
    int nok = Nok(znamenatel, other.znamenatel);
    return NaturalDrob(celaya_czast + other.celaya_czast, czislitel * int(nok / znamenatel) + other.czislitel * int(nok / other.znamenatel), nok );
}

NaturalDrob& NaturalDrob::operator+=(NaturalDrob& other)
{
    NaturalDrob natural = *this + other;
    *this = natural;
    return *this;
}

NaturalDrob NaturalDrob::operator+(int chislo) {
    return NaturalDrob(celaya_czast + chislo, czislitel, znamenatel);
}

NaturalDrob& NaturalDrob::operator+=(int chislo) {
    NaturalDrob natural = *this + chislo;
    *this = natural;
    return *this;
}


NaturalDrob NaturalDrob::operator-(NaturalDrob& other)
{
    int nok = Nok(znamenatel, other.znamenatel);
    return NaturalDrob(celaya_czast - other.celaya_czast, czislitel * int(nok / znamenatel) - other.czislitel * int(nok / other.znamenatel), nok);
}

NaturalDrob& NaturalDrob::operator-=(NaturalDrob& other)
{
    NaturalDrob natural = *this - other;
    *this = natural;
    return *this;
}

NaturalDrob NaturalDrob::operator-(int chislo) {
    return NaturalDrob(celaya_czast - chislo, czislitel, znamenatel);
}

NaturalDrob& NaturalDrob::operator-=(int chislo) {
    NaturalDrob natural = *this - chislo;
    *this = natural;
    return *this;
}



NaturalDrob NaturalDrob::operator*(NaturalDrob& other)
{
    return NaturalDrob(0, (czislitel + celaya_czast * znamenatel) * (other.czislitel + other.celaya_czast * other.znamenatel), znamenatel * other.znamenatel);
}

NaturalDrob& NaturalDrob::operator*=(NaturalDrob& other)
{
    NaturalDrob natural = *this * other;
    *this = natural;
    return *this;
}

NaturalDrob NaturalDrob::operator*(int chislo) {
    return NaturalDrob(0, (czislitel + celaya_czast * znamenatel) * chislo, znamenatel);
}

NaturalDrob& NaturalDrob::operator*=(int chislo) {
    NaturalDrob natural = *this * chislo;
    *this = natural;
    return *this;
}


NaturalDrob NaturalDrob::operator/(NaturalDrob& other)
{
    return NaturalDrob(0, (czislitel + celaya_czast * znamenatel) * other.znamenatel, znamenatel * (other.czislitel + other.celaya_czast * other.znamenatel));
}

NaturalDrob& NaturalDrob::operator/=(NaturalDrob& other)
{
    NaturalDrob natural = *this / other;
    *this = natural;
    return *this;
}

NaturalDrob NaturalDrob::operator/(int chislo) {
    return NaturalDrob(0, (czislitel + celaya_czast * znamenatel) , znamenatel * chislo);
}

NaturalDrob& NaturalDrob::operator/=(int chislo) {
    NaturalDrob natural = *this / chislo;
    *this = natural;
    return *this;
}




bool NaturalDrob::operator<(NaturalDrob& other)
{
    int nok = Nok(znamenatel, other.znamenatel);
    czislitel += celaya_czast * znamenatel;
    czislitel *= nok / znamenatel;
    other.czislitel += other.celaya_czast * other.znamenatel;
    other.czislitel *= nok / other.znamenatel;
    return czislitel > other.czislitel;
}

bool NaturalDrob::operator>(NaturalDrob& other)
{
    int nok = Nok(znamenatel, other.znamenatel);
    czislitel += celaya_czast * znamenatel;
    czislitel *= nok / znamenatel;
    other.czislitel += other.celaya_czast * other.znamenatel;
    other.czislitel *= nok / other.znamenatel;
    return czislitel < other.czislitel;
}

bool NaturalDrob::operator>=(NaturalDrob& other)
{
    int nok = Nok(znamenatel, other.znamenatel);
    czislitel += celaya_czast * znamenatel;
    czislitel *= nok / znamenatel;
    other.czislitel += other.celaya_czast * other.znamenatel;
    other.czislitel *= nok / other.znamenatel;
    return czislitel >= other.czislitel;
}

bool NaturalDrob::operator<=(NaturalDrob& other) {
    
    int nok = Nok(znamenatel, other.znamenatel);
    czislitel += celaya_czast * znamenatel;
    czislitel *= nok / znamenatel;
    other.czislitel += other.celaya_czast * other.znamenatel;
    other.czislitel *= nok / other.znamenatel;
    return czislitel <= other.czislitel;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
