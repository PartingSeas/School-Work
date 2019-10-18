#include <iostream>
#include "stufflist.hpp"

using namespace std;

int main() {
  StuffList<string, int> l1;

  cout << "most popular classical symphonies" << endl;
  cout << "=================================" << endl;
  l1.insert("Kid Cudi: The Prayer", 567);
  l1.insert("03 Greedo: Trap House", 645);
  l1.insert("Tool: Lateralus", 199);
  l1.insert("Common: They Say", 213);
  l1.insert("Playboi Carti: Pissy Pamper", 123);
  l1.insert("", 745);
  l1.insert("Kid Cudi: The Prayer", 543);
  l1.displayAll();
  cin.get();

  cout << "delete non classics" << endl;
  cout << "===================" << endl;


  cout << "most popular classics (copied and updated)" << endl;
  cout << "==========================================" << endl;
  StuffList<string, int> l2(l1);
  l2.insert("bull: shit")
}
