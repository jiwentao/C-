#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"brass.h"
const int CLIENTS = 4;
//通过虚方法特性
int main()
{
	Brass * p_clients[CLIENTS];
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	for(int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		getline(cin,temp);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening balance: $";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or "
			<< "2 for BrassPlus Account: ";
		while(cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";
		if(kind == '1')
			p_clients[i] = new Brass(temp,tempnum,tempbal);
		else
		{
			double tmax,trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cout << "Enter the interest rate "
				<< "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp,tempnum,tempbal,
				                               tmax,trate);
		}
		while(cin.get() != '\n')
			continue;
	}
	cout << endl;
	for(int i = 0; i < CLIENTS; i++)//体现多态性
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for(int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	cout << "Done!\n";
	return 0;
}

#if 0
//通过对象来调用方法
int main()
{
	Brass Piggy("Pocelot Pigg",381299,4000.00);
	BrassPlus Hoggy("Horatio Hogg",382288,3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Deposing $1000 into the Hoggy Account:\n";
	Hoggy.Deposit(1000.00);
	cout << "New balance: $" << Hoggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Piggy account:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg account balance: $" << Piggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Hoggy account:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
	return 0;
}
#endif