#include "Vector.h"
//конструктор без параметров
Vector::Vector()
{
	begin = nullptr;
	size = 0;
	cur = 0;
}
//конструктор с параметрами
Vector::Vector(int N)
{
	begin = new Object * [N];
	size = N;
	cur = 0;
}
//деструктор
Vector::~Vector()
{
	if (begin != nullptr)
		delete[] begin;
	begin = nullptr;
}
//добавление объекта, на который указывает указатель p в вектор
void Vector::Add(Object* p)
{
	if (cur < size)
	{
		begin[cur] = p;
		cur++;
	}

}
//операция вывода
ostream& operator<<(ostream& out, const Vector& vec)
{
	if (vec.size == 0)
		out << "Vector is empty!" << endl;
	else
	{
		Object** ptr = vec.begin; //указатель на указатель типа Object
		for (int i = 0; i < vec.cur; i++)
		{
			(*ptr)->Show();
			ptr++;
		}
	}
	return out;
}