#include <iostream>
#include <cstdio>
#include <cstdlib>

class Shape {
public:
	Shape(int r) : wide(r) {}
	~Shape() {}
	virtual int GetArea() = 0;
protected:
	int wide;
};

class Circle : public Shape {
public:
	Circle(int radius) : Shape(radius) {}
	~Circle() {} 
	int GetArea () {
		return 3 * wide;
	}
	/*
	friend std::ostream &operator<<(std::ostream &os, const Circle& c) {
		os << "Circle area is " << c.GetArea() << std::endl;
		return os;
	}
	*/
};	 

class Rectangle : public Shape {
public:
	Rectangle (int w) : Shape(w) {}
	~Rectangle () {}
	int GetArea() {
		return wide * wide;
	}
	Rectangle &operator+(const Rectangle &r) {
		wide += r.wide;
		return *this;
	}

	void Print() {
		std::cout << GetArea() << std::endl;
	}
	/*
	friend std::ostream &operator<<(std::ostream &os, const Rectangle &r) {
		os << "Rectangle area is " << r.GetArea() << std::endl;
		return os;
	}
	*/
};

int main() {
	Rectangle *rec = new Rectangle(10);
	Rectangle b(10);
	b = b+(*rec);
	b.Print() ;
	return 0;
}

