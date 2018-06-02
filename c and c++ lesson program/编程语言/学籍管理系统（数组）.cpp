# include <iostream>
using namespace std;
int size;
int MAX_SIZE;
string *name;
int *age;
bool *sex;
double *mark;
int *grade;
void initiate()
{
	size = 0;
	MAX_SIZE = 12;
	name = new string[MAX_SIZE];
	age = new int [MAX_SIZE];
	sex = new bool [MAX_SIZE];
	mark = new double [MAX_SIZE];
	grade = new int [MAX_SIZE];
}
void display(int s)
{
	string space = "     ";
	s = s > size ? size : s;
	for (int i = 0; i < s; ++i)
	{
		cout
		<<name[i]<<space
		<<age[i]<<space
		<<(sex[i] ? "女" : "男")<<space
		<<mark[i]<<space
		<<grade[i]<<space<<endl;
	}
}
void display()
{
	display(size);
}
void setSize(int length)
{
	size = length;
	if (size > MAX_SIZE)
	{
		int old_size = MAX_SIZE;
		MAX_SIZE = size * 1.25;
		string *t_name = name;
		int *t_age = age;
		bool *t_sex = sex;
		double *t_mark = mark;
		int *t_grade = grade;
		
		string *name2 = new string[MAX_SIZE];
		int *age2 = new int [MAX_SIZE];
		bool *sex2 = new bool [MAX_SIZE];
		double *mark2 = new double [MAX_SIZE];
		int *grade2 = new int [MAX_SIZE];
		
		for (int i = 0; i < old_size; ++i)
		{
			name2[i] = t_name[i];
			age2[i] = t_age[i];
			sex2[i] = t_sex[i];
			mark2[i] = t_mark[i];
			grade2[i] = t_grade[i]; 
		} 
		name = name2;
		age = age2;
		sex = sex2;
		mark = mark2;
		grade = grade2;
		
		delete []t_name;
		delete []t_age;
		delete []t_sex;
		delete []t_mark;
		delete []t_grade;
	}
}
void addStudent()
{
	setSize(size+1);
	name[size-1] = "名字";
	age[size-1] = size;
	sex[size-1] = size%2;
	mark[size-1] = 60+size;
	grade[size-1] = size%4 + 1;
}
void deleteStudent()
{
	--size;
	if (size < 0)
	{
		size = 0;
	}
}
void updateStudent()
{
	if (size > 0)
	{
		name[size-1] = "你的名字";
	}
}
void queryStudent()
{
	if (size > 0)
	{
		int length = size > 5 ? 5 : size;
		display(length); 
	}
}
int Partition(int low, int high)
{
	int pivotkey = age[low]; 
	string t_name = name[low];
	int t_age = age[low];
	bool t_sex = sex[low];
	double t_mark = mark[low];
	int t_grade = grade[low];
	while ( low < high )
	{
		while ( low < high && age[high] <= pivotkey )--high;
		name[low] = name[high];
		age[low] = age[high];
		sex[low] = sex[high];
		mark[low] = mark[high];
		grade[low] = grade[high];
		while ( low < high && age[low]  >= pivotkey )++low;
		name[low] = name[high];
		age[low] = age[high];
		sex[low] = sex[high];
		mark[low] = mark[high];
		grade[low] = grade[high];
	}
		name[low] = t_name;
		age[low] = t_age;
		sex[low] = t_sex;
		mark[low] = t_mark;
		grade[low] = t_grade;
	return low;
}
void rankStudent(int low, int high )
{
	int pivotlocation;
	if ( low < high )
	{
		pivotlocation = Partition(low,high);
		rankStudent(low,pivotlocation-1);
		rankStudent(pivotlocation+1,high);
	}
}
int main()
{
	int choice;
	initiate();
	bool exit;
	cout<<"数组测试\n";
	while (1){
		cout 
		<<"1.添加  2.删除  3.更新  4.查找  5.排序  6.展示  7.退出。"
		<<"请选择：";
		cin>>choice;
		switch (choice){
			case 1:
				addStudent();
				display();
				break;
			case 2:
				deleteStudent();
				display();
				break;
			case 3:
				updateStudent();
				display();
				break;
			case 4:
				queryStudent();
				break;
			case 5:
				rankStudent(0 ,size-1);
				display();
				break;
			default:
			case 6:
				display();
				break;
			case 7:
				exit = true;
				break;
		}
		if (exit)break;
	}
	return 0;
}
