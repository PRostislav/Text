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
			cout << "1 - Ввести выражение заново\n"; 
		}
		else {
			cout << "1 - Ввести выражение\n";
		}
		cout<<"2 - Вычислить\n";
		cout << "3 - Выход\n";
		cin>>p;
		cout << endl;
		switch (p)
		{
		case 1:
		{
			cout << "Введите выражение" << endl;
			cin >> st;
			cout << endl;
			flag = true;
			break;
		}
		case 2:
		{
			if (flag) {
				TParser infin(st);
				cout << "\nРезультат выражения: " << infin.CalcP() << '\0' << "\n";
				break;
			}
			else {
				cout << "Вы еще не ввели выражение!" << endl;
				break;
			}
		}
		case 3: {return 0;
		}
		}
	}
	return 0;
}
	 