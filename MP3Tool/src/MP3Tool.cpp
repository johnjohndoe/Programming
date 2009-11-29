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
#include "MP3Data.h"
//#include "MP3DataVector.h"
#include "GenericList.h"
#include "Node.h"
#include "NodeList.h"
#include "Helper.h"
#include "ArrayVector.h"
#include "WordNodeList.h"
#include <ostream>
#include <vector>

using namespace MP3Tool;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	// Debugging ArryVector
	ArrayVector * myArrayVector = new ArrayVector();
	myArrayVector->addItem(new std::string("BlabLBub"));
	myArrayVector->addItem(new std::string("Borebs"));
	myArrayVector->addItem(new std::string("Akex"));
	myArrayVector->addItem(new std::string("cccccc"));
	myArrayVector->getItem(0);
	myArrayVector->resize(20);
	myArrayVector->print( std::ofstream("..\\data\\array.txt"));

		// -------------------------------------------- DEBUGGING TOKENIZER
	const char * str = "das ist  nur u ein test ";
	std::vector<std::string> tokens;
	Helper::tokenize( std::string( str), tokens);
	
	//GenericList<WordNode> * wnl = new GenericList<WordNode>;

	WordNodeList * wl = new WordNodeList();
	for( unsigned int i=0; i < tokens.size(); ++i)
	{
		const char * tmp = tokens.at(  i).c_str();
		// wl->insert( tmp);
	}
	wl->print( std::ofstream("..\\data\\words.txt"));


	// -------------------------------------------- END OF DEBUGGING TOKENIZER

	// -------------------------------------------- DEBUGGING NODE LIST

	NodeList * nl = new NodeList();
	MP3Data * data1 = new MP3Data();	data1->setTitle( "alpha");
	MP3Data * data2 = new MP3Data();	data2->setTitle( "aber davor");
	MP3Data * data3 = new MP3Data();	data3->setTitle( "ac dazwischen");
	MP3Data * data4 = new MP3Data();	data4->setTitle( "berta");
	MP3Data * data5 = new MP3Data();	data5->setTitle( "anton");

	nl->insert( data2);	
	nl->insert( data1);	
	nl->insert( data4);	
	nl->insert( data3);
	nl->insert( data5);

	//nl->print( std::ofstream("..\\data\\nodes.txt"));

	const char * alpha = "anton";
	MP3Data * result = nl->find( alpha);

	// Add breakpoint here to see the node disappearing.
	nl->remove( alpha);
	nl->print( std::ofstream("..\\data\\nodes.txt"));


	// -------------------------------------------- END OF DEBUGGING NODE LIST



	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault( false); 

	// Create the main window and run it
	Application::Run( gcnew Form1());


	return 0;

} // eo main