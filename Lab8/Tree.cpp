#include "Tree.h"
#include "Human.h"
#include "Abiturient.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
	Beg = 0;
	Cur = 0;
	Size = 0;
}

Tree::Tree(int N)
{
	Beg = new Object * [N];
	Object* ptr = nullptr;
	for (int i = 0; i < N; i++)
	{
		Beg[i] = ptr;
	}
	Cur = 0;
	Size = N;
}

Tree::~Tree()
{
	if (Beg != 0)
	{
		delete[] Beg;
	}
	Beg = 0;
}

void Tree::Add()
{
	if (Size > 0)
	{
		Object* ptr;
		cout << "\n�������� ����� ������ �������:\n\n";
		cout << "1. ����� Human\n";
		cout << "2. ����� Abiturient\n";
		cout << "\n������� ����� ��������: ";
		int Code;
		cin >> Code;
		if (Code == 1)
		{
			Human* elem1 = new (Human);
			elem1->Input();
			ptr = elem1;
			if (Cur < Size)
			{
				Beg[Cur] = ptr;
				Cur++;
			}
			else
			{
				Size++;
				Beg[Cur] = ptr;
				Cur++;
			}
			cin.ignore();
		}
		else
		{
			if (Code == 2)
			{
				Abiturient* elem2 = new Abiturient;
				elem2->Input();
				ptr = elem2;
				if (Cur < Size)
				{
					Beg[Cur] = ptr;
					Cur++;
				}
				else
				{
					Size++;
					Beg[Cur] = ptr;
					Cur++;
				}
				cin.ignore();
			}
			else
			{
				cout << "\n������: ������ �������� �����. ������� �� ����� ���� ��������.\n\n";
			}
		}
	}
	else
	{
		cout << "\n�� �� ������� ������! ��������� ������� m �����_�����, ������ ��� �������� � ������� ��������� (����������: q)\n\n";
	}
}

void Tree::Show()
{
	if (Size > 0)
	{
		if (Beg[0] == nullptr)
		{
			cout << "\n��������� �� ���������...\n\n";
		}
		else
		{
			cout << "\n������ �������� ������...\n\n";
			Object** ptr = Beg;
			int i = 0;
			while (i < Size)
			{
				cout << "������ # " << i + 1 << endl;
				if (*ptr != nullptr)
				{
					(*ptr)->Show();
				}
				else
				{
					cout << "\n������ ����!\n\n";
				}
				ptr++;
				i++;
			}
		}
	}
	else
	{
		cout << "\n�� �� ������� ������! ��������� ������� m �����_�����, ������ ��� �������� � ������� ��������� (����������: q)\n\n";
	}
}

void Tree::Age()
{
    if (Beg[0] != nullptr)
    {
        if (Size > 0)
        {
            cout << "\n�������� ������� ������� ��������� ������...\n\n";

            Object** ptr = Beg;
            int totalAge = 0;
            int count = 0;
            int i = 0;
            while (i < Size)
            {
                if (*ptr != nullptr)
                {
                    totalAge += (*ptr)->GetAge(); // ������������, ��� � ������� ���� ����� GetAge()
                    count++;
                }
                ptr++;
                i++;
            }

            if (count > 0)
            {
                double average = static_cast<double>(totalAge) / count;
                cout << "������� �������: " << average << endl;
            }
            else
            {
                cout << "\n��� ��������� ��� ���������� �������� ��������!\n";
            }
        }
        else
        {
            cout << "\n������ ����!\n";
        }
    }
    else
    {
        cout << "*�� �� ������� ������! ��������� ������� � �����_�����, ������ ��� �������� � ������� ��������� (����������: q)\n\n";
    }
}

int Tree::operator () ()
{
	return Size;
}

void Tree::Del()			// "��������", ������ �� �������������!
{
	if (Size > 0)
	{
		int temp = Size - 1;
		while (Beg[temp] == nullptr)
		{
			Size--;
			temp--;
		}
		Size--;
		Cur--;
	}
	else
	{
		cout << "�������� ����������: ������ ������ ����� 0 ��� ������ �� �������\n";
		Size = 0;
	}
}