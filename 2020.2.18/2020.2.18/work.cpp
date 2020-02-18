#define _CRT_SECURE_NO_WARNINGS
#include"work.h"
#include<iostream>
using namespace std;
//多重公有继承
Worker::~Worker() {}

void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin,fullname);
	cout << "Enter work's ID: ";
	cin >> id;
	while(cin.get() != '\n')
		continue;
}
////////////////////////////////////////////
void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}

void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while(cin.get() != '\n')
		continue;
}

///////////////////////////////////////////////////
char * Singer::pv[Singer::Vtypes] = {"other","alto","contralto","soprano",
                                          "bass","baritone","tenor"}; 
void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}

void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for(i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if(i % 4 == 3)
			cout << endl;
	}
	if(i % 4 != 0)
		cout << endl;
	cin >> voice;
	while(cin.get() != '\n')
		continue;
}

////////////////////////////////////////////
void SingingWaiter::Data() const
{
	Waiter::Data();
	Singer::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Category: singing waiter\n";
	Worker::Data();
	Data();
}
//普通公有继承
#if 0
//基类方法
Worker::~Worker() {}

void Worker::Set()
{
	cout << "Enter worker's name: ";
	getline(cin,fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while(cin.get() != '\n')
		continue;
}

void Worker::Show() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

//Waiter类方法
void Waiter::Set()
{
	Worker::Set();
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while(cin.get() != '\n')
		continue;
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Show();
	cout << "Panache rating: " << panache << endl;
}

//Singer类方法
char * Singer::pv[] = {"other","alto","contralto",
	"sooprano","bass","baritone","tenor"};

void Singer::Set()
{
	Worker::Set();
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for(i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if(i % 4 == 3)
			cout << endl;
	}
	if(i % 4 != 0)
		cout << endl;
	while(cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "Please enter a value >= 0 and < " << Vtypes << endl;

	while(cin.get() != '\n')
		continue;
}

void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}
#endif