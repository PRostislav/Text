// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Parser_Stack.h"
#include <iostream>
#include <locale.h>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	char st[100];
	int p;
	bool flag = false;
	for (;;)
	{
		if (flag){
			cout << "1 - ������ ��������� ������\n"; 
		}
		else {
			cout << "1 - ������ ���������\n";
		}
		cout<<"2 - ���������\n";
		cout << "3 - �����\n";
		cin>>p;
		cout << endl;
		switch (p)
		{
		case 1:
		{
			cout << "������� ���������" << endl;
			cin >> st;
			cout << endl;
			flag = true;
			break;
		}
		case 2:
		{
			if (flag) {
				TParser infin(st);
				cout << "\n��������� ���������: " << infin.CalcP() << '\0' << "\n";
				break;
			}
			else {
				cout << "�� ��� �� ����� ���������!" << endl;
				break;
			}
		}
		case 3: {return 0;
		}
		}
	}
	return 0;
}
	 