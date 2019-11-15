#include <iostream>
#include <string.h>



using namespace std;

#define NUM 3
#define LEN 21

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
		for (int i = 0; i < NUM; i++) 
			head[i] = str[i];
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



int main() 
{
    //leader for version3 and version1(default)
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
	manyStringsV1 obj1;
	obj1.input();
	obj1.disp();
	for (int i = 0; i < NUM; i++)
			delete []leader[i];
	return 0;
}
    