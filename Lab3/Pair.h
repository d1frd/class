#include <iostream>
using namespace std;
class Pair
{
private:
	int first; double second;
public:
	Pair() { first = 0; second = 0.0; };
	Pair(int f, double s) { first = f; second =s; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {};
	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int f) { first = f; }
	void set_second(int s) { second = s; }
	//������������� ��������
	Pair& operator=(const Pair&);
	Pair& operator--();
	Pair operator--(int);//����������� ��������
	friend bool operator < (Pair& p, Pair& q);						// �������� ���������
	friend bool operator > (Pair& p, Pair& q);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};
