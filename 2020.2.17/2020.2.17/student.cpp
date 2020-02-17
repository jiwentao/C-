#define _CRT_SECURE_NO_WARNINGS
#include"student.h"
//使用私有继承实现代码重用
double Student::Average() const
{
	if(ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

const string & Student::Name() const
{
	return (const string &) *this;
}

double & Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

ostream & Student::arr_out(ostream & os) const
{
	int i;
	int lim = ArrayDb::size();
	if(lim > 0)
	{
		for(i = 0;i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if(i % 5 == 4)
				os << endl;
		}
		if(i % 5 != 0)
			os << endl;
	}
	else
		os << " empty array ";
	return os;
}

istream & operator>>(istream & is,Student & stu)
{
	is >> (string &)stu;
	return is;
}
istream & getline(istream & is,Student & stu)
{
	getline(is,(string &)stu);
	return is;
}

ostream & operator<<(ostream & os,const Student & stu) 
{
	os << "Scores for " << (const string &)stu << endl;
	stu.arr_out(os);
	return os;
}
//使用包含实现代码重用
#if 0
double Student::Average() const
{
	if(scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}

const string & Student::Name() const
{
	return name;
}

double & Student::operator[](int i)
{
	return scores[i];
}

double Student::operator[](int i) const
{
	return scores[i];
}

ostream & Student::arr_out(ostream & os) const //私有辅助方法
{
	int i;
	int lim = scores.size();
	if(lim > 0)
	{
		for(i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
			if(i % 5 == 4)
				os << endl;
		}
		if(i % 5 != 0)
			os << endl;
	}
	else
		os << " empty array ";
	return os;
}

istream & operator>>(istream & is,Student & stu)
{
	is >> stu.name;
	return is;
}
istream & getline(istream & is, Student & stu)
{
	getline(is,stu.name);
	return is;
}

ostream & operator<<(ostream & os,const Student & stu)
{
	os << "Scores for " << stu.name << ":\n";
	stu.arr_out(os);
	return os;
}
#endif