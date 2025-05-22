#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee()
{
	post = " ";
	oklad = 0.0;
}

Employee::Employee(string P, double O)
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

Employee::~Employee()
{

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
	oklad = O;
}
Employee& Employee ::operator = (const Employee& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	post = p.post;
	oklad = p.oklad;
	return *this;
}

istream& operator >> (istream& in, Employee& p)        // Оператор ввода
{

	cout << "\nINPUT NAME: ";
	in >> p.name;
	cout << "INPUT AGE: ";
	in >> p.age;
	cout << "INPUT POST: ";
	in >> p.post;
	cout << "INPUT OKLAD: ";
	in >> p.oklad;
	return in;
}

ostream& operator << (ostream& out, const Employee& p)    // Оператор вывода
{
	out << "\nNAME: " << p.name << endl;
	out << "AGE: " << p.age << endl;
	out << "POST: " << p.post << endl;
	out << "OKLAD: " << p.oklad << endl;
	return out;
}

void Employee::salary()
{
	cout << "Введите процент от оклада" << endl;
	int proc;
	cin >> proc;
	cout << "Зарплата= " << proc * oklad * 0.01 + oklad << endl;
}

void Employee::Show()
{
	cout << "\nNAME: " << name;
	cout << "\nAGE: " << age;
	cout << "\nPOST: " << post;
	cout << "\nOKLAD: " << oklad<< endl;

}