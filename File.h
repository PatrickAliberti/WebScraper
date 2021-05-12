/***************************************************************************************************
Patrick Aliberti

File.h

05/12/2021

This program is the specification file for the File class
***************************************************************************************************/
#ifndef FILE_H
#define FILE_H

#include <string>
using namespace std;

class File {
private:
	string fileStr;
	string search;
	unsigned long long found;
		
public:
	void setSearch(string);
	string readFileIntoString();
	unsigned long long findPrice();
	string trimString();
};

#endif
