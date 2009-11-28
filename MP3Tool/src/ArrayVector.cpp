#include "StdAfx.h"
#include "ArrayVector.h"
#include <cctype>
#include <array>





ArrayVector::ArrayVector(void)
{
	//const capacity = 10; // Initial Capacity
	size = 0;
	int capacity = 10;
	// std::string * strings[][] = new std::string*[capacity][255]; // Ereugt ein Array mit der länge von 10 Strings die 255 Zeichen lang sein dürfen;
	// *blaArray[10];
	//std::string* tArray= new std::string[newCapacity] ;
	
	
	
	for(int n=0;n<10;n++)
	{
		WordItem* t_wordI = new WordItem;
			blaArray[n] = t_wordI;
	}
}


void ArrayVector::addItem(std::string * item)
{
	//blaArray[size].MeinText = item;
	if (size==0)
	{
		WordItem* tempWord = new WordItem;
		tempWord->MeinText = new std::string("");
		blaArray[0] = tempWord;
		blaArray[0]->MeinText = item;
		size++;
	}
	else
	{
		for (int i = 0 ; i < size ; i++)
		{
			if (strcmp( item->c_str(), blaArray[i]->MeinText->c_str()) < 1)
			{
				for (int j = size; j >= i ; j--)
				{
					blaArray[j] = blaArray[j-1]; // Element nach hinten schieben
				}
				WordItem* tempWord = new WordItem;
				//tempWord->MeinText = new std::string("");
				tempWord->MeinText = item;
				blaArray[i] = tempWord;
				break;
			} 
			else
			{
				blaArray[size]->MeinText = item; // Wenn nicht gefunden dann hinten ranhängen
			}
		}
	size++;
	}

	if(size == capacity)
	{
		resize(capacity * 2);
	}

}

std::string * ArrayVector::getItem(int i)
{
	return blaArray[i]->MeinText;
}
void ArrayVector::resize(int const newCapacity)
{
	WordItem* tArray[20];
	int newSize = 10;
	System::Array::Copy(blaArray, tArray, newSize);
	/*for (int i = 0; i < size; i++)
	{
		tArray[i] = blaArray[i];

	}
	delete[] *blaArray;
	*blaArray = *tArray;


	capacity = newCapacity;*/
}


void ArrayVector::print( std::ostream & os)
{
	unsigned int count = 0;
	
	while( count < size)
	{
		os << count << ": " << *blaArray[count]->MeinText << "\n";
		count++;
	}
	os << std::endl;
}



ArrayVector::~ArrayVector(void)
{
}
