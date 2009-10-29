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
/*
	ID3_Tag::Iterator * tagIter = myTag.CreateIterator();
	ID3_Frame * myFrame = NULL;
	while( NULL != ( myFrame = tagIter->GetNext()))
	{
		ID3_Frame::Iterator * frameIter = myFrame->CreateIterator();
		ID3_Field * myField = NULL;
		while( NULL != ( myField = frameIter->GetNext()))
		{
			const char * text;
			if( NULL != myField)
			{
				ID3_FieldID fieldId = myField->GetID();
				ID3_FrameID frameId = myFrame->GetID();
				text = myField->GetRawText();
				if( myField->GetID() == ID3FID_CONTENTTYPE)
					text = myField->GetRawText();
				//ID3_TextEnc enc = myField->GetEncoding();
			}
		}
	}
*/
	return 0;

} // eo main