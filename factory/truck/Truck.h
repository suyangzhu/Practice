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
  // This must be static 
  static Truck* Create() {
    return new FordTruck();
  }
};

class ChevyTruck : public Truck {
  public:
  ChevyTruck()  {}
  ~ChevyTruck () { std::cout << "Delete Chevy Truck " << std::endl; } 

  void Make () {
    std::cout << "Chevy" << std::endl;
  }

  static Truck* Create( ) {
    return new ChevyTruck();
  }
};

