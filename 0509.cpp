#include <iostream>
#include <cstdio>
#include <cstdlib>

class Base {
  public:
  Base() { std::cout << "Base constructor" << std::endl;}
  virtual ~Base() { std::cout << "Base destructor" << std::endl;}
};

class Derived : public Base {
  public:
  Derived() {std::cout << "Derived constructor" << std::endl;}
  ~Derived() {std::cout << "Derived destructor" << std::endl;}
};

int main ()  {
  Base* p = new Base();
  delete p;
  return 0; 
}
