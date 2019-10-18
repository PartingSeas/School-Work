#ifndef _STUFFLIST_
#define _STUFFLIST_

#include <typeinfo>
#include "node.hpp"

template<typename B, typename D>
class StuffList {
private:
  Node* head;

protected:
  Node* predecessor(const B& e);
  Node* successor(const B& e);
  void insertAfter(const B& a, Node* p);
  void insertAfter(const B& a, const D& c, Node* p);
  void removePos(Node* p);

public:
  StuffList();
  ~StuffList();
  StuffList(const StuffList& src);
  StuffList& operator=(const StuffList& src);
  //API
  void insert(const B& a);
  void insert(const B& a, const D& c);
  void remove(const B& a);
  void displayAll() const;
  void clear();
};

template<typename B, typename D>
StuffList<B,D>::StuffList() : head(NULL) {}

template<typename B, typename D>
StuffList<B,D>::~StuffList() {
  clear();
}

template<typename B, typename D>
StuffList<B,D>::StuffList(const StuffList<B,D>& src) {
  Node* p = src.head;
  head = NULL;
  while(p != NULL) {
    // use typeid to figure out what p is actually pointing to
    if(typeid(*p) == typeid(DerivedElem<B,D>))
      insert(dynamic_cast<DerivedElem<B, D>*>(p)->getBelem(), dynamic_cast<DerivedElem<B,D>*>(p)->getDelem());
    else
      insert(dynamic_cast<BaseElem<B>*>(p)->getBelem());
    p = p->getNext();
  }
}

template<typename B, typename D>
StuffList<B,D>& StuffList<B,D>::operator=(const StuffList<B,D>& src) {
  Node* p = src.head;
  clear();
  while(p != NULL) {
    if(typeid(*p) == typeid(DerivedElem<B,D>))
      insert(dynamic_cast<DerivedElem<B, D>*>(p)->getBelem(), dynamic_cast<DerivedElem<B,D>*>(p)->getDelem());
    else
      insert(dynamic_cast<BaseElem<B>*>(p)->getBelem());
    p = p->getNext();
  }
  return *this;
}

template<typename B, typename D>
Node* StuffList<B,D>::predecessor(const B& a) {
  Node* p = head;
  Node* pred = NULL;
  while(p != NULL) {
    if(a > dynamic_cast<BaseElem<B>*>(p)->getBelem())
      pred = p;
    p = p->getNext();
  }
  return pred;
}

template<typename B, typename D>
Node* StuffList<B,D>::successor(const B& a) {
  Node* p = head;
  while(p != NULL && a != dynamic_cast<BaseElem<B>*>(p)->getBelem())
    p = p->getNext();
  if(p != NULL && a == dynamic_cast<BaseElem<B>*>(p)->getBelem())
    return p;
  else
    return NULL;
}

template<typename B, typename D>
void StuffList<B,D>::insertAfter(const B& a, Node* p) {
  if(p == NULL)
    head = new BaseElem<b>(head, a);
  else
    p->setNext(new BaseElem<B>(p->getNext(), a));
}



template
#endif
