#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
class Solution {
public:

    vector<int> plusOne(vector<int> &digits) {
        int carry = 0;
        int size = digits.size();
        int i;
        vector<int> littleEndian;
        vector<int> bigEndian;
        if (size <1)
          return bigEndian;
        int unitDigit = digits[size-1] + 1;
        if (unitDigit == 10) {
            unitDigit = 0;
            carry = 1;
        } else {
            carry = 0;
        }
        std::cout << "----" << std::endl;
        littleEndian.push_back(unitDigit);
        for (i = size - 2; i >= 0; i++) {
            int newDigit = digits[i] + carry;
            if (newDigit == 10) { 
                newDigit = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            littleEndian.push_back(newDigit);
        } 
        std::cout << "++++" << std::endl;
        if (carry == 1) 
            littleEndian.push_back(carry);
        size = littleEndian.size();
        for (i = 0; i < size; i++) {
            bigEndian.push_back(littleEndian.at(size - i - 1));
        }
        return bigEndian;
    }
};
int main() {
  Solution sol;
  int i;
  vector<int> vec; 
  int a[] =  {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
  int size = sizeof(a) / sizeof(int);
  for (i = 0; i < size; i++) 
      vec.push_back(a[i]);
  sol.plusOne(vec);
  return 0;

}
