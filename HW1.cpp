#include <iostream>
//#include <malloc.h>
using namespace std;


/*

从键盘输入R行C列二维整型数组，找出每一行的次最大值并显示出来。要求：

（1）R和C为符号常量；

（2）二维数组是动态申请生成的；

（3）每一行的次最大值是利用单独的函数调用获得的；

（4）对数组元素的访问以及函数参数声明等都是利用指针实现的。

*/

//by yuxiang in September, 2019
const int R = 3;
const int C = 8;

int findSubMax(int *a) {
	bool allEqual = true;
	for (int i = 0; i < C; i++) 
	{
		if (*(a + i)!= *a) 
		{
			allEqual = false;
			break;
		}
	}
	if (allEqual) 
	{
		cout << "all numbers are equal, submax cannot be found" << "\n";
		cout << "please type again!" << "\n";
		return 66;
	}
	
	int max = *a;
	int submax = *a;
	for (int i = 0; i < C; i++) 
	{
		if (max < *(a + i)) 
			max = *(a + i);
	}
	
	for (int i = 0; i < C; i++) 
	{
		if (submax < *(a + i) && *(a + i) != max) 
			submax = *(a + i);
	}
	return submax;
}

//test findSubMax
/*
int main() {
	int b[C] = {1,2,9,4,5,0,0,0};
	int x = findSubMax(b);
	cout << x << '\n';
	return 0;
}
*/


int main() 
{
	int **a = (int **)malloc(sizeof(int *) * R);

	for (int i = 0; i < R; i++) 
		*(a + i) = (int *)malloc(sizeof(int) * C);
    int *result = new int[R];

    /*
    Type in R * C integers from keyboard, line by line.
    If you type in C same integers in a line,
    you will be asked to type again since the submax does not exist.
    I used "goto" syntax to implement this specific part.

    The shortcoming is that you must not type in "66" because it is 
    used as a special signal that the "all equal" case appears.
    */

	for (int i = 0; i < R; i++) 
	{
		cout << "please type in " << C << " integers:"<< '\n';
	type:
		for (int j = 0; j < C; j++) 
			cin >> *(*(a + i) + j);
		*(result + i) = findSubMax(*(a + i));
		if (*(result + i) == 66) 
			goto type;
	}

	//Print the result.
	cout << "result:" << '\n';
	for (int i = 0; i < R; i++)
		cout << *(result + i) << '\n';

	return 0;
}




