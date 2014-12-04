#include <cstdio>
#include <cstdlib>
#include <iostream>

class Animal {
public:
	Animal(){}
	~Animal(){}
	int GetWeight() {
		return weight;
	}
	virtual void Print(){ std::cout << "Animal " << std::endl;} 
private:
	int weight;	
};
class Tiger : virtual public Animal {
public:
	Tiger() {}
	~Tiger() {}
	void Print() {
		std::cout << "I am a Tiger " << std::endl;
	}
};
class Lion : virtual public Animal {
public:
	Lion() {}
	~Lion(){}
	void Print() {
		std::cout << "I am a Lion " << std::endl;
	}
};

class LionTiger : public Tiger, public Animal {
	public:
	LionTiger() {}
	~LionTiger() {}
};

int main() {
	LionTiger *lion = new LionTiger();
	lion->Print();
	return 0;
}
