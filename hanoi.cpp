#include <cstdio>
#include <cstdlib>
#include <iostream>

/**
 * @file hanoi
 *
 * @brief move plates across needles
 *        recursionly.
 */

// -> move top n - 1 plates from needle 1 to needle 2 using needle 3 
//    as intermidiate needle.
// -> move plates n from 1 to 3.
// -> move n-1 plates from 2 to 3 using 1 as intermediate needle.

void move(int num, int src, int dest, int mid) {
  if (num > 0) {
    move(num - 1, src, mid, dest);
    std::cout << "move plate " << num << " from " << src << " to " << dest << " using " << mid << std::endl;
    move(num - 1, mid, dest, src);
  }
}

int main() {
  move(8, 1, 3, 2);
  return 0;
}
