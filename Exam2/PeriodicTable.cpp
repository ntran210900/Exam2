#include "PeriodicTable.h"
PeriodicTable::PeriodicTable()
{
	currentIndex = 0;
	
	arrayElements= new ChemElement[MAX];
}
PeriodicTable::PeriodicTable(const PeriodicTable& pt)
{
	currentIndex = pt.currentIndex;
	
	for (int i = 0; i < currentIndex; i++)
	{
		arrayElements[i] = pt.arrayElements[i];
	}
}
//PeriodicTable& PeriodicTable::operator =(const PeriodicTable& pt)
//{
//	currentIndex = pt.currentIndex;
//	for (int i = 0; i < currentIndex; i++)
//	{
//		arrayElements[i] = pt.arrayElements[i];
//	}
//	return *this;
//}
PeriodicTable PeriodicTable::operator ++()
{
	currentIndex++;
	return *this;
}
PeriodicTable PeriodicTable::operator ++(int)
{
	PeriodicTable temp = *this;
	currentIndex++;
	return temp;
}
PeriodicTable PeriodicTable::operator --()
{
	currentIndex--;
	return *this;
}
PeriodicTable PeriodicTable::operator --(int)
{
	PeriodicTable temp = *this;
	currentIndex--;
	return temp;
}
int PeriodicTable::updateOption(ChemElement& ce,int option)
{
	string word;
	if (option == 0)
	{
		cout << "\n\tAdd Element Menu" ;
		word ="Enter new";
	}
	else
	{
		cout << "\n\tUpdate Element Menu" ;
		word = "Change";
	}
	
	cout << "\n\t" << string(100, char(205)) << "\n";
	cout << "\n\t1. "<<word<<" symbol" ;
	cout << "\n\t2. "<<word<<" name" ;
	cout << "\n\t3. "<<word<<" atomic mass" ;
	cout << "\n\t4. "<<word<<" state" ;
	cout << "\n\t5. "<<word<<" type" ;
	cout << "\n\t6. "<<word<<" discoverer" ;
	cout << "\n\t7. "<<word<<" discovered year" ;
	cout << "\n\t" << string(100, char(205)) << "\n";
	if (option == 0) {
		cout << "\n\t8. Add the new element(s)" ;
		cout << "\n\t0. Return to main menu without adding" ;
	}
	else
	{
		cout << "\n\t8. Commit the update(s)" ;
		cout << "\n\t0. Return to main menu without updating" ;
	}
	cout << "\n\t" << string(100, char(205)) << "\n";
	int input = inputInteger("\n\tOption: ", 0, 8);
	switch (input)
	{
	case 1:
		{
			string symbol = inputString("\n\tEnter new symbol: ",false);
			while (symbol.size() > 2)
			{
				cout << "\n\tError: Symbol cannot be more than 2 characters" ;
				symbol = inputString("\n\tEnter new symbol: ", false);
			}

			ce.setSymbol(symbol.c_str());
			break;
		}
	case 2:
		{
			string name = inputString("\n\tEnter new name: ",false);
			ce.setName(name.c_str());
			break;
		}
	case 3:
	{
			double mass = inputDouble("\n\tEnter new atomic mass: ", 0.0, 1000.0);
			ce.setMass(mass);
			break;
		}
	case 4:
	{
			int state = inputInteger("\n\tEnter a new state (0-unknown, 1-Solid, 2-Liquid, or 3-Gas): ",0,3);
			ce.setState(state);
			break;
		}
	case 5:
	{
			int type = inputInteger("\n\tEnter a new type (0-unknown, 1-Actinide, 2-Alkali Metal, 3-Alkaline Earth Metal,4 - Halogen, 5 - Lanthanide, 6 - Metalloid, 7 - Noble Gas,8 - Reactive Nonmetal, 9 - Post - Transition Metal, or 10 - Transition Metal) : ",0,10);
			ce.setType(type);
			break;
		}
	case 6:
	{
			string discoverer = inputString("\n\tEnter new discoverer: ",false);
			ce.setDiscoverer(discoverer.c_str());
			break;
		}
	case 7:
	{
			int discoveredYear = inputInteger("\n\tEnter new discovered year: ",0,9999);
			ce.setDiscoveredYear(discoveredYear);
			break;
		}
	}
	return input;

}
bool PeriodicTable::addElement()
{
	currentIndex = inputInteger("Enter an atomic# (1...118) to retrieve or 0-return to main menu): ", true);

	ChemElement temp=arrayElements[currentIndex-1];

	do
	{
		system("\n\tpause");
		system("cls");
		displayAnElement(temp);
		int option= updateOption(temp,0);
		if (option == 0)
		{
			
			return false;
		}
		else if (option == 8)
		{
			if (currentIndex == 118)
			{
				arrayElements[currentIndex-1] = temp;
				return true;
			}
			else
			{
				for (int i = currentIndex-1; i < MAX - 1; i++)
				{

					this->arrayElements[i + 1] = this->arrayElements[i];

				}
				arrayElements[currentIndex-1] = temp;
			}
			
		
			
			return true;
		}
	} while (true);
	/*if (currentIndex < MAX)
	{
		arrayElements[currentIndex] = ce;
		currentIndex++;
		return true;
	}*/
	return false;
}
bool PeriodicTable::updateElement()
{
	currentIndex = inputInteger("Enter an atomic# (1...118) to retrieve or 0-return to main menu): ", true);
	ChemElement temp= arrayElements[currentIndex-1];
	do
	{
		displayAnElement(temp);
		int option = updateOption(temp,1);
		if (option == 0)
		{
			
			return false;
		}
		else if (option == 8)
		{
			arrayElements[currentIndex-1] = temp;
			
			return true;
		}
	} while (true);

	return false;
}
bool PeriodicTable::removeElement(int) {

	currentIndex = inputInteger("Enter an atomic# (1...118) to retrieve or 0-return to main menu): ", true);
	arrayElements[currentIndex - 1].setValue(0);
	arrayElements[currentIndex - 1].setSymbol("??");
	arrayElements[currentIndex - 1].setName("Unknown");
	arrayElements[currentIndex - 1].setMass(0.0);
	arrayElements[currentIndex - 1].setState(0);
	arrayElements[currentIndex - 1].setType(0);
	arrayElements[currentIndex - 1].setDiscoverer("Unknown");
	arrayElements[currentIndex - 1].setDiscoveredYear(0);
	return true;
}
//bool PeriodicTable::removeElement(int atomicNumber)
//{
//	for (int i = 0; i < currentIndex; i++)
//	{
//		if (arrayElements[i].getAtomicNumber() == atomicNumber)
//		{
//			for (int j = i; j < currentIndex - 1; j++)
//			{
//				arrayElements[j] = arrayElements[j + 1];
//			}
//			currentIndex--;
//			return true;
//		}
//	}
//	return false;
//}
//bool PeriodicTable::updateElement(ChemElement& ce)
//{
//	for (int i = 0; i < currentIndex; i++)
//	{
//		if (arrayElements[i].getAtomicNumber() == ce.getAtomicNumber())
//		{
//			arrayElements[i] = ce;
//			return true;
//		}
//	}
//	return false;
//}
//ChemElement const PeriodicTable::getElementByAtomicNumber(int atomicNumber)
//{
//	for (int i = 0; i < currentIndex; i++)
//	{
//		if (arrayElements[i].getAtomicNumber() == atomicNumber)
//		{
//			return arrayElements[i];
//		}
//	}
//	return ChemElement();
//}
ChemElement const PeriodicTable::getElementBySymbol(string symbol)
{
	for (int i = 0; i < MAX; i++)
	{
		if (strcmp(arrayElements[i].getSymbol() , symbol.c_str())==0)
		{
			return arrayElements[i];
		}
	}
	return ChemElement();
}
void PeriodicTable::setCurrentIndex(int currentIndex)
{
	this->currentIndex = currentIndex;
}
int PeriodicTable::getCurrentIndex()
{
	return currentIndex;
}
int PeriodicTable::getMax()
{
	return MAX;
}
//void PeriodicTable::displayAnElement(ostream& strm, PeriodicTable& obj)
//{
//	int atomicNumber;
//	cout << "Enter the atomic number of the element you want to display: ";
//	cin >> atomicNumber;
//	for (int i = 0;i < obj.getMax();i++)
//	{
//		if (obj.arrayElements[i].getAtomicNumber() == atomicNumber)
//		{
//			strm << obj.arrayElements[i];
//		}
//	}
//}
void PeriodicTable::displayAllElements()
{
	for (int i=0;i < getMax();i++)
	{
		cout << arrayElements[i];
		
	}

}
void PeriodicTable::displayAllElementsByType(int type)
{
	cout << "\n\t Atomic#\tSymbol\tName";
	cout << "\n\t" << string(55, char(205)) << "\n";
	for (int i = 0;i < MAX;i++)
	{
		if (arrayElements[i].getType() == type)
		{
			cout << "\n\t" << arrayElements[i].getValue() << "\t" << arrayElements[i].getSymbol() << "\t" << arrayElements[i].getName();

		}
	}
}
void PeriodicTable::displayAllElementsByState( int state)
{
	cout << "\n\t Atomic#\tSymbol\tName";
	cout << "\n\t" << string(55, char(205)) << "\n";
	for (int i = 0;i < MAX;i++)
	{

		if (arrayElements[i].getState() == state)
		{
			cout << "\n\t"<<arrayElements[i].getValue()<<"\t"<< arrayElements[i].getSymbol()<<"\t"<< arrayElements[i].getName();
		}
	}
}
//Precondition:valid fstream object and a valid filename as parameters. 
//Postcondition:return a boolean value indicating whether the file was successfully opened or not.
bool PeriodicTable::fileValidation(fstream& file, const string filename)
{
	file.open(filename, ios::binary | ios::in);
	if (!file.is_open())
	{
		return false;
	}
	else
		return true;
}
void PeriodicTable::displayAnElement(ChemElement &ce)
{
	
	cout << ce;


}
//Precondition: an struct array, an int size must be greater than 0 and a valid fstream object
//Postcondition: filled the struct array with data from file.
void PeriodicTable::readElements(ChemElement data[], int size, fstream& file) {
	file.read(reinterpret_cast<char*>(data), size * sizeof(ChemElement));
}
PeriodicTable PeriodicTable::readElementsFromFile(int size, string filename) {
	 PeriodicTable table;
	fstream file;
	if (!fileValidation(file, filename)) {
		delete[] arrayElements;
		cout << "failed";
		return table;

	}
	readElements(arrayElements, size, file);
	cout << "\n\tSuccess";
	file.close();
	return table;

}
PeriodicTable::~PeriodicTable() {
	delete[] arrayElements;
}
//void PeriodicTable::displayPeriodicTable(ostream& strm) 
//{
//	for (int i = 0;i < MAX;i++)
//	{
//		strm<<arrayElements[i];
//	}
//}
PeriodicTable& PeriodicTable::operator =(PeriodicTable&right)
{
	arrayElements = new ChemElement[MAX];
	currentIndex= right.currentIndex;
	if (this != &right)
	{
		delete[] arrayElements;
		arrayElements = new ChemElement[right.MAX];
		for (int i = 0;i < right.MAX;i++)
		{
			arrayElements[i] = right.arrayElements[i];
		}
	}
	return *this;
}