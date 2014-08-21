#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) 
            return true;
        if (n == 1) 
            return true;
        if (n == 2 && A[0] < 1) 
            return false;
        if (n == 2 && A[0] >=1) {
            return true;
        }
        int index = n - 2;
        while (index) {
          std::cout << index << std::endl;
            if ((n -1 - index) <= A[index]) {
              std::cout << (index + 1) << std::endl;
                return canJump(A, index + 1);
            }
            index--;
        }
        std::cout << index << std::endl;
        if ((n-1) > A[0] ) 
            return false;
        else 
            return true;
    }
};

int main() {
  int A[4] = {1, 1, 1, 0};
  Solution sol;
  if (sol.canJump(A, 4))  
     std::cout << "can" << std::endl;
  else 
     std::cout << "cannot " << std::endl;

  return 0;
}
