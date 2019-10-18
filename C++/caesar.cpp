#include <iostream>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

//how to run the program
void usage(string name); // name is the name of the exe
// take a char, encode/decode it and dump to file
//in takes bytes (chars) from the inout file,
// out writes bytes (chars) to output file
//k is the key of the caesar cipher (number of chars to shift)
void process(istream& in, ostream& out, int k);
//executes encryption/decryption
// takes a char c, shifts it k places and returns new char
char caesarCipher(char c, int k);

int main(int argc, char** argv) {
  bool decrypt = false;
  int key;
  int files = 0;
  string filename1;
  string filename2;
  ifstream fin;
  ofstream fout;

  if(argc < 3 || argc > 5)
    usage(string(argv[0]));
  // parse commmand line options
  for(int i=1; i < argc; ++i){
    string arg = string(argv[i]);
    if(arg.length() >= 2 && arg[0] == "")
  }
  if(files != 2)
    usage(string(argv[0]));
    // open file for reading
    // open file for writing

  if(find && fout) {
    if(decrypt)
      key = -key;
    process(fin, fout, key);
    // close files
  }
  cout << "error: " << filename1 << " or " << filename2 << " couldnt not be opened.. shit" << endl;
  return 0;
}

void usage(string name) {
  cout << "usage: " << name << " [-d] [-kn] infile outfile" << endl;
  exit(1);
}
