#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(int F, double S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

int main()
{
	setlocale(LC_ALL, "RU");
	fraction A;
	A.Init(1, 1);
	A.Read();
	A.Show();
	cout << "Произведение = " << A.Multiply();
	return 0;
}
