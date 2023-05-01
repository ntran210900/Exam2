#ifndef PERIODICTABLE_H
#define PERIODICTABLE_H
#include "ChemElement.h"
#include <iostream>
#include <string>
#include"input.h"
#include <fstream>
using namespace std;


class PeriodicTable
{
private:
	static const int MAX=118;
	ChemElement *arrayElements= nullptr;
	int currentIndex;
	
	public:
		PeriodicTable();
		PeriodicTable(const PeriodicTable&);
		~PeriodicTable();
		PeriodicTable& operator =( PeriodicTable&);
		PeriodicTable operator ++();
		PeriodicTable operator ++(int);
		PeriodicTable operator --();
		PeriodicTable operator --(int);
		int getMax();
		bool addElement();
		bool removeElement(int);
		bool updateElement( );
		bool fileValidation(fstream& file, const string filename);
		void readElements(ChemElement data[], int size, fstream& file);
		ChemElement const getElementByAtomicNumber(int);
		ChemElement const getElementBySymbol(string);
		PeriodicTable readElementsFromFile(int, string);
		void setCurrentIndex(int);
		int getCurrentIndex();
		void displayAnElement(ChemElement&);
		int updateOption(ChemElement& ,int );
		void displayAllElements() ;
		void displayAllElementsByType( int) ;
		void displayAllElementsByState(int) ;
		//PeriodicTable& operator =(PeriodicTable&);
		//void displayPeriodicTable(ostream&) ;
		//void displaySizeOf(ostream&) const;
};

#endif
