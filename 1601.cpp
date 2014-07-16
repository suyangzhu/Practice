#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class Employee {
  public:
  Employee() ;
  virtual ~Employee() = 0;
  void setName(std::string name) {
    mName = name;
  }
  void setAddress(std::string address) {
    mAddress = address;
  }
  private:
  std::string mName;
  std::string mAddress;
  int         mId;
};
