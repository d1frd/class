#include <iostream>
#include "fraction.h"
using namespace std;
void fraction::Init(int F, double S)
{
	first = F; second = S;
}
void fraction::Read()
{
	cout << "������� ����� �����: "; cin >> first;
	cout << "������� ������� �����: "; cin >> second;
}
void fraction::Show()
{
	cout << "����� �����:" << first << " ; ";
	cout << "������� �����: " << second;
	cout << "\n";
}
double fraction::Multiply()
{
	return first * second;
}