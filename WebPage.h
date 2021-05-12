/***************************************************************************************************
Patrick Aliberti

WebPage.h

05/12/2021

This program is the class specification for the WebPage class
***************************************************************************************************/
#ifndef WEBPAGE_H
#define WEBPAGE_H

using namespace std;

class WebPage {
private:
    char bareUrl[55];
    
public:
	char *getUrl();
	void urlToFile(CURL* curl, FILE* fp, CURLcode res);
};

#endif
