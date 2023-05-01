#include "Unit.h"
Unit::Unit()
{
	objectCount++;
	value = objectCount;
	strcpy_s(name, "unknow");
}
int Unit::getCount()
{
	return objectCount;
}
void Unit::setValue(int value)
{
	this->value = value;
}
void Unit::setName(const char* name)
{
	strcpy_s(this->name,50, name);
}
const char* Unit::getName()
{
	return name;
}
int Unit::getValue()
{
	return value;
}
ostream& operator<<(ostream& out, Unit& unit)
{
	out << "Name: " << unit.name << endl;
	out << "Value: " << unit.value << endl;
	return out;
}
int Unit::objectCount = 0;