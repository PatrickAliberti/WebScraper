#include <cstring>
#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "WebPage.h"
using namespace std;

void WebPage::urlToFile(CURL* curl, FILE* fp, CURLcode res)
{
	char bareUrl[] = "my.kiplinger.com/tfn/ticker.html?ticker=";	// Skelaton URL to have ticker appended 
    string stockString;												// String for ticker
    
    cout << "Enter the stock you would like to examine:\n";
    cin >> stockString;
    
    int tickerSize = stockString.length();							// Set a c-string equal to the ticker
    char stock[tickerSize];
    for (int i = 0; i < tickerSize; i++)
    {
    	stock[i] = stockString[i];
	}
    
    strcat(bareUrl, stock);											// Append ticker to the 'skelaton URL'
    
    char *url = bareUrl;
    char outfilename[FILENAME_MAX] = "page.html";
    curl = curl_easy_init();                 						// Empty handle to a transfer                                                                                                                                                                                                                                          
    if (curl)
    {   
        fp = fopen(outfilename,"wb");								// Open file
        curl_easy_setopt(curl, CURLOPT_URL, url);					// Set URL to get here
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);		// Send html data to this function
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);				// Write data to the file handle
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

/***************************************************************************************************
task:		To find the number of lines within an html file

data in:	No parameters, using the data from page.html

data out:	Returns the number of lines in the html file
***************************************************************************************************/
int File::getNumOfLines()
{
	string str;
	ifstream inFile;
	inFile.open("page.html");
	
	if (inFile)
	{
		numOfLines = 0;
		while (getline(inFile, str))
		{
			numOfLines++;
		}
	}
	else
	{
		cout << "Could not open data file." << endl;
	}
	inFile.close();
	
	return numOfLines;
}

/***************************************************************************************************
task:		To read the data from the file into a dynamic string array

data in:	the number of lines

data out:	Returns a pointer to the dynamic string array
***************************************************************************************************/
string *File::readIntoString(const int numOfLines)
{
	string *stringPtr = new string[numOfLines],
			str;
	int index = 0;
	
	ifstream inFile;
	inFile.open("page.html");
	if (inFile)
	{
		while (getline(inFile, str))
		{
			stringPtr[index] = str;
			index++;
		}
	}
	else
	{
		cout << "Could not open data file." << endl;
	}
	inFile.close();
	
	return stringPtr;
}

/***************************************************************************************************
task:		To display a string array to the screen

data in:	A string array and the size of the array

data out:	no return value, outputs the contents of an array
***************************************************************************************************/
void File::displayStringArray(string *strPtr, const int numOfLines)
{
	int index = 0;
	while (index < numOfLines)
	{
		cout << strPtr[index] << "\n";
		index++;
	}
}

/***************************************************************************************************
task:		To find the number of lines that contain the search criteria

data in:	A string array, the size of the array, and the search criteria

data out:	Returns the number of lines that have the search criteria
***************************************************************************************************/
int File::getNumOfMatches(string *strPtr, const int numOfLines, string search)
{
	int index = 0,
		count = 0;
	unsigned long long found;
	for (int i = 0; i < numOfLines; i++)
	{
		found = strPtr[index].find(search);
		if (found != string::npos)
		{
			strPtr[found] = strPtr[index];
			found++;
			count++;
		}
		index++;
	}
	
	return count;
}

/***************************************************************************************************
task:		To assign the matches a dynamic string array.

data in:	The origional string array, the number of lines, the search criteria, and the number
			of matches.

data out:	Returns a pointer to the new string array that contains the matches
***************************************************************************************************/
string *File::writeMatchesToArray(string *origionalArray, const int numOfLines, string search, const int numOfMatches)
{
	string *strPtr = new string[numOfMatches];
	int index = 0;
	unsigned long long found = 0;
	
	for (int i = 0; i < numOfLines; i++)
	{
		found = origionalArray[index].find(search);
		if (found != string::npos)
		{
			strPtr[found] = origionalArray[index];
			cout << strPtr[found] << "\n";			// I could not figure out display fucntion
			found++;
			index++;
		}
		else if (found == string::npos)
		{
			index++;
		}
	}
	return strPtr;
}
