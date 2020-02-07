#ifndef _MYTIME_H_
#define _MYTIME_H_
#include<iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h,int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0,int m = 0);
	//Time Sum(const Time & t) const;//1.普通意义的加法
	Time operator+(const Time & t) const;//2.加法运算的重载
	Time operator-(const Time & t) const;
	Time operator*(double n) const;
	//将定义位于类声明中的函数将自动成为内联函数
	friend Time operator*(double m,const Time & t)
	{
		return t * m;
	}//该友元函数为内联函数
	friend std::ostream & operator<<(std::ostream & os,const Time & t);
	//void Show() const;//未使用友元前
};

#endif