#include "Abiturient.h"
#include <iostream>
#include <string>
Abiturient make_abiturient()
{
	string F;
	string S;
	int B;
	cout << "Введите ФИО " << endl;
	cin >> F;
	cout << "Введите специальность " << endl;
	cin >> S;
	cout << "Введите количество баллов " << endl;
	cin >> B;
	Abiturient t(F, S, B);
	return t;
}
void print_abiturient(Abiturient t)
{
	t.show();
}
void main()
{
	system("chcp 1251>nul");
	setlocale(LC_ALL, "RU");
	Abiturient t1;
	t1.show();
	Abiturient t2("Иванов И.И.", "Востоковедение и африканистика", 248);
	t2.show();
	Abiturient t3 = t2;
	t3.set_FIO("Петров П.П.");
	t3.set_spec("Гидрометеорология");
	t3.set_b(260);
	print_abiturient(t3);
	t1 = make_abiturient();
	t1.show();
}
