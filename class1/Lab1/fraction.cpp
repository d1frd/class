#include <iostream>
#include "fraction.h"
using namespace std;
void fraction::Init(int F, double S)
{
	first = F; second = S;
}
void fraction::Read()
{
	cout << "Введите целое число: "; cin >> first;
	cout << "Введите дробное число: "; cin >> second;
}
void fraction::Show()
{
	cout << "Целое число:" << first << " ; ";
	cout << "Дробное число: " << second;
	cout << "\n";
}
double fraction::Multiply()
{
	return first * second;
}