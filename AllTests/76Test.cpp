#include <iostream>
using namespace std;

int main()
{
	for(int rowno=0;rowno<5;rowno++)
     {
          int temp=6;
          cout << rowno << ' ' << temp<<endl;
     }
     if(rowno ==3)     //此处可以引用rowno
          cout << "Correct! ";
      return 0;
}