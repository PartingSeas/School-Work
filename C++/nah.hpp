#ifndef _NAH_
#define _NAH_

#include <string>
#include <iostream>

enum DIPLOMA {HS, BS, BA, MS, MBA, PHD};
enum SWE {FULLSTACK, WEB, IT, APP, ANALYST, INTERN};
enum AEX {SCRIPT, FX, EDITING, SOUND, NONE};

class Node {
private:
  Node* next;
  std::string name;
  double salary;
  DIPLOMA degree;
  SWE expertise;
  std::string skills;

protected:
  // Node objects cannot be created
  Node(Node* s=NULL) : next(s) {}

public:
  // pure virtual function makes Node an abstract class
  // virtual destructor ensures derived classes are destructed properly when
  // pointed by a Node*
  virtual ~Node() {}
  virtual void display() const = 0;
  Node* getNext() const {
    return next;
  }
  void setNext(Node* s) {
    next = s;
  }
};

// constructor and destructor
// name(string), salary (double), degree(DIPLOMA)
// function def of accessors (getName, getSalary, etc) and setters (setName, setSalary, etc)

class Employee : public Node{
private:
  std::string name;
  double salary;
  DIPLOMA degree;
public:
  // constructor and destructor
  Employee(Node* s =NULL, const std::string& n="", const DIPLOMA d=HS, const double sal=0.0): Node(s), name(n), salary(sal), degree(d){}
    //node(NULL), name(fullname), salary(money), degree(compdeg)
    // expertise(swe), skills(string)
    void setName(const std::string& n) {
      name = n;
    }
    void setDeg(const DIPLOMA d){
      degree = d;
    }=
    void setSalary(const double sal){
      salary = sal;
    }
    const std::string& getName() const {
      return name;
    }
    double getSalary() const {
      return salary;
    }
    DIPLOMA getHighestDegree() const {
      return degree;
    }
    void display() const {
      std::cout << name << " (" << degree << ", $" << salary << ")";
    }
};

class SoftwareDeveloper : public Employee {
private:
  SWE expertise;
  std::string skills;

public:
  SoftwareDeveloper(Node* s=NULL, const std::string& n="", const DIPLOMA d=HS, const double sal =0.0, const SWE ex=INTERN, const std::string& sk="") :
  Employee(s, n, d, sal), expertise(ex), skills(sk) {}
// constructor and destructor
  void setExpertise(const SWE ex) {
    expertise = ex;
  }
  void setSkills(const std::string& sk) {
    skills = sk;
  }
  SWE getExpertise() const {
    return expertise;
  }
  const std::string& getSkills() const {
    return skills;
  }
  void display() const {
    std::cout << "{ ";
    Employee::display();
    std::cout << " [" << expertise << ", " << skills << "]";
  }
// expertise (AEX)
// accessors and setters
};

class Artist : public Employee {
private:
  AEX artistexpertise;

public:
  Artist(Node* s=NULL, const std::string& n="", const DIPLOMA d=HS, const double sal =0.0, const AEX ex=NONE) :
  Employee(s, n, d, sal), artistexpertise(ex) {}
  void setExpertise(const AEX ex) {
    artistexpertise = ex;
  }
  AEX getExpertise() const {
    return artistexpertise;
  }
  void display() const {
    std::cout << "{";
    Employee::display();
    std::cout << " [" << artistexpertise << "]";
  }
};
#endif
