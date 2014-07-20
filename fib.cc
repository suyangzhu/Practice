#include <iostream>
#include <cstdio>
#include <cstdlib>

int fib(int n) {
  int array[n+1];
  if (n < 3) 
    return n;
  int i;
  array[0] = 1;
  array[1] = 1;
  for (i = 2; i < n+1; i++) 
    array[i] = array[i-1] + array[i-2];
  return array[n];
}

int main() {
  std::cout << "Input fib Number" << std::endl;
  int n;
  std::cin >> n;
  std::cout << "Fib " << n << " is " << fib(n) << std::endl;
  return 0;
}
