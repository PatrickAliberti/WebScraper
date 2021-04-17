#include <cstring>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <string.h>
#include "WebPage.h"
using namespace std;

int main(void)
{
	CURL* curl;							// Handle to a transfer
    FILE* fp;							// Handle to a file
    CURLcode res;
	
	WebPage obj;
	obj.urlToFile(curl, fp, res);
    
    File page;
    
    // Get the number of lines
    int numOfLines = page.getNumOfLines();
    
    // Read the file into a dynamic array of strings
    string *linePtr = page.readIntoString(numOfLines);
    
    // Display the string array to the screen
    // obj.displayStringArray(linePtr, numOfLines);
    
    // Get the number of matches using the search criteria
    string search = "<!doctype html>";
    int numOfMatches = page.getNumOfMatches(linePtr, numOfLines, search);
    cout << numOfMatches;
    
    // Write the matches to a dynamic array of strings
    string *matchPtr = page.writeMatchesToArray(linePtr, numOfLines, search, numOfMatches);
    
    // Display the matches string array to the screen
    page.displayStringArray(matchPtr, numOfMatches);
    
    return 0;
}
