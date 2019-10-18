#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void getSamples(vector<int>& v, int samples, int a, int b);
void sort(vector<int>& v);
void display(vector<int>& v);
int binarySearch(const vector<int>& v, int target);
vector<int> merge(vector<int>& v1, vector<int>& v2);
//vector<int> readSamples(string filename);
void writeSamples(string filename, const vector<int>& v);

int main() {
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;

  v1.push_back(2);
  v1.push_back(6);
  v1.push_back(4);

  v2.push_back(7);
  v2.push_back(8);
  v2.push_back(3);

  display(v1);
  display(v2);

  // populate vectors
  getSamples(v1, 50, 1, 10000);
  getSamples(v2, 50, 1, 10000);
  display(v1);
  display(v2);

  // write samples to files
  writeSamples("sample1.txt", v1);
  writeSamples("sample2.txt", v2);

  //read samples
  // v1 = readSamples("sample1.txt");
  // v2 = readSamples("sample2.txt");

  // merge vectors
  // v3 = merge(v1, v2);
  // writeSamples("merged.txt", v3);
  // cout << "v1 [" << v1.size() << "], v2[" << v2.size() << "]" << endl;
  // display(v3);
}

// take random samples from a uniform distribution and add them to the vector
void getSamples(vector<int>& v, int samples, int a, int b) {
  random_device rd;
  mt19937 engine(rd());
  uniform_int_distribution<int> distribution(a, b);

  for(int i=0; i < samples; ++i)
    v.push_back(distribution(engine));
}

//sort the vector using the bubble sort algorithm
// void sort(vector<int>& v) {
//
// }
//
// return the postion (index) of the target, if it is in the vector, -1 otherwise
// int binarySearch(const vector<int>& v, int target) {
//   int first = 0;
//   int last = v.size() - 1;
//   int mid;
//
//   if(v.empty())
//     return -1;
//   while(firdt <= last) {
//     mid = (first + )
//   }
// }
void display(vector<int>& v) {
  cout << "vector [" << v.size() << "]:" << endl;
  for(vector<int>::iterator it =v.begin(); it != v.end(); ++it)
    cout << *it << " ";
  cout << endl;

}

void writeSamples(string filename, const vector<int>& v) {
  // append to file
  // ofstream fout(filename.c_str(), ios::out | ios::app);
  // overwrite file if exists (default);
  ofstream fout(filename.c_str(), ios::out | ios::trunc);
  // same as fout.ispoen() or !fout.fail()
  if(fout) {
    for(int i=0; i < v.size(); ++i)
      fout << v[i] << " ";
    fout << endl;
    fout.flush();
    fout.close();
    if(!fout.good())
      cout << "error while closing : " << filename << endl;
    } else
      cout << "error: " << filename << " could not be opened for writing... shiiiit" << endl;
}

vector<int> readSamples(string filename) {
  int val;
  vector<int> v;
  ifstream fin(filename.c_str(), ios::in);
  if(fin) {
    while(!fin.eof()) {
      // read until whitespace
      fin >> val;
      // needed to avoid repeating last value due to eof
      if(!fin.eof())
        v.push_back(val);
    }
    fin.close();
  } else
    cout << "error: " << filename << " could not be opened for reading... shiiiit" << endl;
    return v;
}
