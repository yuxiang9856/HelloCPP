#include <iostream>
#include <string.h>



using namespace std;

#define NUM 3
#define LEN 21

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
		char *minChars = new char[NUM];
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
