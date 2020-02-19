#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//模板的友元三：非约束模板友元函数
template<typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & i) : item(i) {}
	template<typename C,typename D> friend void show(C &,D &);
};

template<typename C,typename D> void show(C & c,D & d) //函数具体化时的友元
{
	cout << c.item << ", " << d.item << endl;
}

int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1, hfi2: ";
	show(hfi1,hfi2);
	cout << "hfdb, hfi2: ";
	show(hfdb,hfi2);
	return 0;
}

#if 0
//模板的友元二：约束模板友元函数（友元与类具体化时的类型相同）

//1.类定义前声明为模板函数
template<typename T> void counts();
template<typename T> void reports(T &);

template<typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT & i) : item(i) { ct++; }
	~HasFriendT() { ct--; }
	//2.在类中声明为友元
	friend void counts<TT>();
	friend void reports<>(HasFriendT<TT> &);
};

template<typename TT>
int HasFriendT<TT>::ct = 0;
//3.为友元提供模板定义
template<typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << ", ";
	cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template<typename T>
void reports(T & hf)
{
	cout << hf.item << endl;
}

int main()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
	cout << "counts<int>() output:\n";
	counts<int>();
	cout << "counts<double>() output:\n";
	counts<double>();
	return 0;
}
#endif
//模板的友元一：非模板友元
#if 0
template<typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) : item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts(); //所有模板类实例化的友元
	friend void reports(HasFriend<T> &); //模板类特定具体化的友元
};

template<typename T>
int HasFriend<T>::ct = 0;

void counts()
{
	cout << "int count: " << HasFriend<int>::ct << ", ";
	cout << "double count: " << HasFriend<double>::ct << endl;
}

void reports(HasFriend<int> & hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

void reports(HasFriend<double> & hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}
int main()
{
	cout << "No objects declared: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared: ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declared: ";
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
	return 0;
}
#endif