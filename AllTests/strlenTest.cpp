#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(void)
{
	char *s = new char[22];
	for (int j = 0; j < 5; j++) {
		s[j] = 'b';
	}
	cout << strlen(s) << '\n';
	delete();
	return 0;
}