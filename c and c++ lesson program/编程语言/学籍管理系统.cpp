# include <iostream>
# include <cstdlib>
using namespace std;
class student
{
	public:
		string name;
		int age;
		bool sex;
		double mark;
		int grade;
		student()
		{
			name = "?";
			age = 0;
			sex = false;
			mark = 0;
			grade = 0;
		} 
		student(string namae, int nenrei, 
		bool seibetsu, double seiseki, int kurasu)
		{
			name = namae;
			age = nenrei;
			sex = seibetsu;
			mark = seiseki;
			grade = kurasu;
		}
};
class management
{
	private:
	  int size;
	  int MAX_SIZE;
		student *gakusei;
	public:
		management()
		{
			size = 0;
			MAX_SIZE = 12;
			gakusei = new student[MAX_SIZE];
		}
		management(int length)
		{
			setSize(length);
		}
		void display()
		{
			display(size);
		}
		void display(int s)
		{
			string space = "     ";
			s = s > size ? size : s;
			for (int i = 0; i < s; ++i)
			{
				cout<<gakusei[i].name<<space
						<<gakusei[i].age<<space
						<<(gakusei[i].sex == false? "女" : "男")<<space
						<<gakusei[i].mark<<space
						<<gakusei[i].grade<<space<<endl;
			}
		}
		void setSize(int length)
		{
			size = length;
			if (size > MAX_SIZE)
			{
				int old_size = MAX_SIZE;
				MAX_SIZE = size * 1.25;
				student *t = gakusei;
				student *s = new student[MAX_SIZE];
				for (int i = 0; i < old_size; ++i)
					s[i] = t[i];
				gakusei = s;
				delete []t;
			}
		}
		void addStudent()
		{
			setSize(size+1);
			student s("名字", size, size%2, 60+size, size%4 + 1);
			gakusei[size-1] = s;
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
			cout<<"把最后一个学生的名字更改\n"; 
			if (size > 0)
			{
				gakusei[size-1].name = "你的名字";
			}
		}
		void queryStudent()
		{
			cout<<"列出前五项\n"; 
			if (size > 0)
			{
				int length = size > 5 ? 5 : size;
				display(length);
			}
		}
		void rankStudent()
		{
			int cmp(const void*,const void*);
			if (size > 0)
		  qsort(gakusei, size, sizeof(gakusei[0]), cmp);
		}
};
int cmp(const void *a, const void *b)
{
  return (*(student*)b).age - (*(student*)a).age;
} 
int main()
{
	int choice;
	management manager;
	bool exit;
	while (1){
		cout
		<<"1.添加  2.删除  3.更新  4.查找  5.排序  6.展示  7.退出。"
		<<"请选择：\n";
		cin>>choice;
		switch (choice){
			case 1:
				manager.addStudent();
				manager.display();
				break;
			case 2:
				manager.deleteStudent();
				manager.display();
				break;
			case 3:
				manager.updateStudent();
				manager.display();
				break;
			case 4:
				manager.queryStudent();
				break;
			case 5:
				manager.rankStudent();
				manager.display();
				break;
			case 6:
				manager.display();
				break;
			default:
			case 7:
				exit = true;
				break;
		}
		if (exit)break;
	}
	return 0;
}
