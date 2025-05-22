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
	cout << "\n����� ���������...\n";
	cout << "���: " << Name << endl;
	cout << "�������: " << Age << endl;
	cout << "���������� ������: " << point << endl << endl;
	cout << "�������������: " << spec << endl << endl;
}

void Abiturient::Input()
{
	cout << "\n���� ������...\n\n";
	cout << "������� ���: ";
	cin >> Name;
	cout << "������� �������: ";
	cin >> Age;

	cout << "������� ����������� ������:";
	cin >> point;

	cout << "������� �������������: ";
	cin >> spec;

	cout << endl;
}