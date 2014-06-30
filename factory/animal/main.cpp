#include <iostream>
#include "IAnimal.h"
#include "BigAnimal.h"
#include "SmallAnimal.h"
#include "BigAnimalFactory.h"
#include "SmallAnimalFactory.h"

void DoFactoryMethod1 () {
  IAnimalFactory *pAnimalFactory = new BigAnimalFactory();
  IAnimal* pAnimal = pAnimalFactory->CreateAnimal();
  pAnimal->Cry();
  pAnimal->Laugh();
  pAnimal->Talk();
  delete pAnimal;
  delete pAnimalFactory; 
}
void DoFactoryMethod2 () {
  IAnimalFactory *pAnimalFactory = new SmallAnimalFactory();
  IAnimal* pAnimal = pAnimalFactory->CreateAnimal();
  pAnimal->Cry();
  pAnimal->Laugh();
  pAnimal->Talk();
  delete pAnimal;
  delete pAnimalFactory; 
}

int main() {
  DoFactoryMethod1();
  DoFactoryMethod2();
  return 0;
}
