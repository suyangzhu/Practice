#include "BigAnimal.h"
#include <iostream>

BigAnimal::BigAnimal() {
  std::cout << "Create BigAnimal" << std::endl;
}

BigAnimal::~BigAnimal() {
  std::cout << "Delete BigAnimal" << std::endl;
}

void BigAnimal::Laugh () {
  std::cout << "Big Laugh" << std::endl;
}

void BigAnimal::Cry() {
  std::cout << "Big Cry" << std::endl;
}

void BigAnimal::Talk() {
  std::cout << "Big Talk" << std::endl;
}


