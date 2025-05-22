#pragma once
#include "Human.h"
#include <iostream>
#include <string>
using namespace std;


class Abiturient : public Human
{
protected:
	int point;
	string spec;

public:
	Abiturient();
	Abiturient(string name, int age, int point, string spec);
	Abiturient(const Abiturient& Ptr);
	~Abiturient();
	int get_point() { return point; }
	void set_point(int point) { this->point = point; }
	string get_spec() { return spec; }
	void set_spec(string spec) { this->spec = spec; }
	void Show();
	void Input();
	Abiturient& operator =(const Abiturient& Ptr);
};
