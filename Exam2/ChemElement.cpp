#include "ChemElement.h"
ChemElement::ChemElement()
{
	strcpy_s(symbol, "??");
	mass = 0;
	state = 0;
	type = 0;
	//atomicNumber = 0;
	strcpy_s(discoverer, "unknow");
	discoveredYear = 0;
}
//void ChemElement::setAtomicNumber(int atomicNumber)
//{
//	this->atomicNumber = atomicNumber;
//}
//int ChemElement::getAtomicNumber()
//{
//	return atomicNumber;
//}
string ChemElement::getStateName()
{
	return states[state];
}
string ChemElement::getTypeName()
{
	return types[type];
}
const char* ChemElement::getSymbol()
{
	return symbol;
}
double ChemElement::getMass()
{
	return mass;
}
int ChemElement::getState()
{
	return state;
}
int ChemElement::getType()
{
	return type;
}
const char* ChemElement::getDiscoverer()
{
	return discoverer;
}
int ChemElement::getDiscoveredYear()
{
	return discoveredYear;
}
void ChemElement::setSymbol(const char* symbol)
{
	strcpy_s(this->symbol, symbol);
}
void ChemElement::setMass(const double mass)
{
	this->mass = mass;
}
void ChemElement::setState(int state)
{
	this->state = state;
}
void ChemElement::setType(int type)
{
	this->type = type;
}
void ChemElement::setDiscoverer(const char* discoverer)
{
	strcpy_s(this->discoverer, discoverer);
}
void ChemElement::setDiscoveredYear(int discoveredYear)
{
	this->discoveredYear = discoveredYear;
}
bool ChemElement::operator<(const ChemElement& ChemElement)
{
	return (this->value < ChemElement.value);
}
ChemElement &ChemElement::operator = (const ChemElement& right)
{
	if (this == &right) {
		return *this;
	}
	setName(right.name);
	 
	//strcpy_s(name, 50, right.name);
	//this->mass=right.mass;
	setValue(right.value);
	setSymbol(right.symbol);
	setMass(right.mass);
	setState(right.state);
	setType(right.type);
	setDiscoverer(right.discoverer);
	setDiscoveredYear(right.discoveredYear);	

	return *this;
}
ostream& operator<<(ostream& out, ChemElement& ChemElement)
{
	out << "\n\tArray subscript: " << ChemElement.getValue()-1;
	out<<"\n\tAtomic Number: "<<ChemElement.getValue();
	out << "\n\tSymbol: " << ChemElement.symbol;
	out << "\n\tName: " << ChemElement.name ;
	out << "\n\tMass: " << ChemElement.mass ;
	out << "\n\tState: " << ChemElement.getStateName();
	out << "\n\tType: " << ChemElement.getTypeName() ;
	out << "\n\tDiscoverer: " << ChemElement.discoverer ;
	out << "\n\tDiscovered Year: " << ChemElement.discoveredYear ;
	return out;
}
istream& operator>>(istream& in, ChemElement& ChemElement)
{
	
	cout << "Symbol: ";
	in >> ChemElement.symbol;
	cout << "Name: ";
	in >> ChemElement.name;
	cout << "Mass: ";
	in >> ChemElement.mass;
	cout << "State: ";
	in >> ChemElement.state;
	cout << "Type: ";
	in >> ChemElement.type;
	cout << "Discoverer: ";
	in >> ChemElement.discoverer;
	cout << "Discovered Year: ";
	in >> ChemElement.discoveredYear;
	return in;
}