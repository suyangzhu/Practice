#ifndef __Factory_IAnimalFactory__
#define __Factory_IAnimalFactory__

#include "IAnimal.h"

class IAnimalFactory {
  public:
  IAnimalFactory() {}
  ~IAnimalFactory() {}
  virtual IAnimal* CreateAnimal() = 0;
};

#endif /* __Factory_IAnimalFactory__ */
