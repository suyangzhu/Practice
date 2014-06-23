#include <iostream>
#include <cstdio>
#include <cstdlib>
#define BITSIZE 4

int indexFirstZeroAfterOne(int num) {
  int cur = 1;
  int result;
  int i = 0;
  int counter = 0;
  int mask = ~0;
  int allOnes =  ~0;
  while (!(cur & num)) {
    cur = cur << 1;
    i++;
  } 
  while ((cur & num) && (i < BITSIZE * sizeof(int))) {
    cur = cur << 1;
    // Number of 1;
    counter++;
    i++;
  }
  // Now i is the index of first 0 after 1 turn it on
  // and turn this bit on. 
  mask -= (cur - 1);
  int tmp = mask & num;
  std::cout << tmp << "  " << cur <<  " " << ~(allOnes << (counter - 1)) <<  std::endl;
  result = (mask & num) + cur + (~(allOnes << (counter-1)));
  std::cout << result << std::endl;
  return result; 
}

int indexFirstOneAfterZero(int num) {
  int cur = 1;
  int i;
  int counter = 0; 
  int mask = ~0;

  while ((cur & num)) {
    cur = cur << 1;
    i++;
  }
  while (!(cur & num) && (i < BITSIZE * sizeof(int))) {
    cur =  cur << 1;
    // Number of zeros;
    counter++;
    i++;
  }
  mask -= ((cur << 1)- 1);

}

int main() {
  int n = 44;
  std::cout << n <<  "  " << indexFirstZeroAfterOne(n) << std::endl;
  return 0;
}
