#include <iostream>
using namespace std;

class myA {
public:
  //virtual makes this function output I am B
  // virtual defined outside func
  virtual void myself();
  virtual~myA(){}
};
void myA::myself() {
  cout << "I am A" << endl;
}
class myB: public myA {
private:
  int* j;
public:
  void myself() {
    cout << "I am B" << endl;
  }
};

// void whoareyou(myA& a) {
//   a.myself();
// }
void whoareyou(myA* a) {
  a->myself();
}
int main () {
  //node -> p = new Artist();
  myA* p = new myB();
  whoareyou(p);
  return 0;
}
