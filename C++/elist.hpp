#ifndef _ELIST_
#define _ELIST_

#include "nah.hpp"

class EList {
private:
  Node* head;

protected:
  Node* predecessor(const std::string& n);
  Node* successor(const std::string& n);
  void insertAfter(const std::string& n, const DIPLOMA d, const double sal, Node* p);
  void insertAfter(const std::string& n, const DIPLOMA d, const double sal, const SWE ex, const std::string& sk, Node* p);
  void insertAfter(const std::string& n, const DIPLOMA d, const double sal, const AEX ex, Node* p);
  void removePos(Node* p);

public:
  //default constructor and destructor
  EList();
  ~EList();
  //copy constructor (make copy of all elements in given list)
  EList(const EList& src);
  //copy assignment (makec copy of all elements in the assigned list)
  EList& operator=(const EList& src);
  //API
   //employee
  void insert(const std::string& n, const DIPLOMA d, const double sal);
  //softwaredeveloper
  void insert(const std::string& n, const DIPLOMA d, const double sal, const SWE ex, const std::string& sk);
  //artist
  void insert(const std::string& n, const DIPLOMA d, const double sal, const AEX exb);
  void remove(const std::string& n);
  void displayAll() const;
  void clear();
};

EList::EList(const EList& src) {

}

EList& EList::operator=(const EList& src) {
  Node* p = src.head;
  head = NULL;
  while(p != NULL) {
    //use typeid to figure out what p is actually pointing to
    if(typeid(*p) == typeid(SoftwareDeveloper))
      insert(dynamic_cast<SoftwareDeveloper*>(p)->getName(),
      dynamic_cast<SoftwareDeveloper*>(p)->getHighestDegree(),
      dynamic_cast<SoftwareDeveloper*>(p)->getSalary(),
      dynamic_cast<SoftwareDeveloper*>(p)->getExpertise(),
      dynamic_cast<SoftwareDeveloper*>(p)->getSkills());
    else if(typeid(*p) == typeid(Artist))
      insert(dynamic_cast<Artist*>(p)->getName(), )
  }
}

Node* EList::predecessor(const string& n) {
  Node* p = head;
  Node* pred = NULL;
  while(p != NULL){
    // cast node* to an Employee* <-- works bc Employee is derived from Node (relying on string)
    //casting: static_cast, const_cast, dynamic_cast, reinterpret_cast
    if(n > dynamic_cast<Employee*>(p)->getName())
      pred = p;
    p = p->getNext();
  }
  return pred;
}
Node* EList::successor(const string& n) {
  Node* p = head;
  while(p != NULL && n != dynamic_cast<Employee*>(p)->getName())
    p = p->getNext();
  if(p != NULL && n == dynamic_cast<Employee*>(p)->getName())
    return p;
  else
    return NULL;
}

void EList::insert(const std::string& n, const DIPLOMA d, const double sal) {
  insertAfter(n, d, sal, predecessor(n));
}

void EList::insert(const std::string& n, const DIPLOMA d, const double sal, const SWE ex, const std::string& sk){

}

void EList::insertAfter(const std::string& n, const DIPLOMA d, const double sal, Node* p){
  if(p == NULL)
    head = new Employee(head, n, d, sal);
  else
    p->setNext(new Employee(p->getNext(), n, d, sal));
}

void EList::insertAfter(const std::string& n, const DIPLOMA d, const double sal, const SWE ex, const std::string& sk, Node* p){
  if(p == NULL)
    head = new SoftwareDeveloper(head, n, d, sal, ex, sk);
  else
    p->setNext(new SoftwareDeveloper(p->getNext(), n, d, sal, ex, sk));
}

void EList::removePos(Node* p) {
  Node* p2;
  if(p != NULL) {
    if (p== head) {
      p2 = head;
      head = head->getNext();
      delete p2;
    } else {
      p2 = predecessor(dynamic_cast<Employee*>(p)->getName());
        if(p2 != NULL)
          p2->setNext(p->getNext());
        delete p;
    }
  }
}

void EList::insert(const std::string& n, const DIPLOMA d, const double sal, const AEX exb){
  if(p == NULL)
    head = new Artist(head, n, d, sal, exb);
  else
    p->setNext(new Artist(p->getNext(), n, d, sal, exb));
}

void EList::insert

#endif
