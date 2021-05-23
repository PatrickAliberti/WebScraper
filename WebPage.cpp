/***************************************************************************************************
Patrick Aliberti

WebPage.cpp

05/12/2021

This program is the implementation of the WebPage class
***************************************************************************************************/
#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include "WebPage.h"
using namespace std;

/***************************************************************************************************
task:		To get the url that will be used to get the stock price from

data out:	Returns the url
***************************************************************************************************/
char *WebPage::getUrl()
{
	string strUrl = "http://tickertech.net/cgi/?ticker=";
	for (int i = 0; i < strUrl.length(); i++)
		bareUrl[i] = strUrl[i];
	
	string stockString;

	cout << "Enter the symbol of the stock you want:\n";
	cin >> stockString;
	if (stockString.length() > 4)
	{
		cout << "Please enter a valid stock symbol" << endl;
		cin >> stockString;
	}

	int tickerSize = stockString.length();		// Set a c-string equal to the ticker
	char stock[tickerSize];
	for (int i = 0; i < tickerSize; i++)
	{
		stock[i] = stockString[i];
	}
	strcat(bareUrl, stock);				// Append ticker to the 'skelaton URL'
	return bareUrl;
}

/***************************************************************************************************
task:		To write the html data from a webpage to a file

data out:	No return value

data in:	handle to a transfer, handle to a file, and variable used for performing transfer
***************************************************************************************************/
void WebPage::urlToFile(CURL* curl, FILE* fp, CURLcode res)
{
	char *url = bareUrl;
	char outfilename[FILENAME_MAX] = "page.html";
	
	// Create an empty handle to a transfer
	curl = curl_easy_init();                                                                                                                                                                                                                                          
	if (curl)
	{   
		fp = fopen(outfilename,"wb");
		
		// Set transfer to URL
		curl_easy_setopt(curl, CURLOPT_URL, url);
		
		// Send html data to this function
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
		
		// Write data to the file handle
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		
		// Perform transfer; return HTML code in the file
		res = curl_easy_perform(curl);
		
		// Cleanup
		curl_easy_cleanup(curl);
		fclose(fp);
	}
}
