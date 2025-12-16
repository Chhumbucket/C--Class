#include "minion.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* 
  Opens minion.txt files and reads data on minions.
  Takes files datas and put into objects then outputs 
  minion's characteristics and height comparisons. 
  In addition, calculate how many bananas each minion has,
  and gives bananas. 
  Finally, prints amount of minions created. 

*/

int main()
{
  //Open File 
  ifstream minionsFile("minions.txt");

  // Check if the file opened
  if (!minionsFile.is_open())
  {
    cout << "File fail to open." << endl;
    return 0;
  }

  //Intializing Variables
  string name;
  float height;
  int eyes;
  int bananas;

  //Reads the files
  minionsFile >> name >> height >> eyes >> bananas;
  const Minion minion1(name, height, eyes, bananas);
  minionsFile >> name >> height >> eyes >> bananas;
  Minion minion2(name, height, eyes, bananas);
  minionsFile >> name >> height  >> eyes >> bananas;
  Minion minion3(name, height, eyes, bananas);

minionsFile.close();

//Compare Height of the Minion
if (minion1 > minion2){
  cout << minion1.getName() << " is taller than " << minion2.getName();
}

if (minion2 < minion3){
  cout << minion3.getName() << " is taller than " << minion2.getName();
}

cout << endl << endl;

//Minion2 gets 2 bananas
cout << minion2;
cout << minion2.getName() << " getting bananas.\n";
cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << endl;

//Minion3 grows 1 strand
cout << minion3;
cout << minion3.getName() << " getting bananas.\n";
cout << "Before getting bananas, the minion had " << minion3++.getBananas() << " banana(s).\n";
cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s).\n" << endl;

//Print Function- Print amount of minions created
Minion::printMinionCount();

return 0;
} 