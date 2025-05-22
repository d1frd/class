#include "Pair.h"
#include <iostream>
using namespace std;
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}
Pair&Pair::operator--()
{
	--first;
	return *this;
}
Pair Pair::operator --(int)
{
	second--;
	return *this;
}
bool operator < (Pair& p, Pair& q)						// Оператор сравнения
{
	if (p.first < q.first)
	{
		return true;
	}
	else
	{
		if (p.first > q.first)
		{
			return false;
		}
		else
		{
			if (p.second < q.second)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
bool operator > (Pair& p, Pair& q)						// Оператор сравнения
{
	if (p.first > q.first)
	{
		return true;
	}
	else
	{
		if (p.first < q.first)
		{
			return false;
		}
		else
		{
			if (p.second > q.second)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
istream& operator>>(istream& in, Pair& p)
{
	cout << "first?"; in >> p.first;
	cout << "second?"; in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	return (out << p.first << ":" << p.second);

}