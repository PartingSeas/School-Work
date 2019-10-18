#define MYPAIR_HPP

#include <iostream>

template<typename f, typename c> class MyPair;
template<typename f, typename c> std::ostream& operator<<(std::ostream& out, const MyPair<f, c>& mp);

template<typename f, typename c>
class MyPair {
private:
  f firstElem;
  c secondElem;
public:
  // constructor
  //MyPair() : first(), second() {}
  MyPair(f i, c j) : firstElem(i), secondElem(j) {}
  MyPair<f, c> makeMyPair(f i, c j);
  f getFirst() const;
  c getSecond() const;
  void setFirst(f& i);
  void setSecond(c& j);

  friend std::ostream& operator<< <f, c>(std::ostream& out, const MyPair<f, c>& mp);

};

template<typename f, typename c>
MyPair<f, c> MyPair<f, c>::makeMyPair(f i, c j) {
  return MyPair(i, j);
};

template<typename f, typename c>
f MyPair<f, c>::getFirst() const {
  return firstElem;
};

template<typename f, typename c>
c MyPair<f, c>::getSecond() const {
  return secondElem;
};

template<typename f, typename c>
void MyPair<f, c>::setFirst(f& i) {
  firstElem = i;
};

template<typename f, typename c>
void MyPair<f, c>::setSecond(c& j) {
  secondElem = j;
};

template<typename f, typename c>
std::ostream& operator<<(std::ostream& out, const MyPair<f, c>& mp){
  out << "(" << mp.getFirst() << " , " << mp.getSecond() << ")";
};
