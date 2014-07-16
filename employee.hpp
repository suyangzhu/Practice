#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
//#include "EmployeeAdaptor.hpp"

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
  void setId(int Id) {
    mId = Id;
  }

  std::string getName() {
    return mName;
  }

  std::string getAddress() {
    return mAddress;
  }
  
  int getId() {
    return mId;
  }
  private:
  std::string mName;
  std::string mAddress;
  int         mId;
};


class Fresher : public Employee {
  public:
  
  private:
  std::string mJob;
};

class TL : public Employee {
  public:
  private:
  std::string mJob;
};

class PM : public Employee {
  public:
  private:
  std::string mJob;
};

class CallHandler {
  public:
  void getCallHandler();
  Fresher* getFirstAvailableFresher() {
    return &frsh;
  }
  TL* getTL() {
    return &tl;
  }
  PM* getPM() {
    return &pm;
  }
  private:
  Fresher frsh;
  PM pm;
  TL tl;
};

void CallHandler :: getCallHandler() {
}  
