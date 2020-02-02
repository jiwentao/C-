#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#if 0
              /* 内联函数 */
inline int Add(int left,int right)
{
	return left + right;
}
int main()
{
	int ret = 0;
	ret = Add(1,2);
	return 0;
}
//查看有无inline汇编代码的不同
#endif
 
                /* 引用 */
#if 0
//引用的声明和创建
int main()
{
	int rats = 101;
	int & rodents = rats;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;

	return 0;
}
#endif

#if 0
//将引用用于结构
struct free_throws
{
	string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft)
{
	cout << "Name: " << ft.name << '\n';
	cout << "  Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
	if(ft.attempts != 0)
	{
		ft.percent = 100.0f * float(ft.made)/float(ft.attempts);
	}
	else
		ft.percent = 0;
}

free_throws & accumulate(free_throws & target,const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}
int main()
{
	free_throws one = {"Ifelsa Branch", 13, 14};
	free_throws two = {"Andor Knott", 10, 16};
	free_throws three = {"Minnie Max", 7, 9};
	free_throws four = {"Whily Looper", 5, 9};
	free_throws five = {"Long Long", 6, 14};
	free_throws team = {"Throwgoods", 0, 0};
	free_throws dup;

	set_pc(one);
	display(one);
	accumulate(team,one);
	display(team);

	display(accumulate(team,two));
	accumulate(accumulate(team,three),four);
	display(team);

	dup = accumulate(team,five);
	cout << "Displaying team:\n";
	display(team);
	cout << "Displaying dup after assignment:\n";
	display(dup);
	set_pc(four);
	accumulate(dup,five) = four;
	cout << "Displaying dup after ill-advised assignment:\n";
	display(dup);
	return 0;
}
#endif

#if 0
//引用应用于类对象
string version1(const string & s1,const string & s2)
{
	string tem;
	tem = s2 + s1 + s2;
	return tem;
}

const string & version2(string & s1,const string & s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string & version3(string & s1,const string & s2)
{
	string tem;
	tem = s2 + s1 + s2;
	return tem;
}

int main()
{
	string input;
	string copy;
	string result;

	cout << "Enter a string: ";
	getline(cin,input);
	copy = input;
	cout << "Your string as entered: " << input << endl;
	result = version1(input, "***");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;
	
	result = version2(input, "###");
	cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
	
	cout << "Resetting original string.\n";
	input = copy;
	//result = version3(input,"@@@");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;
	return 0;
}
#endif

                      /* 函数重载 */
#if 0
unsigned long left(unsigned long num,unsigned ct);
char * left(const char * str,int n = 1);

int main()
{
	char * trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char * temp;

	for(i = 1; i < 10; i++)
	{
		cout << left(n,i) << endl;
		temp = left(trip,i);
		cout << temp << endl;
		delete [] temp;
	}

	return 0;
}

unsigned long left(unsigned long num,unsigned ct)
{
	unsigned digits = 1;
	unsigned n = num;
	if(ct == 0 || num == 0)
		return 0;
	while(n /= 10)
		digits++;
	if(digits > ct)
	{
		ct = digits - ct;
		while(ct--)
			num /= 10;
		return num;
	}
	else
		return num;
}

char * left(const char * str,int n)
{
	if(n < 0)
		n = 0;
	char * p = new char[n+1];
	int i;
	for(i = 0; i < n && str[i]; i++)
	{
		p[i] = str[i];
	}
	while(i <= n)
		p[i++] = '\0';
	return p;
}
#endif

                            /* 函数模板 */
#if 0
template <typename T>
void Swap(T &a, T &b)
{
	T tem;
	tem = a;
	a = b;
	b = tem;
}

int main()
{
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << "," << j << endl;
	cout << "Using compiler-generated int swapper:\n";
	Swap(i,j);
	cout << "Now i, j = " << i << "," << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << "," << y << endl;
	cout << "Using compiler-generated double swapper:\n";
	Swap(x,y);
	cout << "Now x, y = " << x << "," << y << ".\n";
    return 0;
}
#endif 

//函数模板重载
#if 0
template <typename T>
void Swap(T &a, T &b)
{
	T tem;
	tem = a;
	a = b;
	b = tem;
}
template <typename T>
void Swap(T * a, T * b,int n)
{
	T tem;
	for(int i = 0;i < n;i++)
	{
		tem = a[i];
		a[i] = b[i];
		b[i] = tem;
	}
}
const int Lim = 8;
void Show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for(int i = 4; i < Lim; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
int main()
{
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << "," << j << "\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i,j);
	cout << "Now i, j = " << i << "," << j << ".\n";

	int d1[Lim] = {0,7,0,4,1,7,7,6};
	int d2[Lim] = {0,7,2,0,1,9,6,9};
	cout << "Original arrays:\n";
	Show(d1);
	Show(d2);
	Swap(d1,d2,Lim);
	cout << "Swapped arrays:\n";
	Show(d1);
	Show(d2);
	return 0;
}
#endif

//显示具体化
template <typename T>
void Swap(T &a,T &b);

struct job
{
	char name[40];
	double salary;
	int floor;
};

template <> void Swap<job>(job &j1,job &j2);
void Show(job &j);

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	int i = 10,j = 20;
	cout << "i, j = " << i << "," << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i,j);
	cout << "Now i, j = " << i << "," << j << ".\n";

	job sue = {"Susan Yaffee", 73000.60, 7};
	job sidney = {"Sidney Taffee", 78060.72, 9};
	cout << "Before job swapping:\n";
	Show(sue);
	Show(sidney);
	Swap(sue,sidney);
	cout << "After job swapping:\n";
	Show(sue);
	Show(sidney);
	return 0;
}

template <typename T>
void Swap(T &a,T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap<job>(job &j1,job &j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job &j)
{
	cout << j.name << ": $" << j.salary << "on floor " << j.floor << endl;
}
//显示具体化优先于函数模板 