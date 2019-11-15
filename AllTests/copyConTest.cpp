#include <iostream>
using namespace std;


class b
{
	int i;
public:
	b(){cout << "b\n"; i = 10;}
	b(b& x){i = x.i; cout<<"copy\n";}
	int geti() {return i;}
	~b() {cout<<"destructor\n";}
};

int ex(b b){return b.geti()*b.geti();}
int main()
{
	b bb;
	cout <<ex(bb)<<'\n';
	return 0;
}
