#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#if 0
int main()
{
	using namespace std;
	cout << "let us into C++ time.";
	cout << endl;
	cout << "you won't regret it!" << endl;
	return 0;
}
#endif
                        /* 转义序列 */
#if 0
int main()
{
	cout << "\aOperation \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\aYou entered "<< code << "...\n";
	cout << "\aCode verified! Proceed with Plan z3!\n";
	return 0;
}
#endif
                  /* 使用方法getline()和get()读取字符串 */
#if 0
int main()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	cin.getline(name,ArSize);//cin >> name;
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert,ArSize);//cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}

int main()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	//将两个类成员函数拼接起来，最后的get()是为了跨过换行符
	cin.get(name,ArSize).get();//cin >> name;
	cout << "Enter your favorite dessert:\n";
	cin.get(dessert,ArSize).get();//cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}
/*
    该代码问题在于当第一次输入为多个单词时，第二次输入就失效，
	原因是cin是以空白来确定字符串的结束位置,用cin.getline()和
	cin.get()可以解决这个问题  
*/
#endif

/////////////////////////string类///////////////////////
                /* string类与字符数组的比较 */
#if 0 
int main()
{
	char char1[20];
	char char2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "Enter a kind of feline: ";
	cin >> char1;
	cout << "Enter another kind of feline: ";
	cin >> str1;
	cout << "Here are some felines:\n";
	cout << char1 << " " << char2 << " " 
		 << str1 << " " << str2 
		 << endl;
	cout << "The third letter in " << char2 << " is "
		 << char2[2] << endl;
	cout << "The third letter in " << str2 << " is "
		 << str2[2] << endl;
	return 0;
}
/*
   结论：很多方面，使用string对象的方式与使用字符数组相同
   本例区别：可以将string对象声明为简单变量，而不是数组
*/

                /* string类的赋值、拼接和附加 */
int main()
{
	string s1 = "penguin";
	string s2, s3;

	cout << "You can assign one string object to another: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "You can assign a C-style string to a string object.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;
	cout << "You can concatenate strings: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "You can append strings.\n";
	s1 += s2;
	cout << "s1 += s2 yields s1 = " << s1 << endl;
	s2 += " for a day";
	cout << "s2 += \"for a day\" yield s2 = " << s2 << endl;

	return 0;
}
#endif
                     /* string类I/O */
int main()
{
	char charr[20];
	string str;

	cout << "Lenth of string in charr before input: "
		 << strlen(charr) << endl;
	//未初始化数组使用strlen时，其第一个空字符的位置是随机的，故该结果也是随机的
	cout << "Lenth of string str before input: "
		 << str.size() << endl;
	//未初始化的string对象的长度被自动设置为0
	cout << "Enter a line of text:\n";
	cin.getline(charr,20);
	cout << "You entered: " << charr << endl;
	cout << "Enter another line of text:\n";
	getline(cin, str);//不是类方法，是string类的一个友元函数
	//其没有指出字符串长度的参数，因为string类具有自动调整大小的功能
	cout << "You entered: " << str << endl;
	cout << "Lenth of string in charr after input: "
		 << strlen(charr) << endl;
	cout << "Lenth of string in str after input: "
		 << str.size() << endl;//string类中计算字符串大小str.size()

	return 0;
}