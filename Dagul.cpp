//Data* (*p[1])(Data*)
#include <iostream>
using namespace std;
class Data
{
	int i;
public:
	Data()
	{
		i = 0;
	}

	int getI()
	{
		return i;
	}

	void setI(int j)
	{
		i = j;
	}
};

Data* f(Data* m)
{
	m->setI(90);
	return m;
}

int main()
{
	Data data1;   //Data object
	Data *n;      //Data object pointer n
	n = &data1;

	Data *q;      //Data object pointer q
	Data* (*p[1])(Data*);	//define "Data* (*p[1])(Data*)"
	p[0] = &f;    //let p[0] point to function f
	q = (*p[0])(n); //then call f...or you can say call *p[0]
    
	cout << q ->getI() << '\n'; //see what happens? by right it shuold show '90'

	return 0;

}