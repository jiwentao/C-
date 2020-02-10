#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"tabtenn.h"

int main()
{
	TableTennisPlayer player1("Tara","Boomdea",false);
	RatedPlayer rplayer1(1140,"Mallory","Duck",true);
	rplayer1.Name();
	if(rplayer1.Hastable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	player1.Name();
	if(player1.Hastable())
		cout << ": has a table.";
	else
		cout << ": hasn't a table.\n";
	cout << "Name: ";
	rplayer1.Name();
	cout << "; Rating: " << rplayer1.Rating() << endl;	

	RatedPlayer rplayer2(1212,player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << "; Rating: " << rplayer2.Rating() << endl;
	return 0;
}