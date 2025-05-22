#include "Employee.h"
#include "Person.h"
#include <iostream>
using namespace std;

Employee::Employee(void):Person()
{
	post = " ";
	oklad = 0;

}
Employee::~Employee(void)
{

}

Employee::Employee(int Age, string Name, string P, double O):Person(Age, Name)
{
	post = P;
	oklad = O;
}

Employee::Employee(const Employee& p)
{
	post = p.post;
	oklad = p.oklad;
	name = p.name;
	age = p.age;
}

string Employee::get_post()
{
	return post;
}

void Employee::set_post(string P)
{
	post = P;
}

double Employee::get_oklad()
{
	return oklad;
}

void Employee::set_oklad(double O)
{
	oklad=O;
}

Employee&Employee::operator = (const Employee& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	post = p.post;
	oklad = p.oklad;
	return *this;
}

istream& operator >> (istream& in, Employee& p)				// Оператор ввода
{

	cout << "\nINPUT NAME: ";
	in >> p.name;
	cout << "\nINPUT AGE: ";
	in >> p.age;
	cout << "\nINPUT POST: ";
	in >> p.post;
	cout << "\nINPUT OKLAD: ";
	in >> p.oklad;
	return in;
}

ostream& operator << (ostream& out, const Employee& p)		// Оператор вывода
{
	out << "\nNAME: " << p.name << endl;
	out << "\nAGE: " << p.age << endl;
	out << "\nPOST: " << p.post << endl;
	out << "\nOKLAD: " << p.oklad << endl;
	return out;
}

void Employee::salary()
{
	double prem;
	cout << "Введите процент премии " << endl;
	cin >> prem;
	cout << "Зарплата равна " << (0.01 * prem*oklad) + oklad << endl;

}

