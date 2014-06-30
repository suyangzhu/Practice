#include "BigAnimalFactory.h"
#include "BigAnimal.h"
#include <iostream>

BigAnimalFactory::BigAnimalFactory() {
  std::cout << "Create BigAnimalFactory" << std::endl;
}

BigAnimalFactory::~BigAnimalFactory() {
  std::cout << "Delete BigAnimalFactory " << std::endl;
}

IAnimal* BigAnimalFactory::CreateAnimal()  {
  return new BigAnimal();
}
