#pragma once
#if !defined ( MP3TOOLGUI_H )
#define MP3TOOLGUI_H

#include <string>
#include <iostream>
#include "MP3Data.h"
#include "MP3DataGenerator.h"
#include "MP3Controller.h"
#include "Helper.h"
#include "WordNode.h"
#include "ID3_FrameID_LUT.h"
#include "TrackManagerFactory.h"
#include "ITrackManager.h"
#include "TrackInfoNode.h"

namespace MP3Tool 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// \brief Holds the gui elements and event handlers.
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MP3ToolGUI : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Button ^ bt_clearsearch;
		System::Windows::Forms::Button ^ bt_clear;
		ITrackManager * myTrackManager;
		TSearchID mySearchID;
		CTrackInfo * m_trackData;


	public:
		MP3ToolGUI( void)
		{
			InitializeComponent();
			myTrackManager = TrackManagerFactory::getTrackManager();
			mySearchID = INVALID_SEARCH_ID;
			m_trackData = new CTrackInfo;
		}

	protected:
		~MP3ToolGUI()
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
	private: System::Windows::Forms::TextBox^  tb_Interpret;
	private: System::Windows::Forms::TextBox^  tb_Title;
	private: System::Windows::Forms::TextBox^  tb_Album;
	private: System::Windows::Forms::Label^  lb_countText;
	private: System::Windows::Forms::Label^  lb_count;
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
			this->tb_Interpret = (gcnew System::Windows::Forms::TextBox());
			this->tb_Title = (gcnew System::Windows::Forms::TextBox());
			this->tb_Album = (gcnew System::Windows::Forms::TextBox());
			this->lb_countText = (gcnew System::Windows::Forms::Label());
			this->lb_count = (gcnew System::Windows::Forms::Label());
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
			this->myListBox->Location = System::Drawing::Point(12, 38);
			this->myListBox->Name = L"myListBox";
			this->myListBox->Size = System::Drawing::Size(458, 277);
			this->myListBox->TabIndex = 1;
			this->myListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MP3ToolGUI::myListBox_SelectedIndexChanged);
			// 
			// btLoadFiles
			// 
			this->btLoadFiles->Location = System::Drawing::Point(528, 8);
			this->btLoadFiles->Name = L"btLoadFiles";
			this->btLoadFiles->Size = System::Drawing::Size(226, 23);
			this->btLoadFiles->TabIndex = 3;
			this->btLoadFiles->Text = L"Open MP3\'s";
			this->btLoadFiles->UseVisualStyleBackColor = true;
			this->btLoadFiles->Click += gcnew System::EventHandler(this, &MP3ToolGUI::btLoadFiles_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// lb_Interpret
			// 
			this->lb_Interpret->AutoSize = true;
			this->lb_Interpret->Location = System::Drawing::Point(476, 44);
			this->lb_Interpret->Name = L"lb_Interpret";
			this->lb_Interpret->Size = System::Drawing::Size(46, 13);
			this->lb_Interpret->TabIndex = 4;
			this->lb_Interpret->Text = L"Interpret";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(476, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Title";
			// 
			// lb_Album
			// 
			this->lb_Album->AutoSize = true;
			this->lb_Album->Location = System::Drawing::Point(476, 98);
			this->lb_Album->Name = L"lb_Album";
			this->lb_Album->Size = System::Drawing::Size(36, 13);
			this->lb_Album->TabIndex = 4;
			this->lb_Album->Text = L"Album";
			// 
			// tb_Interpret
			// 
			this->tb_Interpret->Enabled = false;
			this->tb_Interpret->Location = System::Drawing::Point(528, 41);
			this->tb_Interpret->Name = L"tb_Interpret";
			this->tb_Interpret->Size = System::Drawing::Size(226, 20);
			this->tb_Interpret->TabIndex = 5;
			// 
			// tb_Title
			// 
			this->tb_Title->Enabled = false;
			this->tb_Title->Location = System::Drawing::Point(528, 68);
			this->tb_Title->Name = L"tb_Title";
			this->tb_Title->Size = System::Drawing::Size(226, 20);
			this->tb_Title->TabIndex = 5;
			// 
			// tb_Album
			// 
			this->tb_Album->Enabled = false;
			this->tb_Album->Location = System::Drawing::Point(528, 95);
			this->tb_Album->Name = L"tb_Album";
			this->tb_Album->Size = System::Drawing::Size(226, 20);
			this->tb_Album->TabIndex = 5;
			// 
			// lb_countText
			// 
			this->lb_countText->AutoSize = true;
			this->lb_countText->Location = System::Drawing::Point(634, 300);
			this->lb_countText->Name = L"lb_countText";
			this->lb_countText->Size = System::Drawing::Size(97, 13);
			this->lb_countText->TabIndex = 6;
			this->lb_countText->Text = L"Total count of files:";
			// 
			// lb_count
			// 
			this->lb_count->AutoSize = true;
			this->lb_count->Location = System::Drawing::Point(734, 300);
			this->lb_count->Name = L"lb_count";
			this->lb_count->Size = System::Drawing::Size(13, 13);
			this->lb_count->TabIndex = 4;
			this->lb_count->Text = L"0";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 328);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(766, 22);
			this->statusStrip1->TabIndex = 8;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(76, 17);
			//this->toolStripStatusLabel1->Text = L"Selected file: ";
			// 
			// bt_delete
			// 
			this->bt_delete->Location = System::Drawing::Point(479, 290);
			this->bt_delete->Name = L"bt_delete";
			this->bt_delete->Size = System::Drawing::Size(75, 23);
			this->bt_delete->TabIndex = 9;
			this->bt_delete->Text = L"Delete";
			this->bt_delete->UseVisualStyleBackColor = true;
			this->bt_delete->Click += gcnew System::EventHandler(this, &MP3ToolGUI::bt_delete_clicked);
			// 
			// searchfield
			// 
			this->searchfield->Location = System::Drawing::Point(66, 10);
			this->searchfield->Name = L"searchfield";
			this->searchfield->Size = System::Drawing::Size(323, 20);
			this->searchfield->TabIndex = 11;
			this->searchfield->TextChanged += gcnew System::EventHandler(this, &MP3ToolGUI::searchfield_changed);
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
			this->bt_clearsearch->Location = System::Drawing::Point(395, 8);
			this->bt_clearsearch->Name = L"bt_clearsearch";
			this->bt_clearsearch->Size = System::Drawing::Size(75, 23);
			this->bt_clearsearch->TabIndex = 14;
			this->bt_clearsearch->Text = L"Clear";
			this->bt_clearsearch->UseVisualStyleBackColor = true;
			this->bt_clearsearch->Click += gcnew System::EventHandler(this, &MP3ToolGUI::bt_clearsearch_Click);
			// 
			// bt_clear
			// 
			this->bt_clear->Location = System::Drawing::Point(479, 261);
			this->bt_clear->Name = L"bt_clear";
			this->bt_clear->Size = System::Drawing::Size(75, 23);
			this->bt_clear->TabIndex = 13;
			this->bt_clear->Text = L"Clear list";
			this->bt_clear->UseVisualStyleBackColor = true;
			this->bt_clear->Click += gcnew System::EventHandler(this, &MP3ToolGUI::bt_clear_clicked);
			// 
			// MP3ToolGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 350);
			this->Controls->Add(this->bt_clearsearch);
			this->Controls->Add(this->bt_clear);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->searchfield);
			this->Controls->Add(this->bt_delete);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->lb_count);
			this->Controls->Add(this->lb_countText);
			this->Controls->Add(this->tb_Album);
			this->Controls->Add(this->tb_Title);
			this->Controls->Add(this->tb_Interpret);
			this->Controls->Add(this->lb_Album);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lb_Interpret);
			this->Controls->Add(this->btLoadFiles);
			this->Controls->Add(this->myListBox);
			this->Name = L"MP3ToolGUI";
			this->Text = L"MP3-Tag-Viewer";
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
			 // File opener retrieves file list, generates track list and index, updates gui
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
						 myTrackManager->addTrack( netstr2cppstr( filePath).c_str(), *m_trackData );
						 //tb_Interpret->Text = gcnew System::String( m_trackData->mAlbum.c_str());  // # 2-b-Del
					 }
					 // Update gui list and file count

					 unsigned int numTracks = updateListBox( "", mySearchID);

					 // Update status message
					 if( numTracks > 1)
						 toolStripStatusLabel1->Text = "The Database now contains " + numTracks + " tracks.";
					 else
						 toolStripStatusLabel1->Text = "The Database now contains " + numTracks + " track.";
					 // Reset search
					 searchfield->Text = "";
					 lb_count->Text = "" + numTracks;
				 }
				 else
				 {
					 toolStripStatusLabel1->Text = "No tracks loaded.";
					 lb_count->Text =  L"0";
				 }
				 updateMetadataFields();
				 // Reset selection if file opener is canceled
				 myListBox->SelectedIndex = -1;
			 }
			 // Change handler for the list box.
	private: System::Void myListBox_SelectedIndexChanged( System::Object ^  sender, System::EventArgs ^ e) 
			 {
			 	 TrackInfoNode ^ selection = (TrackInfoNode ^) myListBox->SelectedItem;
				 updateMetadataFields( selection);
			 }
			 // Initiate a new index search
	private: System::Void searchfield_changed( System::Object ^ sender, System::EventArgs ^ e) 
			 {
				 processSearch();
			 }
			 // Delete the selected item
	private: System::Void bt_delete_clicked( System::Object ^ sender, System::EventArgs ^ e) 
			 {
				 if( myListBox->SelectedIndex >= 0)
				 {
					 deleteTrack( ( ( TrackInfoNode ^)myListBox->SelectedItem)->getTrackInfo()->mIndex);
				 }
				 processSearch();
			 }
			 // Removes a single track from the track list.
	private: System::Void deleteTrack( unsigned int trackID)
			 {
				 myTrackManager->removeTrack( trackID);
			 }
			 // Resets all gui elements
	private: System::Void bt_clear_clicked( System::Object ^ sender, System::EventArgs ^ e) 
			 {	
				 //updateListBox("", mySearchID);
				 System::Collections::IEnumerator ^ myEnum = myListBox->Items->GetEnumerator();
				 //myEnum->Reset();
				int t_id = 0;
				unsigned int deleteCount = 0;
				 while(myEnum->MoveNext())
				 {
					t_id = ((TrackInfoNode ^)myEnum->Current)->getTrackInfo()->mIndex;
					if(myTrackManager->removeTrack(t_id)) deleteCount++;

				 }
				 searchfield->Text = "";
				 updateMetadataFields();
				 lb_count->Text = "" + updateListBox("", mySearchID);
				 toolStripStatusLabel1->Text = "Successfully " + deleteCount + " tracks removed.";
			 }
			 // Resets the search term
	private: System::Void bt_clearsearch_Click( System::Object ^ sender, System::EventArgs ^ e) 
			 {				 
				 myTrackManager->trackSearchStop( mySearchID);
				 mySearchID = INVALID_SEARCH_ID;
				 // Reset gui elements
				 searchfield->Text = "";
				 updateMetadataFields();
				 // Load current track list
				 updateListBox( "", mySearchID);
			 }
			 // Updates the gui list
	private: int updateListBox( const string & pTitleBegin, TSearchID searchID)
			 {
				 myListBox->Items->Clear();
				 int t_SearchID = mySearchID;
				 int searchCount = myTrackManager->trackSearchStart( pTitleBegin, t_SearchID);
				 mySearchID = t_SearchID;
				 bool t_hasNext = true;
				 while (true)
				 {
					 t_hasNext = myTrackManager->trackGetNext( searchID, *m_trackData);
					 if( !t_hasNext) break;
					 myListBox->Items->Add( gcnew TrackInfoNode( *m_trackData));
				 }
			 return searchCount;
			 }
			 // Processes a new search
	private: System::Void processSearch( void)
			 {
				 System::String ^ term = searchfield->Text->ToLower();
				 unsigned int termLength = term->Length;
				 int t_Search = mySearchID;
				 if( termLength > 0)
				 {
					 //term = netstr2cppstr( term).c_str();
				 }
				 else
				 {
					 t_Search = -1;
					 term = "";
				 } 
				 myTrackManager->trackSearchStart( netstr2cppstr( term).c_str(), t_Search);
				 updateListBox( netstr2cppstr( term).c_str(), t_Search);
				 mySearchID = t_Search;
			 }
			 // Updates the metadata fields with the information of the currently selected track.
	private: System::Void updateMetadataFields( TrackInfoNode ^ selection)
			 {
				 if( selection)
				 {
					 tb_Title->Text = gcnew System::String( selection->getTrackInfo()->mTitle.c_str());
					 tb_Interpret->Text = gcnew System::String( selection->getTrackInfo()->mInterpret.c_str());
					 tb_Album->Text = gcnew System::String( selection->getTrackInfo()->mAlbum.c_str());
					 toolStripStatusLabel1->Text = "Selected file: " + tb_Interpret->Text + " - " + tb_Title->Text;
				 }
				 else
				 {
					 tb_Title->Text = "<nothing selected>";
					 tb_Interpret->Text = "<nothing selected>";
					 tb_Album->Text = "<nothing selected>";
					 toolStripStatusLabel1->Text = "No track selected.";
				 }
			 }
			 // Updates the metadata fields with the information of the currently selected track.
	private: System::Void updateMetadataFields()
			 {
				 // Null object.
				 TrackInfoNode ^ selection;
				 updateMetadataFields( selection);
			 }


	};  // eo MP3ToolGUI class
}// eo namespace MP3Tool

#endif;