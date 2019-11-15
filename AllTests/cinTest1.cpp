#include <iostream>
using namespace std;

int main() {
	int num[10];
	int i = 0;
	while (cin >> num[i]) {
		cout << num[i] << " ";
		i++;
	}
	return 0;
}