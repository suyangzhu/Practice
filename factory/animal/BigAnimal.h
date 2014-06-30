#ifndef __Factory_BigAnimal__
#define __Factory_BigAnimal__

#include "IAnimal.h"

class BigAnimal : public IAnimal {
  public: 
  BigAnimal () ;
  ~BigAnimal ();
  void Laugh();
  void Cry();
  void Talk();
};

#endif /* __Factory_BigAnimal__ */
