#pragma once

#include <string>
using namespace std;

class CPerson
{
public:
	CPerson(void);
	~CPerson(void);
	CPerson( const char *pName, int pAge);

	const char *getName() const;
	int getAge() const;

private:
	string mName;
	int mAge;
};
