#include "Abiturient.h"
#include <iostream>
#include <string>
using namespace std;
Abiturient::Abiturient()
{
	FIO=" ";
	spec=" ";
	b=0;
	cout << "Конструктор без параметров " << this << endl;
}
Abiturient::Abiturient(string F, string S, int B)
{
	FIO = F;
	spec = S;
	b = B;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}
Abiturient::Abiturient(const Abiturient &t)
{
	FIO = t.FIO;
	spec = t.spec;
	b = t.b;
	cout << "Конструктор копирования " << this << endl;
}
Abiturient::~Abiturient()
{
	cout << "Деструктор для объекта " << this << endl;
}
//селекторы
string Abiturient::get_FIO()
{
	return FIO;

}
//модификаторы

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
//метод для просмотра атрибутов
void Abiturient::show()
{
	cout << "ФИО абитуриента " << FIO << endl;
	cout << "Специальность " << spec << endl;
	cout << "Баллы ЕГЭ " << b << endl;
}
