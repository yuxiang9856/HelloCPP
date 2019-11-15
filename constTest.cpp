#include <iostream>
using namespace std;
class A
{
public:
	A(int i) {cout << i;} //constructor
	//A(const A &aa) {cout << 999;} // copy constructor
    //operator int() {return ?;}//transformation function

};

class B
{
	A a;  //A a(3);
	const int x;
public:
	B(int i):x(i),a(3) {} //B(int i) {x = i;}
	void disp() {cout << "x:" << x << '\n';}
};
int main()
{
	B b(3);
	cout << '\n';
	b.disp();
	return 0;
}

//变换函数重载也可以给a赋值