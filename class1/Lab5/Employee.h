#pragma once
#include "Person.h"
class Employee : public Person
{
private:
	string post;
	double oklad;
public:
	Employee();
	Employee(string P, double O);
	Employee(const Employee& p);
	~Employee();

	string get_post();
	void set_post(string P);
	double get_oklad();
	void set_oklad(double O);

	Employee& operator= (const Employee& p);                // Оператор присваивания
	friend istream& operator>> (istream& in, Employee& p);      // Оператор вывода
	friend ostream& operator<< (ostream& out, const Employee& p); // Оператор ввода
	void salary();
	void Show() override;
};