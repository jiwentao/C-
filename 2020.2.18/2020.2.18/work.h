#ifndef _WORK_H_
#define _WORK_H_

#include<string>
//多重公有继承
class Worker
{
private:
	std::string fullname;
	long id;
protected: //new
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("no one"),id(0L) {}
	Worker(const std::string & s,long n) 
		: fullname(s),id(n) {}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter : virtual public Worker  //虚基类
{
private:
	int panache;
protected:  //new
	void Data() const;
	void Get();
public:
	Waiter() : Worker(),panache(0) {}
	Waiter(const std::string & s,long n, int p = 0)
		: Worker(s,n),panache(p) {}
	Waiter(const Worker & wk,int p = 0) : Worker(wk),panache(p) {}
	void Set();
	void Show() const;
};

class Singer : virtual public Worker  //虚基类
{
protected:
	enum {other,alto,contralto,soprano,
	                 bass,baritone,tenor};
	enum{Vtypes = 7};
	void Data() const;
	void Get();
private:
	static char * pv[Vtypes];
	int voice;
public:
	Singer() : Worker(),voice(other) {}
	Singer(const std::string & s,long n,int v = other)
		: Worker(s,n),voice(v) {}
	Singer(const Worker & wk,int v = other) : Worker(wk),voice(v) {}
	void Set();
	void Show() const;
};

class SingingWaiter : public Singer,public Waiter  //多重继承
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string & s,long n,int p = 0,int v = other)
		: Worker(s,n),Waiter(s,n,p),Singer(s,n,v) {}
	SingingWaiter(const Worker & wk,int p = 0,int v = other)
		: Worker(wk),Waiter(wk,p),Singer(wk,v) {}
	SingingWaiter(const Waiter & wt,int v = other)
		: Worker(wt),Waiter(wt),Singer(wt,v) {}
	SingingWaiter(const Singer & wt,int p = 0)
		: Worker(wt),Waiter(wt,p),Singer(wt) {}
	void Set();
	void Show() const;
};
//普通公有继承
#if 0
class Worker
{
private:
	std::string fullname;
	long id;
public:
	Worker() : fullname("no one"),id(0L) {}
	Worker(const std::string & fn,long n) : fullname(fn),id(n) {}
	virtual ~Worker() = 0; //纯虚方法--说明该类为抽象基类
	virtual void Set();
	virtual void Show() const;
};

class Waiter : public Worker
{
private:
	int panache;
public:
	Waiter() : Worker(),panache(0) {}
	Waiter(const std::string & fn,long n,int pa)
		: Worker(fn,n),panache(pa) {}
	Waiter(const Worker & wk,int pa) : Worker(wk),panache(pa) {}
	void Set();
	void Show() const;
};

class Singer : public Worker
{
protected:
	enum {other,alto,contralto,soprano,bass,baritone,tenor};
	enum {Vtypes = 7};
private:
	static char *pv[Vtypes];//静态成员变量
	int voice;
public:
	Singer() : Worker(),voice(other) {}
	Singer(const std::string & fn,long n,int v = other)
		: Worker(fn,n),voice(v) {}
	Singer(const Worker & wk,int v = other) : Worker(wk),voice(v) {}
	void Set();
	void Show() const;
};
#endif
#endif