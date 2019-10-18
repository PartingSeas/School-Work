#ifndef MYMAP_HPP
#define MYMAP_HPP

template<typename K, typename V> class myMap {
public:
  myMap(const k& k = K(), const V& v = V()) : dkey(k), dvalue(v) {}
  const K& key() const {
    return dkey;
  }
  const V& value() const {
    return dvalue;
  }
  void setKey(const K& k) {
    dkey = k;
  }
  void setValue(const V& v) {
    dvalue = v;
  }
private:
  K dkey;
  V dvalue;
};

#endif
