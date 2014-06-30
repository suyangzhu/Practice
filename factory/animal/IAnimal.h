#ifndef __Factory_IAnimal__
#define __Factory_IAnimal__

class IAnimal {
  public:
  IAnimal (void) {}
  virtual ~IAnimal (void) {}

  virtual void Laugh()  = 0;
  virtual void Cry() = 0;
  virtual void Talk() = 0; 
};

#endif /* define __Factory_IAnimal__ */
