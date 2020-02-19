#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//将模板用作参数
template<template<typename T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {}
	bool push(int a,double b) { return s1.push(a) && s2.push(b); }
	bool pop(int & a,double & b) { return s1.pop(a) && s2.pop(b); }
};

int main()
{
	Crab<Stack> nebula;
	int ni;
	double nb;
	cout << "Enter int double paris,such as 4 3.5 (0 0 to end):\n";
	while(cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if(!nebula.push(ni,nb))
			break;
	}

	while(nebula.pop(ni,nb))
		cout << ni << ", " << nb << endl;
	cout << "Done.\n";
	return 0;
}


//指针栈
#if 0
#include<cstdlib>
#include<ctime>
using namespace std;

const int Num = 10;
int main()
{
	srand(time(0));
	cout << "Enter stack size: ";
	int stacksize;
	cin >> stacksize;
	Stack<const char *> st;

	const char * in[Num] = {
		" 1: Hank Gilgamesh"," 2: Kili Ishtar",
		" 3: Betty Rocker", " 4: Ian Flagranti",
		" 5: Wolfgang", " 6: Portia",
		" 7: Joy"," 8: Xaverie",
		" 9: Juan"," 10: Misha"
	     };
	const char * out[Num];

	int processed = 0;
	int nextin = 0;
	while(processed < Num)
	{
		if(st.isempty())
			st.push(in[nextin++]);
		else if(st.isfull())
			st.pop(out[processed++]);
		else if(rand()%2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for(int i = 0; i < Num; i++)
		cout << out[i] << endl;
	cout << "Bye\n";
	return 0;
}
#endif
//string对象的栈
#if 0
int main()
{
	Stack<string> st;
	char ch;
	string po;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO, or Q to quit.\n";
	while(cin >> ch && toupper(ch) != 'Q')
	{
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch(ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if(st.isfull())
				cout << "stack already full.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if(st.isempty())
				cout << "stack already empty.\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " popped.\n";
			}
			break;
		}
		cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO, or Q to quit.\n";
	}
	getchar();
	cout << "Bye\n";
	return 0;
}
#endif