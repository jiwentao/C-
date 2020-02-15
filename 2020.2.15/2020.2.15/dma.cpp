#define _CRT_SECURE_NO_WARNINGS
#include"dma.h"
#include<cstring>


baseDMA::baseDMA(const char * l,int r)
{
	lable = new char[strlen(l) + 1];
	strcpy(lable,l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
	lable = new char[strlen(rs.lable) + 1];
	strcpy(lable,rs.lable);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete [] lable;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if(this == &rs)
		return *this;
	delete [] lable;
	lable = new char[strlen(rs.lable)+1];
	strcpy(lable,rs.lable);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream & os,const baseDMA & rs)
{
	os << "Lable: " << rs.lable << endl;
	os << "Rating: " << rs.rating << endl;
	return os;
}

//派生类一
lackDMA::lackDMA(const char * c,const char * l,int r)
	:baseDMA(l,r)
{
	strncpy(color,c,39);
	color[39] = '\0';
}

lackDMA::lackDMA(const char * c,const baseDMA & rs)
	:baseDMA(rs)
{
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1] = '\0';
}

std::ostream & operator<<(std::ostream & os,const lackDMA & rs)
{
	os << (const baseDMA &)rs;
	os << "Color: " << rs.color << endl;
	return os;
}

//派生类二
hasDMA::hasDMA(const char * s, const char * l,int r)
	:baseDMA(l,r)
{
	style = new char[strlen(s)+1];
	strcpy(style,s);
}

hasDMA::hasDMA(const char * s,const baseDMA & rs)
	: baseDMA(rs)
{
	style = new char[strlen(s)+1];
	strcpy(style,s);
}

//派生类的复制构造函数只能访问自己的数据，
//因此需要调用基类的复制构造来处理共享的数据
hasDMA::hasDMA(const hasDMA & hs)
	: baseDMA(hs)  //此时用的是基类引用可指向派生类型
{
	style = new char[strlen(hs.style)+1];
	strcpy(style,hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

//派生类赋值运算符重载需要调用基类赋值运算符重载
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if(this == &hs)
		return *this;
	baseDMA::operator=(hs);  //赋值公共数据
	delete [] style;
	style = new char [strlen(hs.style)+1];
	strcpy(style,hs.style);
	return *this;
}

std::ostream & operator<<(std::ostream & os,const hasDMA & rs)
{
	os << (const baseDMA &)rs; //派生类使用基类友元时需强制类型转换
	os << "Style: " << rs.style << endl;
	return os;
}