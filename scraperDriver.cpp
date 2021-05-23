/***************************************************************************************************
Patrick Aliberti

scraperDriver.cpp

05/12/2021

This program is the driver for the WebPage and File classes
***************************************************************************************************/
#include <curl/curl.h>
#include <iostream>
#include "File.h"
#include "WebPage.h"
using namespace std;

int main(void)
{
	CURL* curl;						// Handle to a transfer
	FILE* fp;						// Handle to a file
	CURLcode res;						// For performing transfers
	
	WebPage stockPage;
	
	// Get the url of the web page depending on the stock symbol entered by user
	stockPage.getUrl();
	
	// Use the url to create a transfer and write the HTML code to a file
	stockPage.urlToFile(curl, fp, res);
    
	File htmlFile;

	// Read the file into a sting so that it can be parsed
	string file = htmlFile.readFileIntoString();
	cout << "\nThe HTML code:\n\n" << file << endl;

	// St the value of the search criteria
	htmlFile.setSearch("<b>");

	// Find where in the file the stock price is
	unsigned long long position = htmlFile.findPrice();
	cout << "\nThe index of the price in the file is " << position << endl;

	// Trim the string so that it only shows the data to be displayed
	string stockPrice = htmlFile.trimString();
	cout << "\nThe price of the stock is $" << stockPrice << endl;

	return 0;
}
