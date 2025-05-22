#include "Pair.h"
#include <iostream>
using namespace std;

void main()
{
	system("chcp 1251>nul");
	Pair a;
	Pair b;
	cin >> a;
	cin >> b;
	if (a < b)
	{
		cout << "\nОбъект A меньше объекта B\n";
	}
	else
	{
		if (a > b)
		{
			cout << "\nОбъект A больше объекта B\n";
		}
		else
		{
			cout << "\nОбъект A равен объекту B\n";
		}
	}
	--b;
	a--;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	
}

