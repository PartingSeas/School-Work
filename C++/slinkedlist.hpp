#define SLINKEDLIST_HPP

#include <iostream>

template<typename T> class SLinkedList;
template<typename T> std::ostream& operator <<(std::ostream&, const SLinkedList<T>&);


template<typename T>
class SLinkedList {
private:
  SNode* head;


public:
  SLinkedList();
  ~SLinkedList();
  bool empty() const;
  T len() const;
  const T& front() const;
  void addFront(const T& e);
  T removeFront();
  bool remove(T v);
  void reverse();
  void clear();

  friend std::ostream& operator<< <T>(std::ostream& out, const SLinkedList& sl);
};

template<typename T>
SLinkedList<T>::SLinkedList() : head(NULL) {}

template<typename T>
SLinkedList<T>::~SLinkedList() {
  clear();
}

template<typename T>
bool SLinkedList<T>::empty() const {
return head == NULL;
}

template<typename T>
  SLinkedList<T>::len() const {
  SLinkedList<T>::SNode* p = head;
  int i = 0;
  while(p != NULL) {
    i++;
    p = p->next;
  }
  return i;
}
template<typename T>
  SLinkedList<T>::front() const {
  return head ->elem;
}

template<typename T>
void SLinkedList<T>::addFront(const int& e) {
  SLinkedList::SNode* v = new SNode;
  v->elem = e;
  v->next = head;
  head = v;
}

template<typename T>
int SLinkedList<T>::removeFront() {
  SLinkedList::SNode* old = head;
  int v = head->elem;
  head = old->next;
  delete old;
  return v;
}

template<typename T>
bool SLinkedList::remove(int v) {
  SLinkedList::SNode* p1 = head;
  SLinkedList::SNode* p2 = p1;
  if(head->elem == v)
    return removeFront();
  while(p1 != NULL) {
    if(p1->elem == v) {
      p2->next = p1->next;
      delete p1;
      return true;
    }
    p2 = p1;
    p1 = p1->next;
  }
  return false;
}
