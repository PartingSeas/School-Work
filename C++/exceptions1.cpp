#include <cassert>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> v1(10);
  vector<int> v2(20);
  int i;

  cout << "index: ";
  cin >> i;
  cout << endl;

  //1. detect error and abort program (default)
  //seg fault id i > 10 (v1[i] does not check bounds)
  //v1.at(i) = 100;
  v1[i] = 100;

  //2. detect and report errors using asserts, then abort program (ok for non-critical)
  assert(i >= 0 && i < v1.size());

  //3. detect and report error using conditionals and continue (ok for non-critical errors)
  if(i >= 0 && i < v1.size())
    v1.at(i) = 100;
  else {
    cout << "error: out of index [" << i << "]" << endl;
  }

  //4. detect and handle error, if possible otherwise bubble up problem
  try {
    v1.at(i) = 100;
    v1.resize(v1.max_size() + 1) ;
  } catch(const out_of_range& e1) {
    cout << "error: out of index [" << i << "] : " << e1.what() << endl;
  } catch(const length_error& e2) {
    cout << "error: resize failed: " << e2.what() << endl;
    throw length_error;
  } catch(...) {
    //without this, the program will be aborted (std::terminate() is called, which calls std::abort())
    cout << "error: something went wrong, so rethrow exception and hope the caller can handle it bitch" << endl;

    throw;
  }

  cout << "v1[" << v1.size() << "]: ";
  for(int i=0; i < v1.size(); ++i)
    cout << v1[i] << " ";
  cout << endl;

  //5. detect errors using the return value (C-Style)
  return 0;
}
