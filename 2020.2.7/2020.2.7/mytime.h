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
	//Time Sum(const Time & t) const;//1.��ͨ����ļӷ�
	Time operator+(const Time & t) const;//2.�ӷ����������
	Time operator-(const Time & t) const;
	Time operator*(double n) const;
	//������λ���������еĺ������Զ���Ϊ��������
	friend Time operator*(double m,const Time & t)
	{
		return t * m;
	}//����Ԫ����Ϊ��������
	friend std::ostream & operator<<(std::ostream & os,const Time & t);
	//void Show() const;//δʹ����Ԫǰ
};

#endif