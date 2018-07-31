#include <iostream>
#include "FileUtils.h" 
using namespace std;

int main()
{
	const char* src = "F:/batch_files/__call_git_add_commit_push_in_miniworld_computer.bat";
	const char* des = "F:/cpp_files/copied_file_by_cpp.bat";
	if (CopyFile(src, des))
	{
		cout<<"复制成功："<<src<<" -> "<<des<<endl;
	}
	else
	{
		cout<<"复制失败\n";
	}
	mkdir("f:/cpp_files/directory_made_by_cpp");
//	TraverseFile("f:/cpp_files/*");

	string foundPath;
	string fileName = "test.cpp";
	string findPath = "f:/trunk/env1/client/";
	findPath = "f:/cpp_files/";
	if (FindFile(findPath, fileName, foundPath))
	{
		cout<<"复制文件："<<foundPath<<" -> "<<findPath+fileName<<endl;
		CopyFile(foundPath, findPath+fileName);
	}
	else
	{
		
	}
	return 0;
} 
