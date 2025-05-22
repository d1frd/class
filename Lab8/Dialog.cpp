#include "Dialog.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

Dialog::Dialog() : Tree()
{
	EndState = 0;
}

Dialog::~Dialog()
{

}

void Dialog::GetEvent(Event& event)
{
	string OperationCodes = "+-&/qam";
	string Str;
	string Parameter;
	char Code;
	cout << "������� ��� ��������\n\n";
	cout << "m �����_����� - ������� ������ �� ���������� ���������� ���������\n";
	cout << "+ - �������� ������� � ������\n";
	cout << "- - ������� ������� �� ������\n";
	cout << "s - ����� ���������� �� ��������� ������\n";
	cout << "z - ����� ���������� � ������� ��������\n";
	cout << "q - ����� ������\n\n";
	cout << "> ";
	getline(cin, Str);
	Code = Str[0];
	if (OperationCodes.find(Code) >= 0)
	{
		event.what = evMessage;
		switch (Code)
		{
		case 'm':
		{
			event.command = cmMake;
			break;
		}
		case '+':
		{
			event.command = cmAdd;
			break;
		}
		case '-':
		{
			event.command = cmDel;
			break;
		}
		case 's':
		{
			event.command = cmShow;
			break;
		}
		case 'z':
		{
			event.command = cmAge;
			break;
		}
		case 'q':
		{
			event.command = cmQuit;
			break;
		}
		default:
		{
			cout << "\n�������� �� ���������!\n\n";
		}
		}
	}
	if (Str.length() > 1)
	{
		Parameter = Str.substr(1, Str.length() - 1);
		int A = atoi(Parameter.c_str());
		if (A < 0)
		{
			cout << "\n����� ��������� � ������ �� ����� ���� �������������\n\n";
			event.what = evNothing;
		}
		else
		{
			event.parameter = A;
		}
	}
	else
	{
		if (Str.length() == 0)
		{
			event.what = evNothing;
		}
	}
}

int Dialog::Execute()
{
	Event event;
	do
	{
		EndState = 0;
		GetEvent(event);		// ��������� �������
		HandleEvent(event);		// ��������� �������
	} while (!Valid());
	return EndState;
}

int Dialog::Valid()
{
	if (EndState == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void Dialog::ClearEvent(Event& event)
{
	event.what = evNothing;
}

void Dialog::EndExec()
{
	cout << "\n����� �� ���������...\n\n";
	EndState = 1;
}

void Dialog::HandleEvent(Event& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:					// �������� ������
		{
			if (event.parameter > 0)
			{
				Size = event.parameter;
				Beg = new Object * [Size];
				for (int i = 0; i < Size; i++)
				{
					Beg[i] = nullptr;
				}
				ClearEvent(event);
				cout << endl;
			}
			else
			{
				cout << "\n�� �� ����� ���������� ���������! ������� ��� �������� � ������������ � �������� m �����_�����\n\n";
			}
			break;
		}
		case cmAdd:						// ���������� �������� � ������
		{
			Add();
			ClearEvent(event);
			break;
		}
		case cmDel:						// �������� �������� �� ������
		{
			Del();
			ClearEvent(event);
			break;
		}
		case cmShow:					// ����� ��������� ������
		{
			Show();
			ClearEvent(event);
			break;
		}
		case cmAge:					// ����� �������� ������ �� ������
		{
			Age();
			ClearEvent(event);
			break;
		}
		case cmQuit:					// ����� �� ���������
		{
			EndExec();
			ClearEvent(event);
			break;
		}
		}
	}
}