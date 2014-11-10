#include "min_max_stack.hpp"

int main() {
	Stack<int> s;
	s.Push(4);
	for (int i = 0; i < 10; i++) {
		s.Push(i);
	}
	while  (!s.Empty()) {
		std::cout << s.Top() << " " << s.Min() <<  " " << s.Max() << std::endl;
		s.Pop();
	}
	return 0;
}
