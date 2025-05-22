#pragma once
#include "Object.h"

class Tree
{
protected:
	Object** Beg;
	int Size;
	int Cur;

public:
	Tree();
	Tree(int N);
	~Tree();
	void Add();
	void Del();
	void Show();
	void Age();
	int operator() ();

};
