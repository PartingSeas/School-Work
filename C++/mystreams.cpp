#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

int main() {
  //common output
  cout << "text" << endl;
  cout << 137 << endl;
  cout << 2.71828 << endl;
  cout << "text followed by a number: " << 31415 << endl;

  //common input
  int i;
  string s;
  //better way of taking input
  cout << "enter sumn: ";
  getline(cin, s);
  cout << "received [" << s << "]" << endl;

  // stream manipulation
  // output boolean values as 1 and 0 or as true and false
  cout << " flag is " << true << endl;
  cout << " flag is " << boolalpha << true << endl;
  // set minimum width of the output (may pad the output)
  cout << "[" << 10 << "]" << endl;
  cout << setw(5) << "[" << 10 << "]" << endl;
  // set fill char
  cout << setfill ('x') << setw(10) << 77 << endl;
  // set radix
  cout << 10 << endl;
  cout << dec << 10 << endl;
  cout << oct << 10 << endl;
  cout << hex << 10 << endl;
  cout << "enter a hex number: ";
  cin >> hex >> i;
  cout << i << " in base 10 is " << dec << i << endl;

  // write files
  string filename = "mydata.txt";
  ofstream fout(filename.c_str(), ios::out | ios::trunc);
  if(fout) {
    fout << 137 << " " << 2.71828 << endl;
    fout << 42 << " " << 3.14159 << endl;
    fout << 7897987 << " " << 1.608 << endl;
    fout << 1337 << " " << .01101010001 << endl;
    fout.flush();
    fout.close();
    if(!fout.good())
      cout << "error while closing: " << filename << endl;
    }
    else
      cout << "error: " << filename << " could not be opened for writing... aborting" << endl;

    // pretty header using stream manipulators
    for(int col=0; col < NUM_COLUMNS - 1; ++col)
      cout << setfill('-') << setw(COLUMN_WIDTH) << "" << "-+-";
    cout << setw(COLUMN_WIDTH) << "" << setfill(' ') << endl;
    // read files and stream manioulation
    ifstream fin(filename.c_str(), ios::in);
    if(fin) {
      int row = 0;
      int i;
      double j;
      while(true) {
        fin >> i >> j;
        if(fin.fail())
          break;
        cout << setw(COLUMN_WIDTH) << (row + 1) << " | ";
        cout << setw(COLUMN_WIDTH) << i << " | ";
        cout << setw(COLUMN_WIDTH) << j << endl;
        ++row;
      }
      fin.close();
    } else
      cout << "error: " << filename << " could not be opened, shiiiiiiiit" << endl;
      return 0;

    }
  
