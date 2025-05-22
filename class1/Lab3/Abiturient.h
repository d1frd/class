#pragma once
#include <string>
using namespace std;
class Abiturient
{
private:
	string FIO;
	string spec;
	int b;
public:
	Abiturient(); //конструктор без параметров
	Abiturient(string F, string S, int B);// конструктор с параметрами
	Abiturient(const Abiturient& t);// конструктор копирования
	~Abiturient();// деструктор
	string get_FIO();// селектор
	void set_FIO(string F);// модификатор
	string get_spec();// селектор
	void set_spec(string S);// модификатор
	int get_b();//селектор
	void set_b(int B);//модификатор
	void show();//просмотр атрибутов
};