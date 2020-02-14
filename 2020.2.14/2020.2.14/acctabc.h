#ifndef _ACCTABC_H_
#define _ACCTABC_H_

#include<iostream>
#include<string>
using namespace std;
//抽象基类
class AcctABC
{
private:
	string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting    //将格式化处理为保护成员函数
	{
		ios_base::fmtflags flag;
		streamsize pr;
	};
	const string & FullName() const { return fullName; }
	long AcctNum() const { return acctNum; }
	Formatting SetFormat() const;
	void Restore(Formatting & f) const;
public:
	AcctABC(const string & fn = "Nullbody",long an = -1,double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;//纯虚函数
	double Balance() const { return balance; }
	virtual void ViewAcct() const = 0;//纯虚函数
	virtual ~AcctABC() {};//虚析构函数
};
//派生类一 -- Brass
class Brass : public AcctABC
{
public:
	Brass(const string & fn = "Nullbody",long an = -1,
		double bal = 0.0) : AcctABC(fn,an,bal) {}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {} //虚函数
};
//派生类二 -- BrassPlus
class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const string & fn = "Nullname",long an = -1,double bal = 0.0,
		     double ml = 500,double r = 0.10);
	BrassPlus(const Brass & ba,double ml = 500,double r = 0.10);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};
#endif