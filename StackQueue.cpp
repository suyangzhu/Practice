#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

stack<int> s1;
stack<int> s2;

void push(int elem) {
	s1.push(elem);
}	

int front() {
	if (!s2.empty()) return s2.top();
	else {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		return s2.top();
	}
}

void pop()  {
	if (!s2.empty()) s2.pop(); 
	else {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}
}

int count() {
	return s1.size() + s2.size();
}

int main() {
	push(1);
	push(2);
	push(3);
	std::cout << front();
	pop();
	std::cout << front();
	
}
