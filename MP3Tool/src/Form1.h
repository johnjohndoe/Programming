#pragma once
#if !defined ( FORM1_H )
#define FORM1_H


#include <vector>
#include <string>
#include <iostream>
#include "MP3Data.h"
#include "MP3DataGenerator.h"
#include "MP3Controller.h"
#include "Helper.h"
#include "WordNode.h"
#include "ID3_FrameID_LUT.h"


namespace MP3Tool 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Button ^ bt_clearsearch;
		System::Windows::Forms::Button ^ bt_clear;
		MP3Controller * myMP3Controller;
		IMP3DataGenerator * myMP3DataGenerator;


	public:
		Form1( void)
		{
			InitializeComponent();
			myMP3Controller = new MP3Controller();
		}

	protected:
		~Form1()
		{
			if ( components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^  myListBox;

	private: System::Windows::Forms::Button^  btLoadFiles;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  lb_Interpret;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lb_Album;

	private: System::Windows::Forms::Label^  lb_Genre;
	private: System::Windows::Forms::Label^  lb_Track;
	private: System::Windows::Forms::Label^  lb_Year;
	private: System::Windows::Forms::TextBox^  tb_Interpret;
	private: System::Windows::Forms::TextBox^  tb_Title;
	private: System::Windows::Forms::TextBox^  tb_Album;
	private: System::Windows::Forms::TextBox^  tb_Genre;
	private: System::Windows::Forms::TextBox^  tb_Track;
	private: System::Windows::Forms::TextBox^  tb_Year;
	private: System::Windows::Forms::Label^  lb_countText;
	private: System::Windows::Forms::Label^  lb_count;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::Button^  bt_delete;
	private: System::Windows::Forms::TextBox^  searchfield;
	private: System::Windows::Forms::Label^  label3;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->myListBox = (gcnew System::Windows::Forms::ListBox());
			this->btLoadFiles = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lb_Interpret = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lb_Album = (gcnew System::Windows::Forms::Label());
			this->lb_Genre = (gcnew System::Windows::Forms::Label());
			this->lb_Track = (gcnew System::Windows::Forms::Label());
			this->lb_Year = (gcnew System::Windows::Forms::Label());
			this->tb_Interpret = (gcnew System::Windows::Forms::TextBox());
			this->tb_Title = (gcnew System::Windows::Forms::TextBox());
			this->tb_Album = (gcnew System::Windows::Forms::TextBox());
			this->tb_Genre = (gcnew System::Windows::Forms::TextBox());
			this->tb_Track = (gcnew System::Windows::Forms::TextBox());
			this->tb_Year = (gcnew System::Windows::Forms::TextBox());
			this->lb_countText = (gcnew System::Windows::Forms::Label());
			this->lb_count = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->bt_delete = (gcnew System::Windows::Forms::Button());
			this->searchfield = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->bt_clearsearch = (gcnew System::Windows::Forms::Button());
			this->bt_clear = (gcnew System::Windows::Forms::Button());
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// myListBox
			// 
			this->myListBox->FormattingEnabled = true;
			this->myListBox->HorizontalScrollbar = true;
			this->myListBox->Location = System::Drawing::Point(12, 51);
			this->myListBox->Name = L"myListBox";
			this->myListBox->Size = System::Drawing::Size(314, 173);
			this->myListBox->TabIndex = 1;
			this->myListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::myListBox_SelectedIndexChanged);
			// 
			// btLoadFiles
			// 
			this->btLoadFiles->Location = System::Drawing::Point(455, 8);
			this->btLoadFiles->Name = L"btLoadFiles";
			this->btLoadFiles->Size = System::Drawing::Size(299, 23);
			this->btLoadFiles->TabIndex = 3;
			this->btLoadFiles->Text = L"Open MP3\'s";
			this->btLoadFiles->UseVisualStyleBackColor = true;
			this->btLoadFiles->Click += gcnew System::EventHandler(this, &Form1::btLoadFiles_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// lb_Interpret
			// 
			this->lb_Interpret->AutoSize = true;
			this->lb_Interpret->Location = System::Drawing::Point(476, 51);
			this->lb_Interpret->Name = L"lb_Interpret";
			this->lb_Interpret->Size = System::Drawing::Size(46, 13);
			this->lb_Interpret->TabIndex = 4;
			this->lb_Interpret->Text = L"Interpret";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(476, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Title";
			// 
			// lb_Album
			// 
			this->lb_Album->AutoSize = true;
			this->lb_Album->Location = System::Drawing::Point(476, 105);
			this->lb_Album->Name = L"lb_Album";
			this->lb_Album->Size = System::Drawing::Size(36, 13);
			this->lb_Album->TabIndex = 4;
			this->lb_Album->Text = L"Album";
			// 
			// lb_Genre
			// 
			this->lb_Genre->AutoSize = true;
			this->lb_Genre->Location = System::Drawing::Point(476, 128);
			this->lb_Genre->Name = L"lb_Genre";
			this->lb_Genre->Size = System::Drawing::Size(36, 13);
			this->lb_Genre->TabIndex = 4;
			this->lb_Genre->Text = L"Genre";
			// 
			// lb_Track
			// 
			this->lb_Track->AutoSize = true;
			this->lb_Track->Location = System::Drawing::Point(476, 156);
			this->lb_Track->Name = L"lb_Track";
			this->lb_Track->Size = System::Drawing::Size(35, 13);
			this->lb_Track->TabIndex = 4;
			this->lb_Track->Text = L"Track";
			// 
			// lb_Year
			// 
			this->lb_Year->AutoSize = true;
			this->lb_Year->Location = System::Drawing::Point(476, 182);
			this->lb_Year->Name = L"lb_Year";
			this->lb_Year->Size = System::Drawing::Size(29, 13);
			this->lb_Year->TabIndex = 4;
			this->lb_Year->Text = L"Year";
			// 
			// tb_Interpret
			// 
			this->tb_Interpret->Enabled = false;
			this->tb_Interpret->Location = System::Drawing::Point(528, 48);
			this->tb_Interpret->Name = L"tb_Interpret";
			this->tb_Interpret->Size = System::Drawing::Size(226, 20);
			this->tb_Interpret->TabIndex = 5;
			// 
			// tb_Title
			// 
			this->tb_Title->Enabled = false;
			this->tb_Title->Location = System::Drawing::Point(528, 75);
			this->tb_Title->Name = L"tb_Title";
			this->tb_Title->Size = System::Drawing::Size(226, 20);
			this->tb_Title->TabIndex = 5;
			// 
			// tb_Album
			// 
			this->tb_Album->Enabled = false;
			this->tb_Album->Location = System::Drawing::Point(528, 102);
			this->tb_Album->Name = L"tb_Album";
			this->tb_Album->Size = System::Drawing::Size(226, 20);
			this->tb_Album->TabIndex = 5;
			// 
			// tb_Genre
			// 
			this->tb_Genre->Enabled = false;
			this->tb_Genre->Location = System::Drawing::Point(528, 126);
			this->tb_Genre->Name = L"tb_Genre";
			this->tb_Genre->Size = System::Drawing::Size(226, 20);
			this->tb_Genre->TabIndex = 5;
			// 
			// tb_Track
			// 
			this->tb_Track->Enabled = false;
			this->tb_Track->Location = System::Drawing::Point(528, 152);
			this->tb_Track->Name = L"tb_Track";
			this->tb_Track->Size = System::Drawing::Size(226, 20);
			this->tb_Track->TabIndex = 5;
			// 
			// tb_Year
			// 
			this->tb_Year->Enabled = false;
			this->tb_Year->Location = System::Drawing::Point(528, 179);
			this->tb_Year->Name = L"tb_Year";
			this->tb_Year->Size = System::Drawing::Size(226, 20);
			this->tb_Year->TabIndex = 5;
			// 
			// lb_countText
			// 
			this->lb_countText->AutoSize = true;
			this->lb_countText->Location = System::Drawing::Point(525, 210);
			this->lb_countText->Name = L"lb_countText";
			this->lb_countText->Size = System::Drawing::Size(97, 13);
			this->lb_countText->TabIndex = 6;
			this->lb_countText->Text = L"Total count of files:";
			this->lb_countText->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// lb_count
			// 
			this->lb_count->AutoSize = true;
			this->lb_count->Location = System::Drawing::Point(452, 210);
			this->lb_count->Name = L"lb_count";
			this->lb_count->Size = System::Drawing::Size(0, 13);
			this->lb_count->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(377, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"List of files:";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 238);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(766, 22);
			this->statusStrip1->TabIndex = 8;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel1->Text = L"Selected file: ";
			// 
			// bt_delete
			// 
			this->bt_delete->Location = System::Drawing::Point(333, 200);
			this->bt_delete->Name = L"bt_delete";
			this->bt_delete->Size = System::Drawing::Size(75, 23);
			this->bt_delete->TabIndex = 9;
			this->bt_delete->Text = L"Delete";
			this->bt_delete->UseVisualStyleBackColor = true;
			this->bt_delete->Click += gcnew System::EventHandler(this, &Form1::bt_delete_clicked);
			// 
			// searchfield
			// 
			this->searchfield->Location = System::Drawing::Point(66, 10);
			this->searchfield->Name = L"searchfield";
			this->searchfield->Size = System::Drawing::Size(184, 20);
			this->searchfield->TabIndex = 11;
			this->searchfield->TextChanged += gcnew System::EventHandler(this, &Form1::searchfield_changed);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Search: ";
			// 
			// bt_clearsearch
			// 
			this->bt_clearsearch->Location = System::Drawing::Point(256, 8);
			this->bt_clearsearch->Name = L"bt_clearsearch";
			this->bt_clearsearch->Size = System::Drawing::Size(75, 23);
			this->bt_clearsearch->TabIndex = 14;
			this->bt_clearsearch->Text = L"Clear";
			this->bt_clearsearch->UseVisualStyleBackColor = true;
			this->bt_clearsearch->Click += gcnew System::EventHandler(this, &Form1::bt_clearsearch_Click);
			// 
			// bt_clear
			// 
			this->bt_clear->Location = System::Drawing::Point(333, 171);
			this->bt_clear->Name = L"bt_clear";
			this->bt_clear->Size = System::Drawing::Size(75, 23);
			this->bt_clear->TabIndex = 13;
			this->bt_clear->Text = L"Clear List";
			this->bt_clear->UseVisualStyleBackColor = true;
			this->bt_clear->Click += gcnew System::EventHandler(this, &Form1::bt_clear_clicked);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 260);
			this->Controls->Add(this->bt_clearsearch);
			this->Controls->Add(this->bt_clear);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->searchfield);
			this->Controls->Add(this->bt_delete);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lb_count);
			this->Controls->Add(this->lb_countText);
			this->Controls->Add(this->tb_Year);
			this->Controls->Add(this->tb_Track);
			this->Controls->Add(this->tb_Album);
			this->Controls->Add(this->tb_Genre);
			this->Controls->Add(this->tb_Title);
			this->Controls->Add(this->tb_Interpret);
			this->Controls->Add(this->lb_Year);
			this->Controls->Add(this->lb_Track);
			this->Controls->Add(this->lb_Genre);
			this->Controls->Add(this->lb_Album);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lb_Interpret);
			this->Controls->Add(this->btLoadFiles);
			this->Controls->Add(this->myListBox);
			this->Name = L"Form1";
			this->Text = L"MP3-Tag-Viewer";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			 // Converts .Net string to std::string
	private: std::string netstr2cppstr( System::String ^ managedString)
			 {
				 std::string out = (const char *) System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( managedString).ToPointer();
				 return out;
			 }
			 // File opener retrieves file list, generates tracklist and index, updates gui
	private: System::Void btLoadFiles_Click( System::Object ^ sender, System::EventArgs ^ e) 
			 {
				 openFileDialog1 = gcnew OpenFileDialog;
				 // @TODO Store the last directory selected to be reopened
				 openFileDialog1->InitialDirectory = "c:\\";
				 openFileDialog1->Filter = "mp3 files (*.mp3)|*.mp3|All files (*.*)|*.*";
				 openFileDialog1->FilterIndex =	1; 
				 openFileDialog1->RestoreDirectory = true;
				 openFileDialog1->Multiselect = true;
				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 System::Collections::IEnumerator ^ fileEnumerator = openFileDialog1->FileNames->GetEnumerator();
					 while ( fileEnumerator->MoveNext())
					 {
						 // Retrieve metadata and add them to the track list
						 System::String ^ filePath = ( System::String ^) fileEnumerator->Current;
						 myMP3Controller->addMP3( netstr2cppstr( filePath).c_str());
					 }
					 // Create new index
					 myMP3Controller->createIndex();
					 // Print word list
					 myMP3Controller->wordNodeList->print( std::ofstream("..\\data\\words.txt"));

					 // Update file count status
					 lb_count->Text = openFileDialog1->FileNames->Length.ToString();

					 // Update gui list
					 updateListBox( myMP3Controller->trackList);
				 }
				 // Reset selection if file opener is canceled
				 myListBox->SelectedIndex = -1;
			 }

	private: System::Void myListBox_SelectedIndexChanged( System::Object ^  sender, System::EventArgs ^ e) 
			 {
				 int selection = myListBox->SelectedIndex;
				 int max = myListBox->Items->Count;

				 // Stop handler when selected item is invalid
				 if( selection > max || selection < 0) return;

				 // Retrieve metadata from search result or tracklist
				 NodeList * searchResult = myMP3Controller->getSearchResult();
				 MP3Data * selectedMP3Data = NULL;
				 // Identify in search result
				 if( searchResult)
					 selectedMP3Data = searchResult->at( selection);
				 // Identify in track list
				 else
					 selectedMP3Data = myMP3Controller->trackList->at( selection);

				 clearTextboxes();
				 if( selectedMP3Data)
				 {
					 tb_Title->Text = gcnew System::String( selectedMP3Data->getTitle());
					 tb_Genre->Text = gcnew System::String( selectedMP3Data->getGenre());
					 tb_Interpret->Text = gcnew System::String( selectedMP3Data->getArtist());
					 tb_Track->Text = gcnew System::String( selectedMP3Data->getTracknumber());
					 tb_Year->Text = gcnew System::String( selectedMP3Data->getYear());
					 tb_Album->Text = gcnew System::String( selectedMP3Data->getAlbum());
					 toolStripStatusLabel1->Text += gcnew System::String( selectedMP3Data->getFilepath());
				 }
				 else
				 {
					 // Error: no MP3Data object.
					 tb_Title->Text = gcnew System::String( "Error: retrieving obj. See myListBox_SelectedIndexChanged");
				 }
			 }
			 // Empties the text boxes showing metadata information
	private: System::Void clearTextboxes()
			 {
				 tb_Title->Text = "<nothing selected>";
				 tb_Interpret->Text = "<nothing selected>";
				 tb_Album->Text = "<nothing selected>";
				 tb_Genre->Text = "<nothing selected>";
				 tb_Track->Text = "<nothing selected>";
				 tb_Year->Text = "<nothing selected>";
				 toolStripStatusLabel1->Text = "Selected file: ";
			 }
			 // Initiate a new index search
	private: System::Void searchfield_changed( System::Object ^ sender, System::EventArgs ^ e) 
			 {
				 processSearch();
			 }
			 // Delete the selected item
	private: System::Void bt_delete_clicked( System::Object ^ sender, System::EventArgs ^ e) 
			 {
				 int selection = myListBox->SelectedIndex;
				 int max = myListBox->Items->Count;

				 // Stop handler when selected item is invalid
				 if( selection > max || selection < 0)return;

				 if( selection >= 0)
				 {
					 // Remove item from gui list
					 myListBox->Items->RemoveAt( selection);
					 // Get the current search result
					 NodeList * searchResult = myMP3Controller->getSearchResult();
					 // No search result -> identify item in tracklist
					 if ( searchResult == NULL || searchResult->isEmpty())
					 {
						 
						 myMP3Controller->trackList->removeObj( myMP3Controller->trackList->at( selection));					 
						 myMP3Controller->createIndex();
					 }
					 // Search result available -> identify item in last search result
					 else
					 {
						 // Remove from track list after identifying in search result
						 myMP3Controller->trackList->removeObj( searchResult->at( selection));
						 // Update index
						 myMP3Controller->createIndex();
						 // Update search result
						 processSearch();
						 // Update gui list if new search result is available
						 if( searchResult = myMP3Controller->getSearchResult())
							 updateListBox( searchResult);
						 // Update gui list if new is empty considering the current search term as a filter
						 else
						 {
							 System::String ^ term = searchfield->Text;
							 unsigned int termLength = term->Length;
							 if( termLength == 0)
								 updateListBox( myMP3Controller->trackList);
						 }
					 }
					 // Reset selection
					 clearTextboxes();
				 }
			 }
			 // Resets all gui elements
	private: System::Void bt_clear_clicked( System::Object ^ sender, System::EventArgs ^ e) 
			 {
				 myListBox->Items->Clear();
				 clearTextboxes();
				 myMP3Controller->clearLists();
			 }
			 // Resets the search term
	private: System::Void bt_clearsearch_Click( System::Object ^ sender, System::EventArgs ^ e) 
			 {
				 // @TODO Crashes when track list is empty and clear search field is pressed.

				 // Reset gui elements
				 searchfield->Text = "";
				 clearTextboxes();
				 // Reset search result
				 myMP3Controller->searchResult = NULL;
				 // Load current track list
				 NodeList * tracklist = myMP3Controller->trackList;
				 if( !tracklist->isEmpty())
					 updateListBox( tracklist);
			 }
			 // Updates the gui list
	private: System::Void updateListBox( NodeList * t_nodelist)
			 {
				 myListBox->Items->Clear();
				 myListBox->Items->Add( gcnew System::String( t_nodelist->getFirst()->getTitle()));
				 while( t_nodelist->hasNext())
					 myListBox->Items->Add( gcnew System::String( t_nodelist->getNext()->getTitle()));
			 }
			 // Processes a new search
	private: System::Void processSearch( void)
			 {
				 System::String ^ term = searchfield->Text->ToLower();
				 unsigned int termLength = term->Length;

				 if( termLength > 0)
				 {
					 // Retrieve search term from gui element
					 //NodeList * found = myMP3Controller->getSearchResult( netstr2cppstr( term).c_str());
					 NodeList * found = myMP3Controller->getSearchResult( netstr2cppstr( term).c_str());
					 if( found && found->getFirst() != NULL)
					 {
						 // One or more element(s) found
						 myListBox->Items->Clear();
						updateListBox(found);
					 }
					 else
					 {
						 // No element found
						 myListBox->Items->Clear();
						 clearTextboxes();
					 }
				 }
				 else
				 {
					 // Empty search term.
					 searchfield->Text = "";
					 myMP3Controller->searchResult = NULL;
					 updateListBox( myMP3Controller->trackList);
				 }
			 }
	private: System::Void label1_Click( System::Object ^ sender, System::EventArgs ^ e)
			 {
			 }
	private: System::Void Form1_Load( System::Object ^ sender, System::EventArgs ^ e)
			 {
			 }


	};  // eo Form1 class
}// eo namespace MP3Tool

#endif;