#include <iostream>
#include <string.h>

using namespace std;

#define NUM 10
#define LEN 21

/*
定义一个类，用于对10个字符串进行管理。要求：

（1）在定义对象时，能够为字符串清空；

（2）定义变换构造函数，能够为（十个）字符串赋以给定的字符串；

（3）定义复制构造函数；

（4）定义成员函数，能够为字符串输入数据；

（5）定义成员函数，能够将字符串显示出来；

（6）定义成员函数，用于找出每个字符串中的最小值（ASCII码最小的字符）及其个数，最小值由函数值返回，个数由参数带回；

（7）定义成员函数，用于为字符串按从小到大顺序排序。

（8）定义main函数，合理地调用上述每个函数。
 */


/*
 *Below are three different ways to implement this interface, 
 *which I call "manyStrings".
 *They are class manyStringsV1, class manyStringsV2, and class manyStringsV2.
 *Each of they has a unique type of the member variable "head".
 *
 *In class manyStringsV1,we have a "char **head;",
 *in class manyStringsV2,we have a "char (*head)[LEN];",
 *and in class manyStringsV3,we have a "char *head[NUM];".
 *
 *default in main() is to call "manyStringsV3". 
 *But you can also change that into version1 or version2 :)
 */



class manyStringsV1
{
	char **head;

public:
	manyStringsV1() 
	{
		head = (char **)malloc(sizeof(char *) * NUM);
		for (int i = 0; i < NUM; i++) 
			*(head + i) = (char *)malloc(sizeof(char) * LEN);
	}
      
    //transformation constructor
	manyStringsV1(char **str)
	{
		head = (char **)malloc(sizeof(char *) * NUM);
		for (int i = 0; i < NUM; i++) 
			*(head + i) = (char *)malloc(sizeof(char) * LEN);

		for (int i = 0; i < NUM; i++)
			for (int j = 0; j < LEN; j++)
				head[i][j] = str[i][j];
	}


    //copy constructor
	manyStringsV1(const manyStringsV1 &another) 
	{
		head = (char **)malloc(sizeof(char *) * NUM);
		for (int i = 0; i < NUM; i++) 
			*(head + i) = (char *)malloc(sizeof(char) * LEN);

		for (int i = 0; i < NUM; i++)
			for (int j = 0; j < LEN; j++)
				head[i][j] = another.head[i][j];
	}
	
    //destructor
	~manyStringsV1() 
	{
		for(int i = 0; i < NUM; i++)
			free(head[i]);
		free(head);
		cout << "DESTRUCTOR CALLED！" << '\n';
	}

	void input() 
	{
		for (int i = 0; i < NUM; i++) 
		{
			cout << "Type in string NO." << i+1 << 
			" below please. The string should be less than " << LEN << 
			" characters: " << '\n';
			for (int j = 0; j < LEN; j++) 
			{
				char ch = cin.get();
				if (ch == '\n') 
				{
					head[i][j] = '\0';
					break;
				}
				head[i][j] = ch;
			}
		}
		cout << '\n';
		cout << "INPUT OVER!\n";
		cout << '\n';
	}

	void disp() 
	{
		cout << "The strings are:" << '\n';
		for (int i = 0; i < NUM; i++)
		{
			for (int j = 0; j < LEN; j++) 
			{
				if (head[i][j] != '\0') 
					cout << head[i][j];
				else 
					break;
			}
			cout << '\n';
		}
		cout << '\n';
	}

	char * getMinChar(int count[]) 
	{
		char minChars[NUM];
		//char *minChars = new char[NUM];
		for (int i = 0; i < NUM; i++) 
		{
			minChars[i] = head[i][0];
			for (int j = 0; j < strlen(head[i]); j++) 
			{
				if (minChars[i] > head[i][j]) 
					minChars[i] = head[i][j];
			}
		}
		for (int i = 0; i < NUM; i++) 
		{
			count[i] = 0;
			for (int j = 0; j < strlen(head[i]); j++) 
			{
				if (minChars[i] == head[i][j]) 
					count[i]++;
			}
		}
		return minChars;
	}

	void sort() 
	{
		cout << "sort begins? Yeah!\n";
		char *t = new char[LEN];
		for (int i = 0; i < NUM - 1; i++) 
		{
			for (int j = 0; j < NUM - 1 - i; j++) 
			{
				if (strcmp(head[j], head[j + 1]) > 0) 
				{
					strcpy(t, head[j]);
					strcpy(head[j], head[j + 1]);
					strcpy(head[j + 1], t);
				}
			}
		}
		delete []t;
	}
};






class manyStringsV2
{
	char (*head)[LEN];

public:
	manyStringsV2() 
	{
		head = new char[NUM][LEN];
		for (int i = 0; i < NUM; i++)
			head[i][0] = '\0';
	}
      
    //transformation constructor
    manyStringsV2(char(*str)[LEN])
	{
		head = new char[NUM][LEN];
		for (int i = 0; i < NUM; i++)
			for (int j = 0; j < LEN; j++)
				head[i][j] = str[i][j];
	}


    //copy constructor
	manyStringsV2(const manyStringsV2 &another) 
	{
		head = new char[NUM][LEN];
		for (int i = 0; i < NUM; i++)
			for (int j = 0; j < LEN; j++)
				head[i][j] = another.head[i][j];
	}
	
    //destructor
	~manyStringsV2() 
	{
		delete []head;
		cout << "DESTRUCTOR CALLED！" << '\n';
	}

	void input() 
	{
		for (int i = 0; i < NUM; i++) 
		{
			cout << "Type in string NO." << i+1 << 
			" below please. The string should be less than " << LEN << 
			" characters: " << '\n';
			for (int j = 0; j < LEN; j++) 
			{
				char ch = cin.get();
				if (ch == '\n') 
				{
					head[i][j] = '\0';
					break;
				}
				head[i][j] = ch;
			}
		}
		cout << '\n';
		cout << "INPUT OVER!\n";
		cout << '\n';
	}

	void disp() 
	{
		cout << "The strings are:" << '\n';
		for (int i = 0; i < NUM; i++)
		{
			for (int j = 0; j < LEN; j++) 
			{
				if (head[i][j] != '\0') 
					cout << head[i][j];
				else 
					break;
			}
			cout << '\n';
		}
		cout << '\n';
	}

	char * getMinChar(int count[]) 
	{
		char minChars[NUM];
		//char *minChars = new char[NUM];
		for (int i = 0; i < NUM; i++) 
		{
			minChars[i] = head[i][0];
			for (int j = 0; j < strlen(head[i]); j++) 
			{
				if (minChars[i] > head[i][j]) 
					minChars[i] = head[i][j];
			}
		}
		for (int i = 0; i < NUM; i++) 
		{
			count[i] = 0;
			for (int j = 0; j < strlen(head[i]); j++) 
			{
				if (minChars[i] == head[i][j]) 
					count[i]++;
			}
		}
		return minChars;
	}

	void sort() 
	{
		cout << "is it... really sorting?\n";
		char *t = new char[LEN];
		for (int i = 0; i < NUM - 1; i++) 
		{
			for (int j = 0; j < NUM - 1 - i; j++) 
			{
				if (strcmp(head[j], head[j + 1]) > 0) 
				{
					strcpy(t, head[j]);
					strcpy(head[j], head[j + 1]);
					strcpy(head[j + 1], t);
				}
			}
		}
		delete []t;
	}
};



class manyStringsV3
{
	char *head[NUM];


public:
	manyStringsV3() 
	{   
		for (int i = 0; i < NUM; i++)
		{
			head[i] = new char[LEN];
			head[i][0] = '\0';
		}
	}
      
    //transformation constructor
	manyStringsV3(char *str[NUM])
	{
		for (int i = 0; i < NUM; i++)
			head[i] = new char[LEN];
		for (int i = 0; i < NUM; i++)
			for (int j = 0; j < LEN; j++)
				head[i][j] = str[i][j];

	}


    //copy constructor
	manyStringsV3(const manyStringsV3 &another) 
	{

		for (int i = 0; i < NUM; i++)
			head[i] = new char[LEN];
		for (int i = 0; i < NUM; i++)
			for (int j = 0; j < LEN; j++)
				head[i][j] = another.head[i][j];

	}
	
    //destructor
	~manyStringsV3() 
	{
		for (int i = 0; i < NUM; i++)
			delete []head[i];
		cout << "DESTRUCTOR CALLED！" << '\n';
	}

	void input() 
	{
		for (int i = 0; i < NUM; i++) 
		{
			cout << "Type in string NO." << i+1 << 
			" below please. The string should be less than " << LEN - 1 << 
			" characters: " << '\n';
			for (int j = 0; j < LEN; j++) 
			{
				char ch = cin.get();
				if (ch == '\n') 
				{
					head[i][j] = '\0';
					break;
				}
				head[i][j] = ch;
			}
		}
		cout << '\n';
		cout << "INPUT OVER!\n";
		cout << '\n';
	}

	void disp() 
	{
		cout << "The strings are:" << '\n';
		for (int i = 0; i < NUM; i++)
		{
			for (int j = 0; j < LEN; j++) 
			{
				if (head[i][j] != '\0') 
					cout << head[i][j];
				else 
					break;
			}
			cout << '\n';
		}
		cout << '\n';
	}
    
	char * getMinChar(int count[]) 
	{
		char minChars[NUM];
		//char *minChars = new char[NUM];
		for (int i = 0; i < NUM; i++) 
		{
			minChars[i] = head[i][0];
			for (int j = 0; j < strlen(head[i]); j++) 
			{
				if (minChars[i] > head[i][j]) 
					minChars[i] = head[i][j];
			}
		}
		for (int i = 0; i < NUM; i++) 
		{
			count[i] = 0;
			for (int j = 0; j < strlen(head[i]); j++) 
			{
				if (minChars[i] == head[i][j]) 
					count[i]++;
			}
		}
		return minChars;
	}
	

	void mergeSort(char *ms, int startIndex, int endIndex) {
		//If the sequence is divided into the smallest unit (a number), the partition is stopped.
		if (endIndex - startIndex > 0) {
			mergeSort(ms, startIndex, (startIndex + endIndex) / 2);//left partition
			mergeSort(ms, (startIndex+endIndex) / 2 + 1, endIndex);//right partition
			merge(ms, startIndex, (startIndex + endIndex) / 2, endIndex);//merge
		}
		//cout << "The String after mergeSort:" << '\n';
	}
    
    /*
    *In the merge step, the array will be divided by two arrays merged 
    *and sorted in ascending order. The one on the left is called the left array, 
    *and the one on the right is called the right array.
    */    
	void merge(char a[], int l, int m, int r) {
		int i = l, j = m+1, k = l;
    	char b[r - l + 1];
    	while (i <= m && j <= r) {
    		if (a[i] <= a[j]) {
    			b[k++] = a[i++];
    		} else {
                b[k++] = a[j++];
        	}
    	}

    	if(i > m) {
    		for(int p = j; p <= r; p ++) {
    			b[k++] = a[p];
    		}
    	} else { 
    		for(int p = i; p <= m; p ++) {
            	b[k++] = a[p];
            }
        }

    	//copy from b to a
    	for(int q = l; q <= r; q ++)
    	{
        	a[q] = b[q];
    	}
    }
    
    /*
	char * getString(int x) 
	{
		if (x > NUM || x <= 0) 
		{
			cout << "Index out of bound!" << '\n';
			cout << "Please enter again!" << '\n';
			return head[NUM];
		}
		return head[x-1];
	}
	*/

	void sort() 
	{
		cout << "is it... really sorting?\n";
		char *t = new char[LEN];
		for (int i = 0; i < NUM - 1; i++) 
		{
			for (int j = 0; j < NUM - 1 - i; j++) 
			{
				if (strcmp(head[j], head[j + 1]) > 0) 
				{
					strcpy(t, head[j]);
					strcpy(head[j], head[j + 1]);
					strcpy(head[j + 1], t);
				}
			}
		}
		delete []t;
	}
};




/*
 *As you have seen above, we included 3 classes in this single file
 *that is, class manyStringsV1, class manyStringsV2, and class manyStringsV3.
 *
 *In the main() function, default is to call version3.
 *You can change all "manyStringsV3" word into "manyStringsV1",
 *or "manyStringsV2" if you want to test the other two implementations.
 *
 *To do this, first note that an object called "leader", created in main() function, 
 *also has 3 versions. The default for "leader" is version3.
 *You need to change its version to match yours,
 *e.g. you should change "leader" into version2 if you want to use manyStringsV2.
 *Remember to change "leader" both creating and deleting!
 *
 *And of course we are good if you just want to test version3.
 *Have a nice day :P
 *
 */

int main() 
{

	//create leader for version1
	/*
	char ** leader;
	leader = (char **)malloc(sizeof(char *) * NUM);
		for (int i = 0; i < NUM; i++) 
			*(leader + i) = (char *)malloc(sizeof(char) * LEN);

		for (int i = 0; i < NUM; i++)
		{
			int j = 0;
			for (; j < LEN - 1; j++)
			{
				leader[i][j] = 'x';
			}
			leader[i][j] = '\0';
		}
	*/


	//create leader for version2
	/*
	char(*leader)[LEN] = new char[NUM][LEN];
	for (int i = 0; i < NUM; i++) 
	{
		int j = 0;
		for (; j < LEN - 1; j++)
		{
			leader[i][j] = 'x';
		}
		leader[i][j] = '\0';
	}
	*/


    //create leader for version3(default)
	char *leader[NUM];
	for (int i = 0; i < NUM; i++)
			leader[i] = new char[LEN];
	for (int i = 0; i < NUM; i++) 
	{
		int j = 0;
		for (; j < LEN - 1; j++)
		{
			leader[i][j] = 'x';
		}
		leader[i][j] = '\0';
	}


	cout << endl << "constructor:" << endl;
	cout << '\n';
	manyStringsV3 obj1; //change version if you want to :)
	obj1.input();
	obj1.disp();
    
    cout << endl << "copy constructor:" << endl;
    cout << '\n';
	
	manyStringsV3 obj2 = obj1; //change version if you want to :)
	obj2.disp();

	cout << endl << "transformation constructor:" << endl;
	cout << '\n';
	manyStringsV3 obj3(leader); //change version if you want to :)
	obj3.disp();

	//test getminchar
	static int ct[NUM];   //ct[NUM] = {0,0,0,...}
    char *mins;
    mins = obj1.getMinChar(ct);
	for (int i = 0; i < NUM; i++) 
	{
		cout << "The minimum character in string NO." << i + 1 << " is " << 
		obj1.getMinChar(ct)[i] << ", which appears " << ct[i] << " time(s)." << '\n';
	}

	//sort
	cout << endl << "sort:" << endl;
	obj1.sort();
	obj1.disp();
    
    //delete leader for version1
	/*
	for(int i = 0; i < NUM; i++)
			free(leader[i]);
		free(leader);
	*/
	

    //delete leader for version2
	/*
	delete []leader;
	*/

    //delete leader for version3
	for (int i = 0; i < NUM; i++)
			delete []leader[i];
		
	return 0;
}





