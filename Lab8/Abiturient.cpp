#include "Abiturient.h"
#include <iostream>

using namespace std;

Abiturient::Abiturient() : Human()
{
	point = 0;
	spec = "-";
}

Abiturient::Abiturient(string name, int age, int point, string spec) : Human(name, age)
{
	this->point = point;
	this->spec = spec;
}

Abiturient::Abiturient(const Abiturient& Ptr)
{
	Name = Ptr.Name;
	Age = Ptr.Age;
	point = Ptr.point;
	spec = Ptr.spec;
}

Abiturient::~Abiturient() {}

Abiturient& Abiturient::operator =(const Abiturient& Ptr)
{
	if (&Ptr != this)
	{
		Name = Ptr.Name;
		Age = Ptr.Age;
		point= Ptr.point;
		spec = Ptr.spec;
	}
	return *this;
}

void Abiturient::Show()
{
	cout << "\nВывод атрибутов...\n";
	cout << "Имя: " << Name << endl;
	cout << "Возраст: " << Age << endl;
	cout << "Количество баллов: " << point << endl << endl;
	cout << "Специальность: " << spec << endl << endl;
}

void Abiturient::Input()
{
	cout << "\nВвод данных...\n\n";
	cout << "Введите имя: ";
	cin >> Name;
	cout << "Введите возраст: ";
	cin >> Age;

	cout << "Введите колличество баллов:";
	cin >> point;

	cout << "Введите специальность: ";
	cin >> spec;

	cout << endl;
}