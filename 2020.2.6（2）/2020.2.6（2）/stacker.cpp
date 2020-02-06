#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stack.h"
#include<cctype>
using namespace std;

int main()
{
	Stack st;
	char ch;
	unsigned long po;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO,or Q to quit.\n";
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
			cout << "Enter a PO nuber to add: ";
			cin >> po;
			if(st.isfull())
				cout << "stack aleady full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if(st.isempty())
			{
				cout << "stack already empty\n";
			}
			else
			{
				st.pop(po);
				cout << "PO #" << po << " popped\n";
			}
			break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	
	cout << "Bye" << endl;

	return 0;
}