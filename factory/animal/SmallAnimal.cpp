#include "SmallAnimal.h"
#include <iostream>

SmallAnimal::SmallAnimal() {
  std::cout << "Create Small Animal" << std::endl;
}

SmallAnimal::~SmallAnimal() {
  std::cout << "Delete Small Animal" << std::endl;
}

void SmallAnimal::Laugh() {
  std::cout << "SmallAnimal Laugh" << std::endl;
}

void SmallAnimal::Cry() {
  std::cout << "SmallAnimal Cry" << std::endl;
}

void SmallAnimal::Talk() {
  std::cout << "SmallAnimal Talk" << std::endl;
}
