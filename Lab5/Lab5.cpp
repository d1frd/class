#include <iostream>
#include <string>
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
using namespace std;

int main()
{
	Vector m(2);

	Person A;
	cin >> A;

	Employee B;
	cin >> B;

	Object* p = &A;
	m.Add(p);

	p = &B;
	m.Add(p);

	cout << m;

}