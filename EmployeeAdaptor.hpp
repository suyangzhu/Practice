#include "employee.hpp"
#include <iostream>
template<typename EmplyeeType> 
struct EmployeeAdaptor_t {
};

template<>
struct FreshAdaptor_t<Fresh> {
  bool Reply() {
    std::cout <<  "Employee reply" << std::endl;
    return true;
  }
};

template<>
struct TLAdaptor_t<TL>{
  bool Reply() {
    std::cout << "TL reply" << std::endl;
    return true;
  }
};

template<>
struct PMAdaptor_t<PM> {
  bool Reply() {
    std::cout << "PM reply" << std::endl;
  }
};
