#ifndef _NODE_
#define _NODE_

#include <iostream>

class Node {
private:
  Node* next;

protected:
  // Node objects cannot be created
  Node(Node* s=NULL) : next(s) {}

public:
  // pure virtual function makes Node an abstract class
  // virtual destructor ensures derived classes are destructed properly when
  // pointed by a Node*
  virtual ~Node() {}
  virtual void display () const = 0;
  Node* getNext() const {
    return next;
  }
  void setNext(Node* s) {
    next = s;
  }
};

template<typename B>
class BaseElem : public Node {
private:
  // Node* next <-- private inherited var
  B belem;

public:
  BaseElem(Node* s, const B& a) : Node(s), belem(a) {}
  void setBelem(const B& a) {
    belem = a;
  }
  const B& getBelem() const {
    return belem;
  }
  // pure virtual function in Node class (must override it)
  void display() const {
    std::cout << belem;
  }
};

template<typename B, typename D>
class DerivedElem : public BaseElem<B> {
private:
  //Node* next <-- inherited
  //B belem <-- inherited
  D delem;

public:
  DerivedElem(Node* s, const B& a, const D& c) : BaseElem<B>(s, a), delem(c) {}
  void setDelem(const D& c){
    delem = c;
  }
  const D& getDelem() const {
    return delem;
  }
  void display() const {
    BaseElem<B>::display();
    std::cout << ", " << delem;
  }
};

#endif
