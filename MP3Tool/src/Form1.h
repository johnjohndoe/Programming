#pragma once
#if !defined ( FORM1_H )
#define FORM1_H


#include <map>
#include <string>
#include "MP3Data.h"
#include "MP3DataGenerator.h"
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
		MP3DataGenerator * myMP3DataGenerator;

	public:
		Form1(void)
		{
			InitializeComponent();
			
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
			this->btLoadFiles->Location = System::Drawing::Point(77, 8);
			this->btLoadFiles->Name = L"btLoadFiles";
			this->btLoadFiles->Size = System::Drawing::Size(677, 23);
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
			this->tb_Interpret->Location = System::Drawing::Point(528, 48);
			this->tb_Interpret->Name = L"tb_Interpret";
			this->tb_Interpret->Size = System::Drawing::Size(226, 20);
			this->tb_Interpret->TabIndex = 5;
			// 
			// tb_Title
			// 
			this->tb_Title->Location = System::Drawing::Point(528, 75);
			this->tb_Title->Name = L"tb_Title";
			this->tb_Title->Size = System::Drawing::Size(226, 20);
			this->tb_Title->TabIndex = 5;
			// 
			// tb_Album
			// 
			this->tb_Album->Location = System::Drawing::Point(528, 102);
			this->tb_Album->Name = L"tb_Album";
			this->tb_Album->Size = System::Drawing::Size(226, 20);
			this->tb_Album->TabIndex = 5;
			// 
			// tb_Genre
			// 
			this->tb_Genre->Location = System::Drawing::Point(528, 126);
			this->tb_Genre->Name = L"tb_Genre";
			this->tb_Genre->Size = System::Drawing::Size(226, 20);
			this->tb_Genre->TabIndex = 5;
			// 
			// tb_Track
			// 
			this->tb_Track->Location = System::Drawing::Point(528, 152);
			this->tb_Track->Name = L"tb_Track";
			this->tb_Track->Size = System::Drawing::Size(226, 20);
			this->tb_Track->TabIndex = 5;
			// 
			// tb_Year
			// 
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
			this->label1->Location = System::Drawing::Point(12, 13);
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
			this->toolStripStatusLabel1->Size = System::Drawing::Size(109, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 260);
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
	private: 
		std::string netstr2cppstr( System::String ^ managedString)
		{
			std::string out = (const char *) System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( managedString).ToPointer();
			return out;
		}

	private: System::Void btLoadFiles_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				MP3Data* myMP3Data = new MP3Data();

				 myListBox->Items->Clear();
				 openFileDialog1 = gcnew OpenFileDialog;
				 // @TODO Store the last directory selected to be reopened
				 openFileDialog1->InitialDirectory = "c:\\";
				 openFileDialog1->Filter = "mp3 files (*.mp3)|*.mp3|All files (*.*)|*.*";
				 openFileDialog1->FilterIndex =	1; 
				 openFileDialog1->RestoreDirectory = true;
				 openFileDialog1->Multiselect = true;
				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 System::Collections::IEnumerator^ a_enumerator = openFileDialog1->FileNames->GetEnumerator();
					 int zaehler = 0;
					 while ( a_enumerator->MoveNext())
					 {
						 myListBox->Items->Add( a_enumerator->Current);
					 }
					 lb_count->Text = openFileDialog1->FileNames->Length.ToString();
				 }
				 myListBox->SelectedIndex = -1;
				 tb_Interpret->Text = "";
				 tb_Title->Text = "";
				 tb_Album->Text = "";
				 tb_Track->Text = "";
				 tb_Year->Text = "";
				 tb_Genre->Text = "";
			 }

	private: System::Void myListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 int selection = myListBox->SelectedIndex;
				 int max = myListBox->Items->Count;

				 // Stop handler when selected item is invalid
				 if( selection > max || selection < 0)
					 return;

				 clearTextboxes();

				 String ^ currentItem = myListBox->SelectedItem->ToString();
				 std::string path = netstr2cppstr( currentItem);
				 const char * textFromMyTextBox = path.c_str();	

				 myMP3DataGenerator = new MP3DataGenerator();

				 if( MP3Data * myMP3Data = myMP3DataGenerator->readMetadata( textFromMyTextBox))
				 {
					 String ^ tempValue;
					 tempValue = gcnew String( myMP3Data->getTitle());
					 tb_Title->Text = tempValue;
					 tempValue = gcnew String( myMP3Data->getArtist());
					 tb_Interpret->Text = tempValue;
					 tempValue = gcnew String( myMP3Data->getAlbum());
					 tb_Album->Text = tempValue;
					 tempValue = gcnew String( myMP3Data->getYear());
					 tb_Year->Text = tempValue;
					 tempValue = gcnew String( myMP3Data->getGenre());
					 tb_Genre->Text = tempValue;
					 tempValue = gcnew String( myMP3Data->getTracknumber());
					 tb_Track->Text = tempValue;

					 myMP3Data->print( std::ofstream( "..\\data\\mp3data.txt"));
				 }
			 } // eo fn

	private: System::Void clearTextboxes()
			 {
				 tb_Title->Text = "<no information>";
				 tb_Interpret->Text = "<no information>";
				 tb_Album->Text = "<no information>";
				 tb_Genre->Text = "<no information>";
				 tb_Track->Text = "<no information>";
				 tb_Year->Text = "<no information>";
			 }

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	}; // eo Form1 class
} // eo namespace MP3Tool
#endif
