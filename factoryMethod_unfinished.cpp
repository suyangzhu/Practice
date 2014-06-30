#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
class Shape {
  public:
  std::string name;
  Shape(std::string name) : name(name) {}
  virtual void draw();
  virtual void erase();
};

class Circle : public Shape {
  public: 
  Circle(std::string name) : Shape(name) {}

  void draw() {
    std::cout << " Circle Draw " << std::endl;
  }

  void erase() {
    std::cout << " Circle Erase " << std::endl;
  }
};

class Square : public Shape {
  public:
  Square(std::string name) : Shape(name) {}
  
  void draw() {
    std::cout << " Square Draw " << std::endl;
  }

  void erase() {
    std::cout << " Square Erase " << std::endl;
  }
};

class ShapeFactory {
  protected:
  Shape factoryMethod(std::string aName) ;
  public:
  void anOperation(std::string aName) {
    Shape s = factoryMethod(aName);
    std::cout << " The current shape is :" << s.name;
    s.draw();
    s.erase();
  }
};

class CircleFactory : public ShapeFactory {
  protected:
  Shape factoryMethod (std::string aName) {
    std::string str = aName + " (created by CircleFactory)";
    Circle cl(str);
    return cl;
  }
};

class SquareFactory : public ShapeFactory {
  protected:
  Shape factoryMethod (std::string aName) {
    std::string str = aName + " (created by SquareFactory)";
    Square sq(str);
    return sq;
  }
};

int main() {
  ShapeFactory* sf1 = new CircleFactory;
  ShapeFactory* sf2 = new SquareFactory;

  std::cout << "Welcome to Factory Method Patterns" << std::endl;
  sf1->anOperation("Shape_Circle");
  sf2->anOperation("Shape_Square");
  return 0;
}
















