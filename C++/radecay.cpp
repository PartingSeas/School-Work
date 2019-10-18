// simulate radioactive decay of atoms (each atom has a 50% chance of decaying every year)

#include <iostream>
#include <random>

using namespace std;

//return the number of atoms that remain in a sampleSize after a decay period
//each atom has a 50% chance of decay in a given period
//using a reference
int halfLifeAtoms(int& sampleSize);
//using a pointer
int halfLifeAtoms(int* sampleSize);


int main() {
  int atoms = 0;
  int year = 0;

  cout << "sample size: ";
  cin >> atoms;

  cout << "initial atoms:  " << atoms << endl;
  while(halfLifeAtoms(&atoms))
    cout << "remainig atoms: " << atoms << " at the end of year " << ++year << endl;
  cout << "remainig atoms: " << atoms << " at the end of year " << ++year << endl;
  return 0;
}


int halfLifeAtoms(int& sampleSize) {
  random_device rd;
  mt19937 engine(rd());
  uniform_int_distribution<int> distribution(1, 100);
  int end = sampleSize;

  for(int i=1; i <= end; ++i) {
    int r = distribution(engine);
    if((r % 2) == 0) {
      --sampleSize;
    }
  }
  return sampleSize;
}


int halfLifeAtoms(int* sampleSize) {
  random_device rd;
  mt19937 engine(rd());
  uniform_int_distribution<int> distribution(1, 100);
  int end = *sampleSize;

  for(int i=1; i <= end; ++i) {
    int r = distribution(engine);
    if((r % 2) == 0) {
      --*sampleSize;
    }
  }
  return *sampleSize;
}
