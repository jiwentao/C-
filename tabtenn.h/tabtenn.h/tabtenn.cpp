#define _CRT_SECURE_NO_WARNINGS
#include"tabtenn.h"
#include<iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn,
	const string & ln,bool ht) : firstname(fn),
	lastname(ln),hasTable(ht) {}

void TableTennisPlayer::Name() const
{
	cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r,const string & fn,
	                     const string & ln,bool ht):TableTennisPlayer(fn,ln,ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r,TableTennisPlayer & tp)
	:TableTennisPlayer(tp),rating(r) {}