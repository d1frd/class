#pragma once

enum Events
{
	evNothing = 0,
	evMessage = 100
};

enum Commands
{
	cmAdd = 1,
	cmDel,
	cmGet,
	cmShow,
	cmAge,
	cmMake,
	cmQuit = 101
};

struct Event
{
	int what;				// ��� �������
	union
	{
		int command;		// ��� �������
		struct
		{
			int message;	// ���������
			int parameter;			// �������� �������
		};
	};
};
