#define _CRT_SECURE_NO_WARNINGS
#include"work.h"
#include<iostream>
using namespace std;

const int SIZE = 5;
int main()
{
	Worker * lolas[SIZE];

	int ct;
	for(ct = 0;ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while(strchr("wstq",choice) == NULL) //只是提醒用户输入正确的选择
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if(choice == 'q')
			break;
		switch(choice)
		{
		case 'w': 
			lolas[ct] = new Waiter;
			break;
		case 's':
			lolas[ct] = new Singer;
			break;
		case 't':
			lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for(i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for(i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";
	return 0;
}

//普通公有继承
#if 0
const int LIM = 4;
int main()
{
	Waiter bob("Bob Apple",314L,5);
	Singer bev("Bev",522L,3);
	Waiter w_temp;
	Singer s_temp;

	Worker * pw[LIM] = {&bob,&bev,&w_temp,&s_temp};

	int i;
	for(i = 2; i < LIM; i++)
		pw[i]->Set();
	for(i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		cout << endl;
	}
	return 0;
}
#endif