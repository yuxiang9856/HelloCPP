#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
题目：基于链表的学生信息管理系统

要求：

    （1）插入节点：输入学生信息后，生成节点并插入链表中；

    （2）删除节点：根据给定的学生姓名或学号删除该学生节点；

    （3）查找节点：根据给定的学生姓名或学号查找学生信息，并显示出来；

    （4）查找并显示总成绩最高和最低的学生信息；

    （5）统计链表中的学生人数；

    （6）（时间允许时选做）对链表节点按总成绩从高到低排序。

   注：

   （1）每个学生信息包括：姓名、学号、性别、出生年月日和3门课的成绩；

   （2）系统运行后，首先显示一个简易的菜单，基于菜单操作来完成上述功能；

   （3）链表的功能需要编程实现。

*/

class student
{
	friend class cList;
//private:
	//friend class cList;
	char name[20];
	long int id;
	char gender[7];
	long int birthday;
	double course1;
	double course2;
	double course3;
	double sum;
	student *next;
public:
    student() 
    {
    	//cout << "You shall not pass1!!!\n";
    	//name = new char[20];
    	strcpy(name, "Gandalf");
    	id = 5;
    	//gender = new char[7];
    	strcpy(gender, "male");
    	birthday = 0;
    	course1 = 90;
    	course2 = 90;
    	course3 = 90;
    	sum = 270;
    	//cout << "You shall not pass2!!!\n";
    }

    student(char *nam, long int iden, char *gen, long int birth, double c1, double c2, double c3) 
    {
    	//name = new char[20];
    	strcpy(name, nam);
    	id = iden;  //e.g. 201663034
    	//gender = new char[7];
    	strcpy(gender, gen);
    	birthday = birth; //e.g. 19980506, 19980127, 19980906
    	course1 = c1;
    	course2 = c2;
    	course3 = c3;
    	sum = c1 + c2 + c3;
    }

    ~student()
    {
    	//delete name;
    	//delete gender;
    	cout << "student destructor     (ง •̀_•́)ง\n";
    }

    student * getNext() 
    {
    	return next;
    }

    void input()
    {
    	cout << "name: ";
    	cin >> name;
    	cout << "\n";

    	cout << "id: ";
    	cin >> id;
    	cout << "\n";

    	cout << "gender: ";
    	cin >> gender;
    	cout << "\n";

    	cout << "birthday: ";
    	cin >> birthday;
    	cout << "\n";

    	cout << "course1: ";
    	cin >> course1;
    	cout << "\n";

    	cout << "course2: ";
    	cin >> course2;
    	cout << "\n";

    	cout << "course3: ";
    	cin >> course3;
    	cout << "\n";

    	sum = course1 + course2 + course3;
 
    }

    void print() 
    {
    	printf("Name: %s\n", name);
    	printf("ID: %ld\n", id);
    	printf("Gender: %s\n", gender);
    	printf("Birthday: %ld\n", birthday);
    	cout << "Course1 Grade: " << course1 << '\n';
    	cout << "Course2 Grade: " << course2 << '\n';
    	cout << "Course3 Grade: " << course3 << '\n';
    	cout << "Sum Grade: " << sum << '\n'; 
    }
};

class cList 
{
protected:
	student *First;
	student *Last;

public:
	cList() 
	{
		First = Last = new student;
	}
	~cList()
	{
		Clear();
		//delete First;
		cout << "cList destructor        (●_●)\n";
	}
	cList &Insert(const student &x); //Insert a node into the header
	cList &Append(const student &x); //append a node to the end
	cList &Delete();                 //Delete a node from the header
	cList &Remove();                 //Remove a node from the end
	void searchByName(char namie[]);
	void searchByID(long int idnum);
	//student &highestScore();
	//student &lowestScore();
	void highestScore();
	void lowestScore();
	int total();
	void rank();
	void Clear();
};

cList &cList::Insert(const student &x)
{
	student *ptr = First;
	First = new student;
	*First = x;
	First -> next = ptr;
	cout << "SUCCESSFULLY INSERTED!!\n";
	return(*this);
}

cList &cList::Append(const student &x)
{
	student *ptr = Last;
	Last = new student;
	*ptr = x;
	ptr -> next = Last;
	cout << "SUCCESSFULLY APPENDED!!\n";
	return(*this);
}

cList &cList::Delete()
{   
	if (First != Last) 
	{
		student *ptr = First -> next;
		//delete First; ############################################11:57pm
		First = ptr;
		 /*
		 *because all 'delete' happen in student objects
		 *you do not want to do it all over again
		 */
	}
	cout << "SUCCESSFULLY DELETED!!\n";
	return (*this);
}

cList &cList::Remove()
{
	if (First == Last) 
		;

	else if (First -> next == Last)
		Delete();
	else
	{
		student *now = First;
		student *pre = First;
		while (now -> next != Last)
		{
			pre = now;
			now = now -> next;
		}
		//delete now;

		 /* 
		 *because all 'delete' happen in student objects
		 *you do not want to do it all over again
		 */
		pre -> next = Last;
	}
	cout << "SUCCESSFULLY REMOVED!!\n";
	return (*this);
}

void cList::searchByID(long int idnum) 
{
	cout << "start search by id:\n";
	student *ptr = First;
	while (ptr != Last)
	{
		if (ptr->id == idnum)
			break;
		ptr = ptr->next;
	}
	ptr -> print();
	cout << "\n";
}

void cList::searchByName(char namie[]) 
{
	cout << "start search by name:\n";
	student *ptr = First;
	while (ptr != Last)
	{
		if (strcmp(ptr -> name, namie) == 0)
		{
			ptr -> print();
			cout << "\n";
		}
		ptr = ptr -> next;
	}
	/*
	student *chosen = new student[count];
	ptr = First;
	int i = 0;
	while (ptr != Last)
	{
		if (ptr -> name == namie)
			ptr -> print();
		ptr = ptr -> next;
	}
	*/
}

void cList::highestScore()
//student &cList::highestScore()
{
	student *ptr = First;
	student *crown;
	double highest = First -> sum;
	while (ptr != Last)
	{
		if (ptr -> sum > highest) 
		{
			highest = ptr -> sum;
			crown = ptr;
		}
		ptr = ptr -> next;
	}
    ptr = First;
	while (ptr != Last)
	{
		if (ptr -> sum == highest) {
			ptr -> print();
			cout << '\n';
		}
		ptr = ptr -> next;
	}
}

void cList::lowestScore()
//student &cList::lowestScore()
{
	student *ptr = First;
	student *dude;
	double lowest = First -> sum;
	while (ptr != Last)
	{
		if (ptr -> sum < lowest) 
		{
			lowest = ptr -> sum;
			dude = ptr;
		}
		ptr = ptr -> next;
	}
	ptr = First;
	while (ptr != Last)
	{
		if (ptr -> sum ==lowest) {
			ptr -> print();
			cout << '\n';
		}
		
		ptr = ptr -> next;
	}
	//dude -> print();
	//return (*dude);
}

int cList::total() 
{
	student *ptr = First;
	int amount = 0;
	while (ptr != Last)
	{
		amount++;
		ptr = ptr -> next;
	}
	return amount;
}

void cList::Clear()
{
	int count = total();
	while (count != 0)
	{
		Delete();
		count--;
	}
}

student & creatANewStudent()
{
	student *stu = new student;
	stu -> input();
	return (*stu);
}

void TheMenu(cList *ls)
{
	cout << '\n';
	cout << '\n';
	cout << "         (●'◡'●)ﾉ❤    (●'◡'●)ﾉ❤    (●'◡'●)ﾉ❤    (●'◡'●)ﾉ❤\n";
	cout << "           ☆☆☆           ☆☆☆         ☆☆☆          ☆☆☆\n";
	cout << "                   ☆☆☆         ☆☆☆         ☆☆☆\n";
	cout << "                         ☆☆☆         ☆☆☆\n";
	cout << "                               ☆☆☆ \n";
	/*
	cout << "                             ☆ \n";
	cout << "                           ☆ \n";
	cout << "                         ☆ \n";
	cout << "                        ☆ \n";
	cout << "                        ☆ \n";
	cout << "                          ☆ \n";
	cout << "                           ☆ \n";
	cout << "                             ☆ \n";
	cout << "                             ☆ \n";
	cout << "                            ☆ \n";
	cout << "                            ☆ \n";
	cout << "                            ☆ \n";
	cout << "                             ☆ \n";
	cout << "                              ☆ \n";
	cout << "                               ☆ \n";
	cout << "                                 ☆  d(ŐдŐ๑)\n";
	cout << '\n';
	*/
	cout << '\n';
	cout << "                     STEP1: CREAT YOUR LIST\n";
	cout << '\n';
	cout << '\n';
	cout << "You can type in following commands to create your unique student list:\n";
	cout << '\n';
	cout << '\n';
	cout << "#   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   \n"; 
	cout << "1  --------- insert to the head \n";
	cout << '\n';
	cout << "2  --------- append to the end\n";
	cout << '\n';
	cout << "3  --------- delete from the head\n";
	cout << '\n';
	cout << "4  --------- remove from the end\n";
	cout << '\n';
	cout << "5  --------- next step\n";
	cout << "#   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   \n";
	cout << '\n';
	cout << '\n';
	cout << '\n';
	cout << '\n';


	while (true) 
	{
		int choice = 0;
	    cin >> choice;

		if (choice == 1)
			ls -> Insert(creatANewStudent());

		else if (choice == 2)
			ls -> Append(creatANewStudent());

		else if (choice == 3)
			if(ls -> total()) 
				ls -> Delete();
			else
				cout << "there is no student in the list!!!\n";

		else if (choice == 4)
			if(ls -> total()) 
				ls -> Remove();
			else
				cout << "there is no student in the list!!!\n";

		else if (choice == 5)
			break;

		cout << '\n';
		cout << '\n';
		cout << "#   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   \n"; 
		cout << "1  --------- insert to the head \n";
		cout << '\n';
		cout << "2  --------- append to the end\n";
		cout << '\n';
		cout << "3  --------- delete from the head\n";
		cout << '\n';
		cout << "4  --------- remove from the end\n";
		cout << '\n';
		cout << "5  --------- next step\n";
		cout << "#   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   \n";
		cout << '\n';
		cout << '\n';
	}



	cout << '\n';
	cout << '\n';
	cout << "              Yeah! Your list is created!\n";
	cout << '\n';
	cout << "         (●'◡'●)ﾉ❤    (●'◡'●)ﾉ❤    (●'◡'●)ﾉ❤    (●'◡'●)ﾉ❤\n";
	cout << '\n';
	cout << '\n';
	cout << "             STEP2:CHECK YOUR LIST INFORMATION\n";
	cout << '\n';
	cout << '\n';
	cout << "You can type in following commands to check your student list:\n";
    cout << '\n';
	cout << '\n';
	cout << "#   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   \n"; 
	cout << "6  --------- search by name\n";
	cout << '\n';
	cout << "7  --------- search by id number\n";
	cout << '\n';
	cout << "8  --------- highest total grade student(s)\n";
	cout << '\n';
	cout << "9  --------- lowest total grade student(s)\n";
	cout << '\n';
	cout << "10 --------- total number of students\n";
	cout << '\n';
	cout << "11 --------- sort the list\n";
	
	/*with the highest-grade student on the head, 
	the next highest-grade student right after ... and the lowest-grade student on the end.
	Note that when multiple students have the same sum grade, 
	the algorithm will sort them in the order of id number.\n";
	*/
	cout << '\n';
	cout << "12 --------- end this program\n";
	cout << "#   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   \n";
	cout << '\n';
	cout << '\n';
	cout << '\n';
	cout << '\n';
	
	while (true) 
	{
		int choice = 0;
	    cin >> choice;
		if (choice == 6)
		{
			char mName[20];
			cout << "name: ";
			cin >> mName;
    	    cout << "\n";
    	    ls -> searchByName(mName);//char namie[]
		}
		else if (choice == 7)
		{
			long int mID;
			cout << "id: ";
			cin >> mID;
    	    cout << "\n";
			ls -> searchByID(mID);//long int idnum
		}
		else if (choice == 8)
			ls -> highestScore();
		else if (choice == 9)
			ls -> lowestScore();
		else if (choice == 10)
			cout << '\n' << "there are " << ls -> total() << " student(s) in total!\n";
		else if (choice == 11)
			cout<< '\n' << "sorry, this function is not available now.\n";//ls -> rank();
		else if (choice == 12)
			break;

		cout << '\n';
		cout << '\n';
		cout << "#   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   \n"; 
		cout << "6  --------- search by name\n";
		cout << '\n';
		cout << "7  --------- search by id number\n";
		cout << '\n';
		cout << "8  --------- highest total grade student(s)\n";			cout << '\n';
		cout << "9  --------- lowest total grade student(s)\n";
		cout << '\n';
		cout << "10 --------- total number of students\n";
		cout << '\n';
		cout << "11 --------- sort the list\n";
		cout << '\n';
		cout << "12 --------- end this program\n";
		cout << "#   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   \n";
		cout << '\n';
		cout << '\n';
	}
	
	cout << '\n';
	cout << '\n';
	cout << "THE END. THANKS FOR USING!\n";
	cout << '\n';
	cout << "(*^ω^*) \n";
	cout << '\n';
	cout << '\n';
}

int main() 
{
    cList *csjpnz = new cList;
    TheMenu(csjpnz);
	return 0;
}














