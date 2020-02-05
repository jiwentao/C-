#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<new>
/* new和定位new的用法 */
using namespace std;
const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
	double * pd1,* pd2;
	int i;
	cout << "Calling new and placement new:\n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N];
	for(i = 0;i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "Memory address:\n" << "  heap:" << pd1
		<< "  static:" << (void *)buffer << endl;//（void*）类型不同，需强制类型转换
	cout << "Memory content:\n";
	for(i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";" ;
		cout << pd2[i] << " at " << &pd2[i] << endl ;
	}
	
	cout << "\nCalling new and palcement new a second time:\n";
	double * pd3,* pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];//会覆盖掉原来的数据
	for(i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "Memory contents:\n";
	for(i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << ";";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

	cout << "\nCalling new and placement new a third time:\n";
	delete [] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for(i = 0;i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "Memory contents:\n";
	for(i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete [] pd1;
	delete [] pd3;//buffer是静态区，故pd2,pd4不能用delete释放；
	return 0;
}