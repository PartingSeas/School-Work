#ifndef _ELIST_
#define _ELIST_

#include <typeinfo>
#include "node.hpp"


class EList {
private:
  Node* head;

protected:
  Node* predecessor(const std::string& n);
  Node* successor(const std::string& n);
  void insertAfter(const std::string& n, const DIPLOMA d, const double sal, Node* p);
  void insertAfter(const std::string& n, const DIPLOMA d, const double sal, const SWE ex, const std::string& sk, Node* p);
  void insertAfter(const std::string& n, const DIPLOMA d, const double sal, const AEX ex, Node* p);
  void  removePos(Node* p);

public:
  EList();
  ~EList();
  EList(const EList& src);
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


#endif
