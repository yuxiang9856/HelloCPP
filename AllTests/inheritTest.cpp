#include <iostream>
using namespace std;
class cake
{
private:
	int i;
	static void bake(){cout << "burnt!!!\n";}
public:
	cake(){i = 0;}
	void disp(){cout << i << '\n';}	
};

class cupcake: public cake
{
public:
	cupcake(){}
	void bake(cake::bake();)
	void disp() {cake::disp();}
};

int main()
{
	cake a;
	cupcake b;
	cout << "cake bake:\n";
	a.bake();
	
	cout << "cupcake bake:\n";
	b.bake();
	
	return 0;
}