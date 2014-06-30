#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include <map>
#include <iostream>
class MyBaseClass {
  public:

  virtual void doSomething() = 0;
};

class MyFactory {
  public:
  void RegisterFactoryFunction(std::string name,
                               std::function<MyBaseClass*(void)> classFactoryFunction);
  static std::shared_ptr<MyBaseClass> CreateInstance(std::string name);
  MyFactory* Instance();
  std::map<std::string, std::function<MyBaseClass*(void)> > factoryFunctionRegistry;
};

class DerivedClassOne : public MyBaseClass {
  public: 
  DerivedClassOne () {}
  virtual ~DerivedClassOne() {}

  virtual void doSomething () { std::cout << "I am class one" << std::endl; }
};

class DerivedClassTwo : public MyBaseClass {
  public:
  DerivedClassTwo () {}
  virtual ~DerivedClassTwo () {}
  virtual void doSomething () { std::cout << "I am class two" << std::endl; }
};

/** Factory determines which concreate class to create. */

void MyFactory::RegisterFactoryFunction(std::string name,
                                        std::function<MyBaseClass*(void)> classFactoryFunction) {
  factoryFunctionRegistry[name] = classFactoryFunction;
}

std::shared_ptr<MyBaseClass> MyFactory::CreateInstance(std::string name) {
  MyBaseClass* instance = NULL;
  auto it = factoryFunctionRegistry.find(name);
  if (it != factoryFunctionRegistry.end())
    instance = it->second();

  if (instance != NULL) 
    return std::shared_ptr<MyBaseClass> (instance);
  else 
    return NULL;
};

MyFactory* MyFactory::Instance() {
  static MyFactory factory;
  return &factory;
}

class Registrar : public MyFactory{
  public:
  Registrar (std::string className, std::function<MyBaseClass*(void)> classFactoryFunction);
};

Registrar::Registrar (std::string name, std::function<MyBaseClass*(void)> classFactoryFunction) {
  MyFactory::Instance()->RegisterFactoryFunction(name, classFactoryFunction);
}

static Registrar registrar("one", [](void) ->MyBaseClass* { return new DerivedClassOne();});
//static Registrar registrar("two", [](void) ->MyBaseClass* { return new DerivedClassTwo();});

int main (int argc, char** argv) {
  auto instanceOne = MyFactory::Instance()->CreateInstance("one");
//  auto instanceTwo = MyFactory::Instance()->CreateInstance("two");
  instanceOne->doSomething();
//  instanceTwo->doSomething();
  return 0;
}









