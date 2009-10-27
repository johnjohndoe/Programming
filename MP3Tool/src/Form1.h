#pragma once
#if !defined ( FORM1_H)
#define FORM1_H
#include "MP3Connector.h"
#include "MP3Controller.h"
// #include <Stream>;

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
			this->myListBox->Size = System::Drawing::Size(612, 173);
			this->myListBox->TabIndex = 1;
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 273);
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
			const char * textFromMyTextBox = "..\\data\\song.mp3";

			if( myMP3Connector->getFile( textFromMyTextBox))
			{
				myListBox->Items->Add( "// File read successfully.");
				// Read metadata from file to MP3Connector
				myMP3Connector->retrieveMetadata();

				String ^ tempTitle = gcnew String( myMP3Connector->getTitle());
				myListBox->Items->Add( String::Format( "Title: {0}", tempTitle));
				String ^ tempAlbum = gcnew String( myMP3Connector->getAlbum());
				myListBox->Items->Add( String::Format( "Album: {0}", tempAlbum));
			}
			else
			{
				myListBox->Items->Add( "// Error reading file.");
			}
		}
		// @see: http://msdn.microsoft.com/en-us/library/system.runtime.interopservices.marshal.stringtohglobaluni.aspx
		// @TODO Status: not working yet; test in empty CLR project
		const char * netstr2cppstr( System::String ^ managedString)
		{
			const char * stringPointer = (const char *) System::Runtime::InteropServices::Marshal::StringToHGlobalUni( managedString).ToPointer();
			return stringPointer;
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
};
}

#endif