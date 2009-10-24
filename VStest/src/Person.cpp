#include "StdAfx.h"
#include "Person.h"

CPerson::CPerson(void): mAge(0), mName("")
{
}

CPerson::~CPerson(void)
{
}
CPerson::CPerson( const char *pName, int pAge)
{
	mName = pName;
	mAge = pAge;
}
const char *CPerson::getName() const
{
	return mName.c_str();
}
int CPerson::getAge() const
{
	return mAge;
}