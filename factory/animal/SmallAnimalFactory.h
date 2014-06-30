#ifndef __Factory_SmallAnimalFactory__
#define __Factory_SmallAnimalFactory__
#include "IAnimalFactory.h"

class SmallAnimalFactory : public IAnimalFactory {
  public:
  SmallAnimalFactory ();
  ~SmallAnimalFactory ();
  virtual IAnimal* CreateAnimal();
};

#endif /* __Factory_SmallAnimalFactory__ */
