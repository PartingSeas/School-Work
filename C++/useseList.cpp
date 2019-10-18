
#include <iostream>
#include "elist.hpp"

using namespace std;


int main() {
  EList l1;


  l1.insert("Harry_Potter", MS, 100, FULLSTACK, "all");
  l1.insert("Ron_Weasley", BS, 75, WEB, "some");
  l1.insert("Hermione_Granger", PHD, 380, ANALYST, "all");
  l1.insert("Draco_Malfoy", BA, 80, FX);
  l1.displayAll();
  cin.get();

  cout << "deleted Draco" << endl;
  cout << "==============" << endl;
  l1.remove("Draco_Malfoy");
  l1.displayAll();
  cout << endl;
  cin.get();


  EList l2(l1);
  cout << "copy constructor and add 2 employees" << endl;
  cout << "====================================" << endl;
  l2.insert("Neville_Longbottom", MS, 180, APP, "all");
  l2.insert("Luna_Lovegood", BA, 140, EDITING);
  l2.displayAll();
  cout << endl;
  cin.get();


  EList l3; //empty list
  l3 = l2;
  cout << "copy assigned and add one employee" << endl;
  cout << "==================================" << endl;
  l3.insert("Fleur_Delacour", MS, 200, SOUND);
  l3.displayAll();
  cout << endl;
  return 0;
}
