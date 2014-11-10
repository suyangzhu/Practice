#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<typename T>
class Stack {
public: 
	Stack() {}
	~Stack() {}
	void Push(T elem) {
		mainStack.push(elem);
		std::cout << elem << std::endl;
		if (minStack.empty() || elem <= Min()) {
			minStack.push(elem);
		}	
		if (maxStack.empty() || elem >= Max()) {
			maxStack.push(elem);
		}
	}

	T Top() {
		return mainStack.top();
	}

	void Pop() {
		if (minStack.top() == mainStack.top()) {
			minStack.pop();
		}
		if (maxStack.top() == mainStack.top()) {
			maxStack.pop();
		}
		mainStack.pop();
	}

	T Min() {
		return minStack.top();
	}

	T Max() {
		return maxStack.top();
	}

	bool Empty() {
		return mainStack.empty();
	}
private:
	stack<T> mainStack;
	stack<T> minStack;
	stack<T> maxStack;
};
