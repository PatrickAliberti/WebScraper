# WebScraper

Scrapes the stock price of a stock depending on the stock symbol entered by the user with the libcurl library.

This program gets the HTML code of a stock website and writes it to a file using the libcurl 'easy' interface. It then copies the HTML into a string and parse through the string using string functions.

The WebPage class is used to represent the webpage you are gettin the HTML code from and using to write to a file and contains the operations for getting the url and writing the HTML code to a file. 

The File class is used to represent the file the program is parsing through and contains the operations for finding and modifying the data.

'scraperDriver.cpp' is the driver for the classes. It performs the functions in the classes using objects.
