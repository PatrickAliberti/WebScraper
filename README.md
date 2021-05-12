# WebScraper

Scrapes stock data from a web page using the libcurl library.

This program gets the HTML code of a stock website and writes it to a file using the libcurl 'easy' interface. It then parses through the HTML and writes the data to the screen.

The WebPage class is used to represent the webpage you are gettin the HTML code from and using to write to a file and contains the operations for getting the url and writing the HTML code to a file. 

The File class is used to represent the file the program is parsing through and contains the operations for finding and displaying the data.
