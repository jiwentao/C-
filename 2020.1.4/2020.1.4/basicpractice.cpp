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
                        /* ת������ */
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
                  /* ʹ�÷���getline()��get()��ȡ�ַ��� */
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
	//���������Ա����ƴ������������get()��Ϊ�˿�����з�
	cin.get(name,ArSize).get();//cin >> name;
	cout << "Enter your favorite dessert:\n";
	cin.get(dessert,ArSize).get();//cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}
/*
    �ô����������ڵ���һ������Ϊ�������ʱ���ڶ��������ʧЧ��
	ԭ����cin���Կհ���ȷ���ַ����Ľ���λ��,��cin.getline()��
	cin.get()���Խ���������  
*/
#endif

/////////////////////////string��///////////////////////
                /* string�����ַ�����ıȽ� */
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
   ���ۣ��ܶ෽�棬ʹ��string����ķ�ʽ��ʹ���ַ�������ͬ
   �������𣺿��Խ�string��������Ϊ�򵥱���������������
*/

                /* string��ĸ�ֵ��ƴ�Ӻ͸��� */
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
                     /* string��I/O */
int main()
{
	char charr[20];
	string str;

	cout << "Lenth of string in charr before input: "
		 << strlen(charr) << endl;
	//δ��ʼ������ʹ��strlenʱ�����һ�����ַ���λ��������ģ��ʸý��Ҳ�������
	cout << "Lenth of string str before input: "
		 << str.size() << endl;
	//δ��ʼ����string����ĳ��ȱ��Զ�����Ϊ0
	cout << "Enter a line of text:\n";
	cin.getline(charr,20);
	cout << "You entered: " << charr << endl;
	cout << "Enter another line of text:\n";
	getline(cin, str);//�����෽������string���һ����Ԫ����
	//��û��ָ���ַ������ȵĲ�������Ϊstring������Զ�������С�Ĺ���
	cout << "You entered: " << str << endl;
	cout << "Lenth of string in charr after input: "
		 << strlen(charr) << endl;
	cout << "Lenth of string in str after input: "
		 << str.size() << endl;//string���м����ַ�����Сstr.size()

	return 0;
}