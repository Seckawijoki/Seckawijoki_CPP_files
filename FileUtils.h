#include <iostream>
#include <direct.h>
#include <string>
#include <cstring>
#include <io.h>
using namespace std;
bool FindFile(std::string folderPath, std::string &fileName, std::string &foundPath)
{
	_finddata_t fileInfo;
	std::string strFind = folderPath + "/*";
	long handle = _findfirst(strFind.c_str(), &fileInfo);
	if (handle == -1L)
	{
		return false;
	}
	do
	{
		if (fileInfo.attrib & _A_SUBDIR)
		{
			if ((strcmp(fileInfo.name, ".") != 0) && (strcmp(fileInfo.name, "..") != 0))
			{
				std::string newPath = folderPath + "/" + fileInfo.name;
				if (FindFile(newPath, fileName, foundPath))
					return true;
			}
		}
		else
		{
			cout << folderPath << "/" << fileInfo.name << endl;
			if (strcmp(fileInfo.name, fileName.c_str()) == 0)
			{
				cout<<"找到文件"<<fileInfo.name<<endl; 
				foundPath = folderPath + "/" + fileInfo.name;
				return true;
			}
		}
	}
	while (_findnext(handle, &fileInfo) == 0);
	_findclose(handle);
	return false;
}
bool TraverseFile(string path)
{
	_finddata_t fileInfo;
	long handle = _findfirst(path.c_str(), &fileInfo);
	if (handle == -1L)
	{
		cerr<<"failed to transfer files\n";
		return false;	
	}
	do
	{
		cout<<fileInfo.name<<endl;
	} while (_findnext(handle, &fileInfo) == 0);
	return true;
}
bool CopyFile(string src, string des)
{
	FILE* fSrc = fopen(src.c_str(), "rb");
	if (!fSrc)
	{
		cout<<"打开文件"<<src<<"失败。\n";
		return false;
	}
	FILE* fDes = fopen(des.c_str(), "wb");
	if (!fDes)
	{
		cout<<"创建文件"<<des<<"失败。\n";
		return false;
	}
	unsigned char* buf;
	unsigned int length;
	fseek(fSrc, 0, SEEK_END);
	length = ftell(fSrc);
	buf = new unsigned char[length+1];
	memset(buf, 0, length+1);
	fseek(fSrc, 0, SEEK_SET);
	fread(buf, length, 1, fSrc);
	fwrite(buf, length, 1, fDes);
	fclose(fSrc);
	fclose(fDes);
	delete []buf;
	return true;
}
