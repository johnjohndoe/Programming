/*
 * MP3Tool
 * @author 20091024
 */


// MP3Tool.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <id3/tag.h>
#include <iostream>

using namespace MP3Tool;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	//Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	//Application::Run(gcnew Form1());

	std::cerr << "HALLO PROGRAM" << std::endl;
	ID3_Tag myTag;
	myTag.Link("../data/song.mp3");
	ID3_Tag::Iterator* iter = myTag.CreateIterator();
	ID3_Frame* myFrame = myTag.Find( ID3FID_ALBUM);
	if (NULL != myFrame)
    {
		std::cout << "Ausgabe" << std::endl;
		std::cout << myFrame << std::endl;
	}
	else
		std::cout << "myFrame == NULL" << std::endl;




	return 0;
}
