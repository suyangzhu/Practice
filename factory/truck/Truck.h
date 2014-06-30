#include <iostream>
#include <cstdio>
#include <cstdlib>

class Truck {
  public:
  Truck() {}
  virtual ~Truck() { std::cout << "Delete Truck" << std::endl; }

  virtual void Make() = 0;
};

class FordTruck : public Truck {
  public:
  FordTruck() {}
  ~FordTruck() { std::cout << "Delete Ford Truck " << std::endl; }

  void Make () {
    std::cout << "Ford" << std::endl;
  }
  
  static Truck* Create() {
    return new FordTruck();
  }
};
