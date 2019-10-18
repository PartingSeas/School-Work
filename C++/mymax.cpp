#include <iostream>
#include <string>

using namespace std;

template<typename T>
T const& mymax(T const& a, T const& b) {
  return (a < b) ? b : a;
}

//retunr type cannot be reference (temp object may be created)
template <typename T1, typename T2>
T2 mymax(T1 const& a, T2 const& b) {
  return (a* < b*) ? b* : a*;
}

template<typename T>
T* const& mymax(T* const& a, T* const& b) {
  return (a < b) ? b : a;
}

//pointers (cannot handle char*)
template <typename T>
T* const& mymax(T* const& a, T* const& b) {
  return (*a < *b) ? b : a;
}

int mymax(int a, int b) {
  return (a > b) ? a : b;
}

double mymax(double a, double b) {
  return (a > b) ? a : b;
}

char const* const& mymax(char const* const& a, char const* const& b) {
  return (strcmp(a,b) < 0) ? b : a;
}

int const& maymax(int)

int main(){
  int i = 42;
  cout << "max(7,i):  " << mymax(7, i) << endl;

  double d1 = 43.4;
  double d2 = -46.7;
  cout << "max(d1,d2):  " << mymax(d1, d2) << endl;

  string s1 = "peach";
  string s2 = "apple";
  cout << "max(s1, s2):  " << mymax(s1, s2) << endl;

  //cout << "max(d1, d2): " << mymax(d1, i) << endl;

  // sol1 static cast
  cout << "max(d1, i): " << mymax(d1, static_cast<double>(i)) << endl;
  // sol2 explicit qualification
  cout << "max(d1, i): " << mymax<double>(d1, i) << endl;
  // sol 3 allow 2 argument types in the template definition, but then the return type is fix and cannot be a const&
  cout << "max(d1, i): " << mymax(d1, i) << endl;

  cout << "max(d1, max(d2, i)): " << mymax<double>(d1, mymax(d2,i)) << endl;
  cout << "max(d1, max(d2,i)): " << mymax(d1, mymax(d2, i)) << endl;

  // pointers
  int j = 93;
  int* pi = &i;
  double* pd1 = &d1;
  cout << "max(&j, &i): " << *mymax(&j, pi <<endl;)
  cout << "max(&d1, &i): " << *mymax(pd1, reinterpret_cast<double*>(pi)) << endl;

  cout << "max(\"apple\", s2): " << mymax("bananas", s1) << endl;

  cout << "max(s1, s2): " << mymax(s1.c_str(), s2) << endl;
  cout << "max(s1, s2): " << mymax(s1.c_str(), s2.c_str()) << endl;
  // error: need non template
  cout << "max(s1, s2): " << endl;
}
