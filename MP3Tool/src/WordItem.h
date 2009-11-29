#pragma once
#include <string>

class WordItem
{
public:
	WordItem(void);
	std::string * MeinText;
	int blub;
	//WordItem(const WordItem& wi);
	WordItem* WordItem::operator=(const WordItem* wi);

	~WordItem(void);
};
