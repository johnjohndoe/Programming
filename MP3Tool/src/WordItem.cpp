#include "StdAfx.h"
#include "WordItem.h"

WordItem::WordItem(void)
{
	MeinText = new std::string("");
	blub = 0;
}
	//WordItem::WordItem(const WordItem& wi)
	//{
	//	MeinText = wi.MeinText;
	//	blub = wi.blub;
	//} 

	WordItem* WordItem::operator=(const WordItem* wi) {
	if (this != wi)
	{
		//MeinText = *(new std::string(wi.MeinText)); // Get new space
		            // Copy new name
		MeinText = wi->MeinText;
		blub = wi->blub;                         // Copy id
	}
	return this;    // Return ref for multiple assignment
	}

WordItem::~WordItem(void)
{
	delete MeinText;
}
