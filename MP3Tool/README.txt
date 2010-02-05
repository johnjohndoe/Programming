--- 
+ October/November/December 2009
+ January 2010

--- Background:
* International media and computer science, Master's program, Programming course
* First steps with .NET, Windows Forms Applications

--- Usage
* The main-method is located in the MP3Tool.cpp. 
* This is also the place where you have to define the directory from which the mp3-files are read. The default is "c:\\mp3\\".
* The main-method just creates an instance of the ThreadTest-class and calls processAllTests().
* These tests runs after confirming the start with ENTER and prints the result on the console. The different test-cases are explained within the source code 
and in short below. 

--- Tests-Cases
* Test 1 - Add single file per thread
Creates a threaded and a unthreaded track manager and fills the threaded manager with files, one thread for each file. 
After that both track managers are compared. 

* Test 2 - Add multiple files per thread
The same as Test 1, but this time with more than one file added in each thread. 
The files are choosen randomly and so some files are tried to insert more than once. 

* Test 3 - Add multiple files and delete
This test fills both track managers with the same amount of files and then removes randomly a couple of files. 
Each remove of a file is done in a separate thread.

* Test 4 - Add multiple files and search
This test chooses the title randomly from a list of previously inserted files.
It searches for the first character of these titles in the trackmanager, a separate thread for each search, and prints out the result on the screen. 
Since the read threads can access the collection of search results at the "same time"the list of files becomes mixed up at the console.



--- Description:
* An application to handle some information and metadata of mp3 objects.
* The inital set of metadata that are focused are the following:
+ File name
+ Title
+ Artist
+ Album
+ Genre


--- Libraries:
* The application uses the open source id3lib framework version 3.8.3.
* http://id3lib.sourceforge.net/
* Further the boost framework version 1.40 is used.
* http://www.boost.org/


--- Project structure / paths:
* The framework is reference by relative paths.
* The location set in the project settings is the following:
+ build\Programming.sln
+ libs\
+ libs\boost_1_40\boost
+ libs\boost_1_40\lib
+ libs\id3lib-3.8.3\
+ libs\id3lib-3.8.3binaries\
+ MP3Tool\
+ MP3Tool\bin
+ MP3Tool\data
+ MP3Tool\doc
+ MP3Tool\prj
+ MP3Tool\src
+ MP3Tool\README.txt

* The libraries are available free online and are 
  therefore not included into the version system.