#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

stack<int> origin;
stack<int> extra;

stack<int> sort() {
	stack<int> a;
       while (!origin.empty()) {
	       int first = origin.top();
	       origin.pop();
	       while (!a.empty() && a.top() < first) {
		       origin.push(a.top());
		       a.pop();
	       }
	       a.push(first);
       }	       
       return a;
}

int main(){
	origin.push(4);
	origin.push(1);
	origin.push(2);
	origin.push(3);
	stack<int> result = sort();
	while (!result.empty()) {
		std::cout <<result.top();
		result.pop();
	}
	std::cout <<std::endl;
}
