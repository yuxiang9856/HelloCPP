#include<iostream>
using namespace std;
class Demo {
	int id;
public:
	Demo(int i) 
	{
		id = i;
		cout << id << " constructor" << endl;
	}
	Demo(const Demo &d)
	{
		cout << "copy constructor" << endl;
	}

	~Demo() 
	{
		cout << id << " destructor" << endl;
	}
};

int main() {
	Demo d5(5);
	Demo d4 = d5; //初始化，会调用复制构造函数
	return 0;
}


