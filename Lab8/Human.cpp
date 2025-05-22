#include "Human.h"
#include <iostream>
using namespace std;

Human::Human()
{
	Name = "";
	Age = 0;
}

Human::Human(string name, int age)
{
	Name = name;
	Age = age;
}

Human::Human(const Human& Ptr)
{
	Name = Ptr.Name;
	Age = Ptr.Age;
}

Human::~Human()
{

}

Human& Human::operator =(const Human& Ptr)
{
	if (&Ptr != this)
	{
		Name = Ptr.Name;
		Age = Ptr.Age;
	}
	return *this;
}

int Human::GetAge() const
{
	return Age;
}

void Human::Show()
{
	cout << "\n����� ���������...\n";
	cout << "���: " << Name << endl;
	cout << "�������: " << Age << endl << endl;
}

void Human::Input()
{
	cout << "\n���� ������...\n\n";

	cout << "������� ���: ";
	cin >> Name;

	cout << "������� �������: ";
	cin >> Age;

	cout << endl;
}