#include <iostream>
using namespace std;

/*
根据下列要求，编写完整程序。

设计一个类，用于对10元整型数组进行管理。要求：

（1）在定义对象时，能够为数组元素清0.

（2）定义成员函数input, 用于为数组元素输入数据。

（3）定义成员函数disp，用于显示数组的每个元素值。

（4）定义成员函数max，用于找出数组元素的最大值及其个数，其中最大值由函数值返回，个数由参数带回。

（5）定义成员函数find，用于找出数组中重复次数最多的数及其个数（可能存在多个），并显示出来。

（6）定义main函数，合理地调用上述每个函数。
*/


//By yuxiang in September, 2019

class dut 
{

	int *arr;

public:   
    //the contructor generates an array as [0,0,0,0,0,0,0,0,0,0]
	dut() 
	{ 
		arr = new int[10];
		for (int i = 0; i < 10; i++) 
			arr[i] = 0;			
	}

	~dut()
	{
		cout << "destructor" << '\n';
		delete arr;
	}

	//input method 1:

	/*
	In this method, after typing in 10 integers, you need to type in
	a random key (except "space","return" or any number keys)
	to jump out of the while loop.
	This is kind of stupid so you may find "method 2" more convenient.
	*/

	/*
	void input() {
		int i = 0;
		while (cin >> arr[i]) {
			i++;
		}
        
	}
	*/

    //input method 2:
	void input() 
	{
		for (int i = 0; i < 10; i++)
			cin >> arr[i];
	}
    
	void disp()
	{
		int i = 0;
		while (i < 10) 
		{
			cout << arr[i] << ' ';
			i++;
		}
		cout << '\n';
	}

	int max(int *count) 
	{
		int max = arr[0];
		for (int i = 0; i < 10; i++) 
		{
			if (max < arr[i]) 
				max = arr[i];
		}
	    *count = 0;
		for (int i = 0; i < 10; i++) 
		{
			if (max == arr[i]) 
				(*count)++;
		}
		return max;
	}

	void find() 
	{
		int ct[10] = {0,0,0,0,0,0,0,0,0,0};
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) 
			{
				if (arr[i] == arr[j]) 
					ct[i]++;
			}
		}
		int maxct = ct[0];
        
        //Find the integer that appears most often.
        //Use maxct to record how many times it appears.
        //Note that there might be multiple integers that meet the requirement.
		for (int i = 0; i < 10; i++) 
		{
			if (ct[i] >= maxct)
				maxct = ct[i];
		}

        //In case there are multiple integers, we need to go through the ct[] again.
		for (int i = 0; i < 10; i++) 
		{
			if (ct[i] == maxct) 
			{
				cout << "the number that appears most often is " << 
				    arr[i] << " and it appears "<< ct[i] <<" times."<< "\n";
			}
		} 

		 

	}


};




int main() 
{
	dut he;
	he.input();
	he.disp();
	
	int p[10] = {0,0,0,0,0,0,0,0,0,0};
	int max = he.max(p);
	cout << "the largest integer is " << max << "\n";
	he.find();

	return 0;
}







