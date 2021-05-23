/***************************************************************************************************
Patrick Aliberti

File.cpp

05/12/2021

This program is the implementation file for the File class
***************************************************************************************************/
#include <fstream>
#include <iostream>
#include "File.h"
using namespace std;

// Search member mutator
void File::setSearch(string s)
{
	search = s;
}

/***************************************************************************************************
task:		To read the data from the file into a single string

data out:	Returns the string with the hmtl code
***************************************************************************************************/
string File::readFileIntoString()
{
	string temp;
	char a;
	ifstream inFile;
	inFile.open("page.html");
	if (inFile)
	{
		while (inFile >> a)
		{
			getline(inFile, temp);
			fileStr.append(temp);
		}
	}
	else
		cout << "Could not open data file." << endl;\
		
	inFile.close();
	return fileStr;
}

/***************************************************************************************************
task:		To find where in the file string the price data is

data out:	Returns an unsigned long long of the position of the price
***************************************************************************************************/
unsigned long long File::findPrice()
{
	found = fileStr.find(search);
	if (found > 3300)
	{
		return 0;
	}
	return found;
}

/***************************************************************************************************
task:		To trim the string to contain only the stock price

data out:	Returns the modified file string
***************************************************************************************************/
string File::trimString()
{	
	if (found == 0)
	{
		cout << "The stock price was not found" << endl;
		return fileStr;
	}
	fileStr.erase(0, found+3);
	fileStr.erase(6, 10090);
	return fileStr;
}
