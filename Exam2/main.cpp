
#include"PeriodicTable.h"

#include"input.h"
#include<iostream>
#include<string>
using namespace std;
char menuOption();
void OptionA(PeriodicTable *table);
void OptionB(PeriodicTable *table);
//precodition: none.
//postcondition: none.
//description: this function will display the periodic table and the option for the program.
char menuOption() 
{
    //Hello World
    adfasfgasdczxZXCzxcvxcvbbvxcz
    cout << "\n\t" << string(100, char(205)) << "\n";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\tA. Dynamic Array of Structure Elements";
    cout << "\n\tB. Structure Elements from Binary File";
    cout << "\n\tC. Structure Element size info (5pts Extra)";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\tX. Exit";
    cout << "\n\t" << string(100, char(205)) << "\n";
    char input;
    do
    {
        input = inputChar("\n\tOption: ");
        if (toupper(input) != 'A' && toupper(input) != 'B' && toupper(input) != 'C' && toupper(input) != 'X' && toupper(input) != 'N')
            cout << "\n\tERROR-2: Invalid input. Must be a character from the list of ''A', 'B', 'C', 'X', or 'N'.";
        else break;
    } while (true);

    return input;
}
int main()
{

    PeriodicTable *table=new PeriodicTable;
   
  
    do
    {
        switch (menuOption())
        {
        case 'X': exit(1); break;
        case 'A': OptionA(table); break;
           case 'B': OptionB(table); break;
            /* case 'C': OptionC(); break;
             case 'N': optionN(); break;*/
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}
void OptionB(PeriodicTable *table)
{
   
    system("cls");
    cout << "\n\t" << string(100, char(205)) << "\n";
    cout << "\n\t1. Add\n";
    cout << "\n\t2. Update\n";
    cout << "\n\t" << string(100, char(205)) << "\n";
    cout << "\n\t0. Return to main menu\n";
    cout << "\n\t" << string(100, char(205)) << "\n";
    int option=inputInteger( "\n\tOption: ",0,2);
    switch (option)
    {
    case 1:
        if(table->addElement())
            cout << "\n\tThe element with atomic #" << table->getCurrentIndex()<< " has been added.";
		else
			cout << "\n\tElement not added";
        break;
    case 2:
        if (table->updateElement())
            cout << "\n\tThe element with atomic #" << table->getCurrentIndex() << " has been updated.";
		else
            cout << "\n\tNo update has been committed.";
		break;
    case 0: return; break;
       
    }
   


}
void OptionA(PeriodicTable *table)
{
    
    table->readElementsFromFile(118, "file.dat");
    ChemElement element = table->getElementBySymbol("Li");
    cout << element;
  //  table->displayAllElementsByType(1);

   /* ChemElement data[118];
    data[1] = data[2];*/
  /*  string file;
    cout << "\n\tEnter file name";
    cin >> file;
    table.readElementsFromFile(118, file);
    */
 
}
