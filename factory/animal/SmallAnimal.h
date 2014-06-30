#ifndef __Factory_SmallAnimal__
#define __Factory_SmallAnimal__

#include "IAnimal.h"

class SmallAnimal : public IAnimal {
  public:
  SmallAnimal();
  ~SmallAnimal();

  void Laugh();
  void Cry();
  void Talk();
};

#endif /* __Factory_SmallAniaml__ */
