#pragma once

#include "Person.h"

namespace VStest {

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
		CPerson *pers;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			pers = new CPerson( "Tobias", 19);
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
	private: System::Windows::Forms::Button^  btAddItem;
	private: System::Windows::Forms::ListBox^  myListBox;
	private: System::Windows::Forms::TextBox^  myTextBox;


	protected: 

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
			this->btAddItem = (gcnew System::Windows::Forms::Button());
			this->myListBox = (gcnew System::Windows::Forms::ListBox());
			this->myTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btAddItem
			// 
			this->btAddItem->Location = System::Drawing::Point(98, 225);
			this->btAddItem->Name = L"btAddItem";
			this->btAddItem->Size = System::Drawing::Size(75, 23);
			this->btAddItem->TabIndex = 0;
			this->btAddItem->Text = L"Add item";
			this->btAddItem->UseVisualStyleBackColor = true;
			this->btAddItem->Click += gcnew System::EventHandler(this, &Form1::btAddItem_Click);
			// 
			// myListBox
			// 
			this->myListBox->FormattingEnabled = true;
			this->myListBox->Location = System::Drawing::Point(12, 12);
			this->myListBox->Name = L"myListBox";
			this->myListBox->Size = System::Drawing::Size(268, 173);
			this->myListBox->TabIndex = 1;
			// 
			// myTextBox
			// 
			this->myTextBox->Location = System::Drawing::Point(13, 192);
			this->myTextBox->Name = L"myTextBox";
			this->myTextBox->Size = System::Drawing::Size(267, 20);
			this->myTextBox->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 273);
			this->Controls->Add(this->myTextBox);
			this->Controls->Add(this->myListBox);
			this->Controls->Add(this->btAddItem);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btAddItem_Click(System::Object^  sender, System::EventArgs^  e) {
				//MessageBox::Show( "btAddItem has been clicked.", "Event", MessageBoxButtons::OK, MessageBoxIcon::Information);
				//myListBox->Items->Add( myTextBox->Text);

				 /*
				 NICHT KOMPATIBLE
				 int i = pers->getAge();
				 string a = pers->getName();
				 myTextBox->Text = a;
				 myListBox->Items->Add( myTextBox->Text );
				 */

				 int a = pers->getAge();
				 String ^sTemp = gcnew String( pers->getName());
				 myListBox->Items->Add( String::Format( "Item: {0}; Person: {1}, Age: {2}", myTextBox->Text, sTemp, a));
			 }
	};
}

