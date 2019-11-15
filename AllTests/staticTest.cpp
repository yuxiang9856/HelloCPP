#include <iostream>

using namespace std;

int main() {
	static int mind[10];
	cout << mind[9] << '\n';
	mind[9] = 999;
	cout << mind[9] << '\n';
	return 0;
}

//output:
//0
//999