#ifndef _BRASS_H_
#define _BRASS_H_

#include<string>
using namespace std;

class Brass
{
private:
	string fullname;
	long acctNum;
	double balance;
public:
	Brass(const string & fn = "Nullbody",long an = -1,double ba = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);//�鷽��
	double Balance() const;
	virtual void ViewAcct() const;//�鷽��
	virtual ~Brass() {} //��������������ִ���κβ���
};

class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const string & s = "Nullbody",long an = -1,
		double bal = 0.0,double ml = 500,double r = 0.11125);
	BrassPlus(const Brass & ba,double ml = 500,double r = 0.11125);
	//�������������¶������ķ�����ʹ���鷽����ʵ�ֶ�̬�̳�
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif