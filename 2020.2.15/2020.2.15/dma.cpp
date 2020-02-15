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

//������һ
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

//�������
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

//������ĸ��ƹ��캯��ֻ�ܷ����Լ������ݣ�
//�����Ҫ���û���ĸ��ƹ����������������
hasDMA::hasDMA(const hasDMA & hs)
	: baseDMA(hs)  //��ʱ�õ��ǻ������ÿ�ָ����������
{
	style = new char[strlen(hs.style)+1];
	strcpy(style,hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

//�����ำֵ�����������Ҫ���û��ำֵ���������
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if(this == &hs)
		return *this;
	baseDMA::operator=(hs);  //��ֵ��������
	delete [] style;
	style = new char [strlen(hs.style)+1];
	strcpy(style,hs.style);
	return *this;
}

std::ostream & operator<<(std::ostream & os,const hasDMA & rs)
{
	os << (const baseDMA &)rs; //������ʹ�û�����Ԫʱ��ǿ������ת��
	os << "Style: " << rs.style << endl;
	return os;
}