#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <string>
using namespace std;
class Unit
{
protected:
	static int objectCount;
	int value;
	char name[50];
	public:
		Unit();
		static int getCount();
		void setValue(int);
		void setName(const char*);
		const char* getName();
		int getValue();
		friend ostream& operator<<(ostream&, Unit&);
};

#endif // !UNIT_H

