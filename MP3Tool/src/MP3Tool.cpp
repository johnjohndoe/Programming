/**
 * \file	src\MP3Tool.cpp
 *
 * \brief	Main project file.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
 * \date	20091029
 *
**/

#include "stdafx.h"
#include "Form1.h"

using namespace MP3Tool;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());

	// Simple library test: debug variable 'text'

	ID3_Tag myTag;
	myTag.Link("..\\data\\song.mp3");

	return 0;

} // eo main