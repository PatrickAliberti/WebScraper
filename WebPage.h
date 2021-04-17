#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <curl/curl.h>
using namespace std;

class WebPage {
private:
	CURL* curl;														// Handle to a transfer
    FILE* fp;
    CURLcode res;
    
public:
	void urlToFile(CURL*, FILE*, CURLcode);
};

class File {
private:
	int numOfLines;
	//int numOfMatches;
		
public:
	int getNumOfLines();
	string *readIntoString(const int);
	void displayStringArray(string *, const int);
	int getNumOfMatches(string *, const int, string);
	string *writeMatchesToArray(string *, const int, string, const int);	
	
};

#endif
