#include "Abiturient.h"
#include <iostream>
#include <string>
using namespace std;
Abiturient::Abiturient()
{
	FIO=" ";
	spec=" ";
	b=0;
	cout << "����������� ��� ���������� " << this << endl;
}
Abiturient::Abiturient(string F, string S, int B)
{
	FIO = F;
	spec = S;
	b = B;
	cout << "����������� � ����������� ��� ������� " << this << endl;
}
Abiturient::Abiturient(const Abiturient &t)
{
	FIO = t.FIO;
	spec = t.spec;
	b = t.b;
	cout << "����������� ����������� " << this << endl;
}
Abiturient::~Abiturient()
{
	cout << "���������� ��� ������� " << this << endl;
}
//���������
string Abiturient::get_FIO()
{
	return FIO;

}
//������������

void Abiturient::set_FIO(string F)
{
	FIO = F;

}
string Abiturient::get_spec()
{
	return spec;
}
void Abiturient::set_spec(string S)
{
	spec = S;
}

int Abiturient::get_b()
{
	return b;
}

void Abiturient::set_b (int B)
{
	b=B;
}
//����� ��� ��������� ���������
void Abiturient::show()
{
	cout << "��� ����������� " << FIO << endl;
	cout << "������������� " << spec << endl;
	cout << "����� ��� " << b << endl;
}
