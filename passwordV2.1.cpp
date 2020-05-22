#include "pch.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <conio.h>

using namespace std;

/*Enter the password with *, 
you can try up to NumAttempt times*/
bool CheckPassWord(string password)
{
	bool judge = false;
	int i = 0;
	int times = 1;
	string s;
	char ch;
	char pw[50];
	while (times <= NumAttempt)
	{
		i = 0;
		while ((ch = _getch()) != '\r')
		{
			if (ch == '\b' && i > 0)//backspace
			{
				printf("\b \b");
				i--;
			}
			else
			{
				pw[i++] = ch;
				cout << '*';
			}
		}
		pw[i] = '\0';
		cout << endl;
		if (password.compare(pw) != 0)
		{
			if (times == NumAttempt)
				cout << "Wrong password, exit！" << endl << endl;
			else
				cout << "Wrong password,you can try for another " << (NumAttempt - times) << " times:\n";
			times++;
		}
		else
		{
			cout << "Correct password！Authorised！" << endl << endl;
			judge = true;
			return judge;
		}
	}
	if (times == (NumAttempt+1))
		return judge;
	return judge;
}

int main()
{
	string password = "VGakki520521"; //Original password
	cout << "Password up to 50 digits.\nPlease enter 6 digits for password（VGakki520521)：\n";
	if (CheckPassWord(password) != true)
		return 0;
	return 1;
}
