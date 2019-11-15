#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class A
{
private:
	char *text;
	int i;
public:
	A(char t[], int j = 1)
	{
		text = t;
		i = j;
	}

	void disp() {
		cout << text << '\n';
		cout << i << '\n';
	}

}; 

int main()
{
	A a("sa");
	a.disp();
	return 0;
}