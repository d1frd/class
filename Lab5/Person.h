#pragma once
#include "Object.h"
#include <string>
using namespace std;

class Person : public Object
{
protected:
	string name;
	int age;
public:
	Person();
	Person(string Name, int Age);
	Person(const Person& p);
	~Person();

	string get_name();
	void set_name(string Name);
	int get_age();
	void set_age(int Age);

	Person& operator= (const Person& p);								// �������� ������������
	friend istream& operator>> (istream& in, Person& p);			// �������� ������
	friend ostream& operator<< (ostream& out, const Person& p); // �������� �����

	void Show() override;
};
