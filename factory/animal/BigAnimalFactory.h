#ifndef __Factory_BigAnimalFactory__
#define __Factory_BigAnimalFactory__
#include "IAnimalFactory.h"
class BigAnimalFactory : public IAnimalFactory {
  public:
  BigAnimalFactory ();
  ~BigAnimalFactory ();
  virtual IAnimal* CreateAnimal();
};

#endif /* __Factory_BigAnimalFactory__ */
