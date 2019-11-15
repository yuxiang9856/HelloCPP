/*����һ���࣬���ڶ�10���ַ������й�����Ҫ��

��1���ڶ������ʱ���ܹ�Ϊ�ַ�����գ�

��2������任���캯�����ܹ�Ϊ�ַ������Ը������ַ�����

��3�����帴�ƹ��캯����

��4�������Ա�������ܹ�Ϊ�ַ����������ݣ�

��5�������Ա�������ܹ����ַ�����ʾ������

��6�������Ա�����������ҳ�ÿ���ַ����е���Сֵ��ASCII����С���ַ��������������Сֵ�ɺ���ֵ���أ������ɲ������أ�

��7�������Ա����������Ϊ�ַ�������С����˳������

��8������main�����������ص�������ÿ��������*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#define L 3
#define N 20
using namespace std;
class cString {
	char(*pt)[N + 1] ; //char **pt;
public:
	cString() {
		pt = new char[L][N + 1];
		for (int i = 0; i < L; i++)
			pt[i][0] = '\0';
	}
	cString(char(*p)[N+1]) {
		pt = new char[L][N + 1];
		for (int i = 0; i < L; i++)
			for (int j = 0; j < (N+1); j++) 
				pt[i][j] = p[i][j];
	}
	cString(const cString& another) {
		//pt = new char[L][N + 1];
		//for (int i = 0; i < L; i++)
		//pt = another.pt;
		pt = new char[L][N + 1];
		for (int i = 0; i < L; i++)
			for (int j = 0; j < (N+1); j++) 
				pt[i][j] = another.pt[i][j];

	}
	void input() {
		for (int i = 0; i < L; ++i)
		{
			int j = 0;
			while ((pt[i][j]=getchar()) != '\n') {
				j++;
				if (j >= N+1) {
					break;
				}
			}
			pt[i][j] = '\0';
		}
	}
	void disp() {
		for (int i = 0; i < L; i++) {
			cout << "pt[" << i << "]:";
			for (int j = 0; j < N; j++) {
				if (pt[i][j] != '\0') {
					cout << pt[i][j] << " ";
				}
				else
					break;
			}
			cout << endl;
		}
	}
	
	char* min(int(&a)[L]){
		char m[L];
		for (int i = 0; i < L; ++i)
		{
			int n = pt[i][0];
			for (int j = 0; j < strlen(pt[i]); ++j)
			{
				if (pt[i][j] < n) {
					n = pt[i][j];
				}	
			}
			for (int j = 0; j < strlen(pt[i]); ++j) {
				if (pt[i][j] == n)
					a[i]++;
			}
			m[i] = n;
		}
		return m;
	}
	void sort() {
		cout << "is it... really sorting?\n";
		int ptr;

		char *t = new char[N + 1];
		
		for (int i = 0; i < L - 1; i++) {
			for (int j = 0; j<L-1-i; j++) {
				ptr = strcmp(pt[j], pt[j + 1]);
				if (ptr > 0) {
					strcpy(t, pt[j]);
					strcpy(pt[j], pt[j + 1]);
					strcpy(pt[j + 1], t);
				}
			}
			
		}
		delete []t;
	}
	~cString() {
		cout << "DESTRUCTOR CALLED！" << '\n';
		delete []pt;
	}
};

int main() {
	char(*st)[N+1] = new char[L][N+1]; 
	for (int i = 0; i < L; i++) {
		int j = 0;
		for (; j < N; j++) {
			st[i][j] = 'b';
		}
		st[i][j] = '\0';
	}

	cout << "Please input "<<L
		<<" strings and each one of them has at most "<<N
		<<" characters" << endl;
	
	cString D1;
	D1.input();
	D1.disp();
	cout <<endl<< "Transformation constructor" << endl;
	cString D2(st);
	D2.disp();
	cout << endl << "Copy constructor" << endl;
	cString D3(D1);
	D3.disp();
	cout << endl << "Min character" << endl;
	for (int i = 0; i < L; i++) {
		int c[L];
		for (int j = 0; j < L; j++)
			c[j] = 0;
		int(&a)[L] = c;
		cout << "min character : " << D3.min(a)[i];
		cout << endl;
		cout << "number of min : " << a[i] << endl;
		cout << endl;
	}
	cout << endl << "Sort" << endl;
	D3.sort();
	D3.disp();
	delete []st;

	return 0;
}
