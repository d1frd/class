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
		cout << "\n������ A ������ ������� B\n";
	}
	else
	{
		if (a > b)
		{
			cout << "\n������ A ������ ������� B\n";
		}
		else
		{
			cout << "\n������ A ����� ������� B\n";
		}
	}
	--b;
	a--;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	
}

