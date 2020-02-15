#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"dma.h"
using namespace std;

int main()
{
	baseDMA shirt("Port",8);
	lackDMA balloon("red","Bli",4);
	hasDMA map("Mer","Buf",5);
	cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
	cout << "Diplaying lackDMA object:\n";
	cout << balloon << endl;
	cout << "Displaying hasDMA object:\n";
	cout << map << endl;

	lackDMA balloon2(balloon);
	cout << "Result of lackDMA copy:\n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "Result of hasDMA assignment:\n";
	cout << map2 << endl;
	return 0;
}