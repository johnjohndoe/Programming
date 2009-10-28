#pragma once
#if !defined ( FORM1_H )
#define FORM1_H
#include <map>
#include "MP3Connector.h"

#include "ID3_FrameID_LUT.h"

namespace MP3Tool {

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
		MP3Connector * myMP3Connector;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			myMP3Connector = new MP3Connector();
		}


		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btGetMp3Information;
	private: System::Windows::Forms::ListBox^  myListBox;
	private: System::Windows::Forms::TextBox^  myTextBox;
	private: System::Windows::Forms::Button^  btLoadFiles;
	public: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  lb_Interpret;
	public: 

	public: 
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




	protected: 

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
			this->btGetMp3Information = (gcnew System::Windows::Forms::Button());
			this->myListBox = (gcnew System::Windows::Forms::ListBox());
			this->myTextBox = (gcnew System::Windows::Forms::TextBox());
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
			this->SuspendLayout();
			// 
			// btGetMp3Information
			// 
			this->btGetMp3Information->Location = System::Drawing::Point(12, 238);
			this->btGetMp3Information->Name = L"btGetMp3Information";
			this->btGetMp3Information->Size = System::Drawing::Size(612, 23);
			this->btGetMp3Information->TabIndex = 0;
			this->btGetMp3Information->Text = L"Get MP3 information";
			this->btGetMp3Information->UseVisualStyleBackColor = true;
			this->btGetMp3Information->Click += gcnew System::EventHandler(this, &Form1::btGetMp3Information_Click);
			// 
			// myListBox
			// 
			this->myListBox->FormattingEnabled = true;
			this->myListBox->Location = System::Drawing::Point(12, 51);
			this->myListBox->Name = L"myListBox";
			this->myListBox->Size = System::Drawing::Size(314, 173);
			this->myListBox->TabIndex = 1;
			this->myListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::myListBox_SelectedIndexChanged);
			// 
			// myTextBox
			// 
			this->myTextBox->Location = System::Drawing::Point(12, 12);
			this->myTextBox->Name = L"myTextBox";
			this->myTextBox->Size = System::Drawing::Size(504, 20);
			this->myTextBox->TabIndex = 2;
			// 
			// btLoadFiles
			// 
			this->btLoadFiles->Location = System::Drawing::Point(549, 10);
			this->btLoadFiles->Name = L"btLoadFiles";
			this->btLoadFiles->Size = System::Drawing::Size(75, 23);
			this->btLoadFiles->TabIndex = 3;
			this->btLoadFiles->Text = L"...";
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
			this->lb_Interpret->Location = System::Drawing::Point(346, 51);
			this->lb_Interpret->Name = L"lb_Interpret";
			this->lb_Interpret->Size = System::Drawing::Size(46, 13);
			this->lb_Interpret->TabIndex = 4;
			this->lb_Interpret->Text = L"Interpret";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(346, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Title";
			// 
			// lb_Album
			// 
			this->lb_Album->AutoSize = true;
			this->lb_Album->Location = System::Drawing::Point(346, 105);
			this->lb_Album->Name = L"lb_Album";
			this->lb_Album->Size = System::Drawing::Size(36, 13);
			this->lb_Album->TabIndex = 4;
			this->lb_Album->Text = L"Album";
			// 
			// lb_Genre
			// 
			this->lb_Genre->AutoSize = true;
			this->lb_Genre->Location = System::Drawing::Point(346, 128);
			this->lb_Genre->Name = L"lb_Genre";
			this->lb_Genre->Size = System::Drawing::Size(36, 13);
			this->lb_Genre->TabIndex = 4;
			this->lb_Genre->Text = L"Genre";
			// 
			// lb_Track
			// 
			this->lb_Track->AutoSize = true;
			this->lb_Track->Location = System::Drawing::Point(346, 156);
			this->lb_Track->Name = L"lb_Track";
			this->lb_Track->Size = System::Drawing::Size(35, 13);
			this->lb_Track->TabIndex = 4;
			this->lb_Track->Text = L"Track";
			// 
			// lb_Year
			// 
			this->lb_Year->AutoSize = true;
			this->lb_Year->Location = System::Drawing::Point(346, 182);
			this->lb_Year->Name = L"lb_Year";
			this->lb_Year->Size = System::Drawing::Size(29, 13);
			this->lb_Year->TabIndex = 4;
			this->lb_Year->Text = L"Year";
			// 
			// tb_Interpret
			// 
			this->tb_Interpret->Location = System::Drawing::Point(398, 48);
			this->tb_Interpret->Name = L"tb_Interpret";
			this->tb_Interpret->Size = System::Drawing::Size(226, 20);
			this->tb_Interpret->TabIndex = 5;
			// 
			// tb_Title
			// 
			this->tb_Title->Location = System::Drawing::Point(398, 75);
			this->tb_Title->Name = L"tb_Title";
			this->tb_Title->Size = System::Drawing::Size(226, 20);
			this->tb_Title->TabIndex = 5;
			// 
			// tb_Album
			// 
			this->tb_Album->Location = System::Drawing::Point(398, 102);
			this->tb_Album->Name = L"tb_Album";
			this->tb_Album->Size = System::Drawing::Size(226, 20);
			this->tb_Album->TabIndex = 5;
			// 
			// tb_Genre
			// 
			this->tb_Genre->Location = System::Drawing::Point(398, 125);
			this->tb_Genre->Name = L"tb_Genre";
			this->tb_Genre->Size = System::Drawing::Size(226, 20);
			this->tb_Genre->TabIndex = 5;
			// 
			// tb_Track
			// 
			this->tb_Track->Location = System::Drawing::Point(398, 152);
			this->tb_Track->Name = L"tb_Track";
			this->tb_Track->Size = System::Drawing::Size(226, 20);
			this->tb_Track->TabIndex = 5;
			// 
			// tb_Year
			// 
			this->tb_Year->Location = System::Drawing::Point(398, 179);
			this->tb_Year->Name = L"tb_Year";
			this->tb_Year->Size = System::Drawing::Size(226, 20);
			this->tb_Year->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 273);
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
			this->Controls->Add(this->myTextBox);
			this->Controls->Add(this->myListBox);
			this->Controls->Add(this->btGetMp3Information);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	private: 
	
		System::Void btGetMp3Information_Click( System::Object^  sender, System::EventArgs^  e)
		{
			// Remove all items before adding new
			myListBox->Items->Clear();

			// @TODO Substitute with conversion System::String -> const char *
			//const char * textFromMyTextBox = netstr2cppstr( myTextBox->Text);
			const char * textFromMyTextBox = "..\\data\\song.mp3";

			if( myMP3Connector->getFile( textFromMyTextBox))
			{
				myListBox->Items->Add( "// File read successfully.");
				// Read metadata from file to MP3Connector
				std::map<ID3_FrameID, std::string> * metadata = myMP3Connector->getMetadata();

				// If not null
				if( metadata)
				{
					std::map<ID3_FrameID, std::string>::iterator mdIter = metadata->begin();
					String ^ tempKey;
					String ^ tempValue;
					ID3_FrameID_LUT * myLUT = new ID3_FrameID_LUT();
					for ( mdIter; mdIter != metadata->end(); ++mdIter)
					{
						tempKey = gcnew String( myLUT->getRealname( mdIter->first));
						// @TODO Translate genre from number into string
						tempValue = gcnew String( (mdIter->second).c_str());
						myListBox->Items->Add( String::Format( "{0}: {1}", tempKey, tempValue));
					}
				}

				
				
				/*
				// Get single fields
				String ^ tempTitle = gcnew String( myMP3Connector->getTitle());
				myListBox->Items->Add( String::Format( "Title: {0}", tempTitle));
				String ^ tempAlbum = gcnew String( myMP3Connector->getAlbum());
				myListBox->Items->Add( String::Format( "Album: {0}", tempAlbum));
				String ^ tempArtist = gcnew String( myMP3Connector->getArtist());
				myListBox->Items->Add( String::Format( "Lead artist: {0}", tempArtist));
				String ^ tempTrack = gcnew String( myMP3Connector->getTrack());
				myListBox->Items->Add( String::Format( "Track num: {0}", tempTrack));
				String ^ tempYear = gcnew String( myMP3Connector->getYear());
				myListBox->Items->Add( String::Format( "Year: {0}", tempYear));
				String ^ tempGenre = gcnew String( myMP3Connector->getGenre());
				myListBox->Items->Add( String::Format( "Genre: {0}", tempGenre));
				*/
			}
			else
			{
				myListBox->Items->Add( "// Error reading file.");
			}
		}
		// @see: http://msdn.microsoft.com/en-us/library/system.runtime.interopservices.marshal.stringtohglobaluni.aspx
		const char * netstr2cppstr( System::String ^ managedString)
		{
			std::string out = (const char *) System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( managedString).ToPointer();
			return out.c_str();
		}

private: System::Void btLoadFiles_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //System::Windows::Forms::DialogResult dr;

			 openFileDialog1 = gcnew OpenFileDialog;
			 openFileDialog1->InitialDirectory = "c:\\";
			 openFileDialog1->Filter = "mp3 files (*.mp3)|*.mp3|All files (*.*)|*.*";
			 openFileDialog1->FilterIndex =	2; // Muss auf 1 wenn MP3 die Standartauswahl sein soll.
			 openFileDialog1->RestoreDirectory = true;
			 openFileDialog1->Multiselect = true;

			 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			 {
				 // erzeugt aus dem FileNames-Array ein IEnumerator
				 System::Collections::IEnumerator^ a_enumerator = openFileDialog1->FileNames->GetEnumerator();
				 while (a_enumerator->MoveNext())
				 {
					// iteriert durch das Array und gibt jeden Eintrag in die ItemLIst aus
					 // Muss in den Controller ausgelagert werden
					 myListBox->Items->Add(a_enumerator->Current);
				 }
			 }
		}
private: System::Void myListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 // Test -> wird wird beim markieren eines Eintrages aus myListBox der eintrag genommen und
			 // in das Feld tb-Album übertragen.
			 // TODO: auslesen der Datei, nachschauen in der noch zu erstellenen map<String dateiname, MP3Connector myConn>, 
			 // das passende MP3Connector-Objekt auslesen und die werte in die Passenden Felder eintragen.

			 String ^ temp_string = myListBox->SelectedItem->ToString();
			 tb_Album->Text = temp_string;
		 }
};
}
#endif
