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
	Abiturient(); //����������� ��� ����������
	Abiturient(string F, string S, int B);// ����������� � �����������
	Abiturient(const Abiturient& t);// ����������� �����������
	~Abiturient();// ����������
	string get_FIO();// ��������
	void set_FIO(string F);// �����������
	string get_spec();// ��������
	void set_spec(string S);// �����������
	int get_b();//��������
	void set_b(int B);//�����������
	void show();//�������� ���������
};