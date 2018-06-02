/*
题目描述
在前面学生类和教师类的基础上，增加两种对象的互动。
教师的日常工作包括布置作业（homework）、批改作业(review)。

其中布置作业需要指定是哪门课程的作业，
需要知道课程名称，然后返回课程编号；

批改作业需要接收学生的作业答案，并根据答案返回分数，
如果答案大于60则返回分数88，否则返回分数44。

学生的日常学习包括做作业（dohomework），
作业内容是根据课程编号返回作业答案，
以课程编号的平方值做为作业答案。

在前面师生两个类中增加相应的操作方法，
并根据输入输出要求使用上述的方法。

要求：必须使用师生两个类的方法来
实现布置作业、批改作业、做作业的过程，
凡是发现用其他方法一律无效！

输入
第一行输入t表示有t门课程
接着输入t行，每行包含两个参数，
第一个参数是课程编号（正整数），第二个参数课程名称（字符串）
接着一行输入n，n小于t，表示老师布置作业的数量
接着输入n行，每行输入一个作业对应的课程名称，
每输入一行就依次调用三个方法来表示三个操作：
老师布置作业，学生做作业，老师批改作业

输出
每行输出一个作业的成绩

样例输入
5
4 math
8 chinese
6 english
7 biology
9 history
3
history
math
english

样例输出
88
44
44
*/
# include <iostream>
# include <string>
using namespace std;
class Student
{
private:
	int *courseNumber;
	string *courseName;
	int *homeworkAnswer;
public:
	Student()
	{
		courseNumber = new int (0);
		courseName = new string ("？？？\0\n");
		homeworkAnswer = new int (0);
	}
	Student( int number , string name , int i )
	{
		courseNumber[i] = number;
		courseName[i] = name;
	}
	void SetNumberName( int number , string name , int i )
	{
		courseNumber[i] = number;
		courseName[i] = name;
	}
	void Initial( int size )
	{
		courseNumber = new int [size];
		courseName = new string [size];
		homeworkAnswer = new int [size];
	}
	int DoingHomework( int curriculumNumber )
	{
		return curriculumNumber * curriculumNumber;
	}
	string GetCourseName( int i )
	{
		return courseName[i];
	}
	int GetCourseNumber( int i )
	{
		return courseNumber[i];
	}
};
class Teacher
{
private:
	int *curriculumNumber;
	string *curriculum;
public:
	Teacher()
	{
		curriculumNumber = new int (0);
		curriculum = new string ("None\0\n");
	}
	Teacher( int number , string course , int i )
	{
		curriculumNumber[i] = number;
		curriculum[i] = course;
	}
	void Initial( int n )
	{
		curriculumNumber = new int [n];
		curriculum = new string [n];
	}
	void SetCurriculum( string course , int i )
	{
		curriculum[i] = course;
	}
	void SetNumber( Student &gakusei , int t , int n )
	{
		int j,k;
		for ( j = 0 ; j < t ; j++ )
			for ( k = 0 ; k < n ; k++ )
				if ( curriculum[k] == gakusei.GetCourseName(j) )
					curriculumNumber[k] = gakusei.GetCourseNumber(j);
	}
	int AssigningHomework( string course , int i )
	{
		return curriculumNumber[i];
	}
	int CorrectingHomework( Student &gakusei , int i )
	{
		if ( gakusei.DoingHomework(AssigningHomework(curriculum[i],i)) > 60 )
			return 88;
		else
			return 44;
	}
};
int main()
{
	int t,n,bango,i,j;
	string course,jugyou;
	Student gakusei;
	Teacher sensei;
	cin>>t;
	gakusei.Initial(t);
	for ( i = 0 ; i < t ; i ++ )
	{
		cin>>bango>>course;
		gakusei.SetNumberName(bango,course,i);
	}
	cin>>n;
	sensei.Initial(n);
	for ( i = 0 ; i < n ; i ++ )
	{
		cin>>jugyou;
		sensei.SetCurriculum(jugyou,i);
		for ( j = 0 ; j < t ; j ++ )
			sensei.SetNumber(gakusei,t,n);
		cout<<sensei.CorrectingHomework(gakusei,i)<<endl;
	}
	return 0;
}