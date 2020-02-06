#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stock.h"

const int STKS = 4;
int main()
{
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	    };

	std::cout << "Stock holdings:\n";
	int st;
	for(st = 0; st < STKS; st++)
	{
		stocks[st].show();
	}

	const Stock * top = &stocks[0];
	for(st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);
	std::cout << "\nMost valuable holding:\n";
	top->show();
	return 0;
}
#if 0
int main()
{
	using std::cout;
	cout << "Using constructors to create new objects\n";
	Stock stock1("NaanoSmart", 12, 20.0);
	stock1.show();
	Stock stock2 = Stock("Boffo Object", 2, 2.0);
	//此时是初始化，可能会创建临时对象，也可能不会
	stock2.show();

	cout << "Assigning stock1 to stock2:\n";
	stock2 = stock1;
	cout << "Listing stock1 and stock2:\n";
	stock1.show();
	stock2.show();

	cout << "Using a constructor to reset an object\n";
	stock1 = Stock("Niffy Foods", 10, 50.0);
	//此时对于stock1来说是赋值，在赋值前创建临时对象，调构造函数，之后调用析构
	cout << "Revised stock1:\n";
	stock1.show();
	cout << "Done\n";
	return 0;
}
#endif