#pragma once
#include <string>
#include <iostream>
#include "WordItem.h"
class ArrayVector
{
public:
	ArrayVector(void);
	ArrayVector(const ArrayVector& av);

	void addItem(std::string* item);

	WordItem * blaArray[10];
	
	std::string * getItem(int i);
	
	int size;

	void print( std::ostream & os = std::cout);
	void resize(int newCapacity);

private:


	int capacity;
//	char* strings[];
	std::string * tempString;
	~ArrayVector(void);
};
