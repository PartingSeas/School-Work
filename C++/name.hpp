#ifndef NAME_H
#define NAME_H

class Name {
private:
  std::string first;
  std::string second;

public:
  Name(const std::string& name1="", const std::string& name2="") : first(name1), second(name2){

  bool operator<(const Name& name) const;
  bool operator>(const Name& name) const;

  friend std::istream& operator>>(std::istream& in, Name& name);
  friend std::ostream& operator<<(std::ostream& out, const Name& name);
}
inline bool operator<(const Name& name) const {
  return second < name.second || (second == name.second && first < name.first);
}
inline bool operator>(const Name& name) const {
  return second > name.second || (second == name.second && first > name.first);
}

inline std::istream& operator>>(std::istream& in, Name& name) {
  in >> name.first >> name.second;
  return in;
}
};
