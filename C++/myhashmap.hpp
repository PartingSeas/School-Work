#ifndef MYHASHMAP_HPP
#define MYHASHMAP_HPP

#include <list>
#include <vector>
#include "mypair.hpp"

//hashmap with separate chaining (key, value, comparator)
template <typename K, typename V, typename H>
class MyHashMap {
public:
  typedef MyPair<K, V> Entry;
  class Iterator;
public:
  MyHashMap(int capacity = 100);
  Iterator find(const K& k);
  Iterator put(const K& k, const V& v);
  Iterator begin();
  Iterator end();
  int size() const;
  bool empty() const;
  void erase(const K& k);
  void erase(const Iterator& p);
protected:
  //bucket's next entry and end of bucket
  static void nextEntry(Iterator& p) {
    ++p.ent;
  }
  static bool endOfBkt(const Iterator& p) {
    return p.ent == p.bkt->end();
  }
  typedef std::list<Entry> Bucket;
  typedef std::vector<Bucket> BktArray;
  typedef typename BktArray::iterator BItor;
  typedef typename Bucket::iterator EItor;
  //
  Iterator finder(const K& k);
  Iterator inserter(const Iterator& p, const Entry& e);
  void eraser(const Iterator& p);
private:
  //entries
  int n;
  //comparator
  H hash;
  //bucket array
  BktArray B;
public:
  //identify entry position in the hashmap (bucket array, bucket itself. current entry)
  class Iterator {
  private:
    //entry
    EItor ent;
    //bucket
    BItor bkt;
    const BktArray* ba;
  public:
    Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor()) : ent(q), bkt(b), ba(&a) {}
    Entry& operator*() const;
    Entry& operator*();
    bool operator==(const Iterator& p) const;
    Iterator& operator++();
    friend class MyHashMap;
  };
};


template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Entry& MyHashMap<K,V,H>::Iterator::operator*() const {
  return *ent;
}

template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Entry& MyHashMap<K,V,H>::Iterator::operator*() {
  return *ent;
}

template <typename K, typename V, typename H>
bool MyHashMap<K,V,H>::Iterator::operator==(const Iterator& p) const {
  if(ba != p.ba || bkt != p.bkt)
    return false;
  else if(bkt == ba->end())
    return true;
  else
    return ent == p.ent;
}

template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Iterator& MyHashMap<K,V,H>::Iterator::operator++() {
  ++ent;
  if(endOfBkt(*this)) {
    ++bkt;
    //find non-empty bucket
    while(bkt != ba->end() && bkt->empty)
      ++bkt;
    //end of bucket array
    if(bkt == ba->end())
      return *this;
    //first non empty bucket
    ent = bkt.begin();
  }
  return *this;
}

template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Iterator MyHashMap<K,V,H>::begin() {
  BItor bkt = B.begin();
  if(empty())
    return end();
  else {
    //find non-empty bucket
    while(bkt->empty())
      ++bkt;
    //return first bucket
    return Iterator(B, bkt, bkt->begin());
  }
}

template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Iterator MyHashMap<K,V,H>::end() {
  return Iterator(B, B.end());
}


template <typename K, typename V, typename H>
MyHashMap<K,V,H>::MyHashMap(int capacity) : n(0), B(capacity) {}

template <typename K, typename V, typename H>
int MyHashMap<K,V,H>::size() const {
  return n;
}

template <typename K, typename V, typename H>
bool MyHashMap<K,V,H>::empty() const {
  return size() == 0;
}

template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Iterator MyHashMap<K,V,H>::finder(const K& k) {
  //get hash index (apply hash funcion on the key modulo array size)
  int i = H(k) % B.size();
  //add index to the beginning iterator (bkt)
  BItor bkt = B.begin() + i;
  Iterator p(B, bkt, bkt->begin());
  //search for k (p is an iterator so shorthand notation -> does not apply here)
  while(!endOfBkt(p) && (*p).getFirst() != k)
    nextEntry(p);
  //return final position
  return p;
}

template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Iterator MyHashMap<K,V,H>::find(const K& k) {
  Iterator p = finder(k);
  if(endOfBkt(p))
    return end();
  else
    return p;
}

template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Iterator MyHashMap<K,V,H>::inserter(const Iterator& p, const Entry& e) {
  //insert before p, update entries and return position
  EItor ins = p.bkt->insert(p.ent, e);
  n++;
  return Iterator(B, p.bkt, ins);
}

template <typename K, typename V, typename H>
typename MyHashMap<K,V,H>::Iterator MyHashMap<K,V,H>::put(const K& k, const V& v) {
  //search key and if found replace value ow add at the end of the bucket
  Iterator p = finder(k);
  if(endOfBkt(p))
    return inserter(p, Entry(k,v));
  else {
    //p.ent->setValue(v);
    p.ent->setSecond(v);
    return p;
  }
}

template <typename K, typename V, typename H>
void MyHashMap<K,V,H>::eraser(const Iterator& p) {
  p.bkt->erase(p.ent);
  n--;
}

template <typename K, typename V, typename H>
void MyHashMap<K,V,H>::erase(const Iterator& p) {
  eraser(p);
}

template <typename K, typename V, typename H>
void MyHashMap<K,V,H>::erase(const K& k) {
  //search key and if found erase it
  Iterator p = finder(k);
  if(!endOfBkt(p))
    eraser(p);
}

#endif
