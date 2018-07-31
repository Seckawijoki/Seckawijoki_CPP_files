#include "tinyxml.h"
#include "tinystr.h"
#include "FileUtils.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
int main()
{
	string srcFile = "F:/trunk/env1/bin/res/ui/filelist.xml";
	string desFile = "F:/cpp_files/filelist.xml";
	CopyFile(srcFile, desFile);
	TiXmlDocument xml(desFile.c_str());
	
	return 0;
} 
