#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"error.h"
using namespace std;
//将对象用作异常类型
#include<cmath>
double hmean(double a,double b);
double gmean(double a,double b);

int main()
{
	double x,y,z;
	cout << "Enter two numbers: ";
	while(cin >> x >> y)
	{
		try{
			z = hmean(x,y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x,y) << endl;
			cout << "Enter next a set of numbers<q to quit>: ";
		}

		catch(bad_hmean & bg)
		{
			bg.mesg();
			cout << "Try again.\n";
			continue;
		}
		catch(bad_gmean & hg)
		{
			cout << hg.mesg();
			cout << "Values used: " << hg.v1 << ", "
				<< hg.v2 << endl;
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}

	cout << "Bye.\n";
	return 0;
}
double hmean(double a,double b)
{
	if(a == -b)
		throw bad_hmean(a,b);
	return 2.0 * a * b / (a + b);
}
double gmean(double a,double b)
{
	if(a < 0 || b < 0)
		throw bad_gmean(a,b);
	return sqrt(a*b);
}


//异常机制：throw try catch
#if 0 
double hmean(double a,double b);
int main()
{
	double x,y,z;
	cout << "Enter two numbers: ";
	while(cin >> x >> y)
	{
		try{
			z = hmean(x,y);
		}
		catch(const char * s)
		{
			cout << s << endl;
			cout << "Enter a new pair of numbers: ";
			continue;
		}
		cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << endl;
		cout << "Enter next set of numbers<q to quit>: ";
	}
	cout << "Bye.\n";
	return 0;
}

double hmean(double a,double b)
{
	if(a == -b)
	{
		throw "bad hmean() arguments: a = -b not allowed";
	}
	return 2.0 * a * b / (a + b);
}
#endif
#if 0
//返回错误码
#include<cfloat>

bool hmean(double a, double b, double * ans);
int main()
{
	double x,y,z;
	cout << "Enter two numbers: ";
	while(cin >> x >> y)
	{
		if(hmean(x,y,&z))
			cout << "Harmonic mean of " << x << " and "
			<< y << " is " << z << endl;
		else
			cout << "One value should not be the negtive "
			<< "of teh other - try again.\n";
		cout << "Enter next set of numbers<q to quit>: ";
	}

	cout << "Bye.\n";
	return 0;
}

bool hmean(double a,double b,double * ans)
{
	if(a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}

//异常终止

#include<cstdlib>
double hmean(double a,double b);

int main()
{
	double x,y,z;
	cout << "Enter two numbers: ";
	while(cin >> x >> y)
	{
		z = hmean(x,y);
		cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << endl;
		cout << "Enter next set of numbers<q to quit>: ";
	}
	cout << "Bye.\n";
	return 0;
}

double hmean(double a, double b)
{
	if(a == -b)
	{
		cout << "untenable arguments to hmean()\n";
		abort();
	}
	return 2.0 * a * b / (a + b);
}
#endif