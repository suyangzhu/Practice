#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

class FindSingle{
  public:
  int singleNumber(int array[], int size) {
    std::sort(array, array+size);
    int i;
    for (i = 0; i < size-1; i+=2) {
      if (array[i] != array[i+1])
        return array[i];
    }
    return array[size-1];
  }

  int singleNumber2(int array[], int size) {
    int result = 0;
    int i;
    for (i = 0; i < size; i++)
      result ^= array[i];
    return result;
  }
};

int main() {
  int array[9] = {0, 1, 2, 3,3,2,1,9, 0};
  FindSingle find;
  std::cout << find.singleNumber2(array, 9) << std::endl;
  return 0;
}
