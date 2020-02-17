#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<iostream>
#include<string>
#include<valarray>
using namespace std;

//使用私有继承实现代码重用
class Student : private string,private valarray<double>
{
	//两个基类（多重继承）
private:
	typedef valarray<double> ArrayDb;
	ostream & arr_out(ostream & os) const;
public:
	Student() : string("Null Student"),ArrayDb() {}
	explicit Student(const string & s) : string(s),ArrayDb() {}
	explicit Student(int n) : string("Nully"),ArrayDb(n) {}
	Student(const string & s,int n) : string(s),ArrayDb(n) {}
	Student(const string & s,const ArrayDb & a) : string(s),ArrayDb(a) {}
	Student(const string & s,const double * pd,int n)
		: string(s),ArrayDb(pd,n) {}
	~Student() {}
	double Average() const;
	double & operator[](int i);
	double operator[](int i) const;
	const string & Name() const;

	friend istream & operator>>(istream & is,Student & stu);
	friend istream & getline(istream & is,Student & stu);
	friend ostream & operator<<(ostream & os,const Student & stu);
};

//使用包含实现代码重用
#if 0
class Student
{
private:
	typedef valarray<double> ArrayDb;
	string name;  //包含
	ArrayDb scores;  //包含
	ostream & arr_out(ostream & os) const;
public:
	Student() : name("Null Student"),scores() {}
	//关键字explicit不允许隐式类型转换
	explicit Student(const string & s) : name(s),scores() {}
	explicit Student(int n) : name("Nully"),scores(n) {}
	Student(const string & s,int n) : name(s),scores(n) {}
	Student(const string & s,const ArrayDb & a)
		: name(s),scores(a) {}
	Student(const string & s,const double * pd,int n)
		: name(s),scores(pd,n) {}
	~Student() {}
	double Average() const;
	const string & Name() const;
	double & operator[](int i);
	double operator[](int i) const;

	friend istream & operator>>(istream & is,Student & stu);
	friend istream & getline(istream & is,Student & stu);
	friend ostream & operator<<(ostream & os,const Student & stu);
};
#endif
#endif