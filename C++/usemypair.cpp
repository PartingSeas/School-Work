#include <iostream>
#include "mypair.hpp"

using namespace std;

int main() {
  MyPair<int, int> a(-1, 2);
  MyPair<int, double> b(5, 1.2);
  MyPair<string, double> c("Average", 2.1);

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  return 0;
}
