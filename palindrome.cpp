#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int digitValue(int digit) {
  int result = 1;
  int i;
  for (i  = 0; i < digit; i++) {
    result*=10;
  }
  return result;
}

bool isPanilome(int n) {
  int len = 0; 
  int num = n;
  while (n) {
    n /=10;
    len++;
  }
  int num1 = num; 
  int num2 = num;
  int i;
  for (i = 0; i < len; i++) {
    if (num1 / digitValue(len - i-1) != num2%10) {
        return false;
    }
    num1 = num1 % digitValue(len-i-1);
    num2 /= 10;
  }
  return true;
}


int main() {
  if (isPanilome(10))
    std::cout << "yes" << std::endl;
}
