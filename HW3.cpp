#include <iostream>
//#include <string> 
using namespace std;

/*
设计一个类，用于对字符串进行管理。要求：

（1）在定义对象时，能够确定字符串的最大长度并清空字符串。

（2）定义成员函数input, 用于从键盘为字符串输入数据。

（3）定义运算符重载函数，用于判断两个对象中的字符串是否相同。

（4）定义成员函数exchange，用于互换字符串中ASCII码最大和最小的字符（需考虑字符串中存在多个最大和最小字符的情况）。

（5）定义成员函数disp，用于显示字符串。

（6）定义main函数，合理地调用上述每个函数。

*/

//By Yuxiang in September, 2019

class myString {

	char *s;
	int len;

public:
	/*
	myString();
	myString(int len1);
	//~myString();
	void input();
	bool operator ==(myString str);
	void exchange();
	void disp();
	*/

	myString(int len1) 
	{
		//int,double....8个 
		//Dog, Animal,Node, class:

		//s = (char *)malloc(sizeof(char) * len1);
		s = new char[len1];
		len = len1;
	}

	~myString() 
	{
		cout << "destructor" << '\n';
		delete s;
    }

	void input() 
	{
		cout << "Please type in " << (len - 1) << " characters: ";
		for (int i = 0; i < len - 1; i++) 
		{
			cin >> s[i];
		}
	}

	bool operator ==(myString str) 
	{
		if (len != str.len) 
		{
			cout << "no" << '\n';
			return false;
		}
		for (int i = 0; i < len; i++) 
		{
			if (s[i] != str.s[i]) 
			{
				cout << "no" << '\n';
				return false;
			}
		}
        cout << "yes" << '\n';
		return true;
	}

	void exchange() 
	{
		char max = s[0];
		char min = s[0];
		for (int i = 0; i < len - 1; i++) 
		{
			if (max <= s[i])
				max = s[i];
			if (min >= s[i])
				min = s[i];
		}
		//By the way, if all characters in the string are the same,
		//then nothing will happen.
		for (int i = 0; i < len - 1; i++) 
		{
			if (s[i] == min) 
			{
				s[i] = max;
			} 
			else if (s[i] == max)
			{
				s[i] = min;
			}
		}
		cout << "After exchange the string becomes: ";
		int i =0;
		while (i < len - 1) 
		{
			cout << s[i];
			i++;
		}
		cout << '\n';
	}


	void disp() 
	{
		//cout << "The string is: " << s << '\n'; 
		int i =0;
		while (i < len - 1) 
		{
			cout << s[i];
			i++;
		}
		cout << '\n';
        
	}
	

};
/*

//Set the string length to 1 as default
myString::myString() {
	len = 2;
	s = new char[1];
}

myString::myString(int len1) {
	//s = (char *)malloc(sizeof(char) * len1);
	s = new char[len1];
	len = len1;
}


myString::~myString() {
	cout << "destructor" << '\n';
	delete s;
}

void myString::input() {
	cout << "Please type in " << (len - 1) << " characters: ";
	for (int i = 0; i < len - 1; i++) {
		cin >> s[i];
	}
}

bool myString::operator ==(myString str) {
	if (len != str.len) {
		cout << "no" << '\n';
		return false;
	}
	for (int i = 0; i < len; i++) {
		if (s[i] != str.s[i]) {
			cout << "no" << '\n';
			return false;
		}
	}
    cout << "yes" << '\n';
	return true;
}

void myString::exchange() {
	char max = s[0];
	char min = s[0];
	for (int i = 0; i < len - 1; i++) {
		if (max <= s[i]) {
			max = s[i];
		}
		if (min >= s[i]) {
			min = s[i];
		}
	}
	//By the way, if all characters in the string are the same,
	//then nothing will happen.
	for (int i = 0; i < len - 1; i++) {
		if (s[i] == min) {
			s[i] = max;
		} else if (s[i] == max) {
			s[i] = min;
		}
	}

	cout << "After exchange the string becomes: ";
	int i =0;
	while (i < len - 1) {
		cout << s[i];
		i++;
	}
	cout << '\n';
}

void myString::disp() {
	cout << "The string is: " << s << '\n'; 
	int i =0;
	while (i < len - 1) {
		cout << s[i];
		i++;
	}
		cout << '\n';
        
}

*/



int main() 
{
	myString a(8);
	myString b(8);
	myString c(7);

	a.input();
	b.input();
	c.input();
    
    cout << "myString a: ";
	a.disp();
	cout << "myString b: ";
	b.disp();
	cout << "myString c: ";
	c.disp();
	
    cout << "Do a and b have the same string? ";
	bool boolean2 = a == b;
	cout << "Do a and c have the same string? ";
	bool boolean3 = a == c;
	/*
    a.exchange();
    b.exchange();
    c.exchange();
    */ 
	return 0;
}



