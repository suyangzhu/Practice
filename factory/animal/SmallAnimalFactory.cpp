#include "SmallAnimalFactory.h"
#include "SmallAnimal.h"
#include <iostream>

SmallAnimalFactory::SmallAnimalFactory() {
  std::cout << "Create SmallAnimalFactory" << std::endl;
}

SmallAnimalFactory::~SmallAnimalFactory() {
  std::cout << "Delete SmallAnimalFactory " << std::endl;
}

IAnimal* SmallAnimalFactory::CreateAnimal()  {
  return new SmallAnimal();
}
