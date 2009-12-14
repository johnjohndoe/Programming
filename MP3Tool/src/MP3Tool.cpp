/**
 * \file	src\MP3Tool.cpp
 *
 * \brief	Main project file.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
 *
**/

#include "stdafx.h"
#include "MP3ToolGUI.h"


using namespace MP3Tool;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault( false); 

	// Create the main window and run it
	Application::Run( gcnew MP3ToolGUI());


	return 0;

} // eo main