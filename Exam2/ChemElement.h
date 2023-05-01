#ifndef ChemELEMENT_H
#define ChemELEMENT_H
#include "Unit.h"
#include <iostream>
#include <string>

using namespace std;
const string states[] = { "unknown", "Solid", "Liquid", "Gas" };
const string types[] = { "unknown", "Actinide", "Alkali Metal", "Alkaline Earth Metal", "Halogen", "Lanthanide", "Metalloid", "Noble Gas", "Reactive Nonmetal", "Post-Transition Metal",  "Transition Metal" };

class ChemElement : public Unit
{
protected:
	static const int MAX = 3;
	//int atomicNumber;
	char symbol[3];
	double mass;
	int state;
	int type;
	char discoverer[100];
	int discoveredYear;
	public:
		ChemElement();
		const char* getSymbol();
		double getMass();
		int getState();
		int getType();
		string getStateName();
		string getTypeName();
		//int getAtomicNumber();
		const char* getDiscoverer();
		int getDiscoveredYear();
		//void setAtomicNumber(int);
		void setSymbol(const char*);
		void setMass(const double);
		void setState(int);
		void setType(int);
		void setDiscoverer(const char*);
		void setDiscoveredYear(int);
		
		bool operator<(const ChemElement&);
		ChemElement& operator=(const ChemElement&);

		friend ostream& operator<<(ostream&, ChemElement&);
		friend istream& operator>>(istream&, ChemElement&);

};

#endif