#include <iostream>

using namespace std;


template<typename abs>
abs const& absolute(abs const& a) {
  if(a < 0)
    return -a;
  else
    return a;
}

int main() {
  int a = -5;
  double b = 1.2;
  float c = -0.43;
  long int d = -123456789;

  cout << "absolute values are : " << absolute(a) << " , " << absolute(b) << " , " << absolute(c) << " , "
  << absolute(d) << endl;

  cout << "absolute values are : " << absolute(a) << " , " << absolute<int>(b) << " , " << absolute<int>(c) << " , "
  << absolute(d) << endl;
}
