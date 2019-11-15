#include <iostream>
using namespace std;

int main()
{
	int dt1 = 10, dt2 = 20, dt3 = 30;
	int * const p2 = &dt2; //指针是constant（p2）
	const int * p3 = &dt3; //int * 是 constant（dt3），但是p3可以指别的东西
	//* p2 = 1000;//correct
	//p2 = &dt1;  //error,cannot be changed anymore
	p3 = &dt1;  //correct
	//* p3 = 1000;//error
	cout << "dt1 = " << dt1 << '\n';
	cout << "dt2 = " << dt2 << '\n';
	cout << "dt3 = " << dt3 << '\n';
	//cout << "* p2 = " << * p2 << '\n';
	cout << "* p3 = " << * p3 << '\n';
	return 0;
}
