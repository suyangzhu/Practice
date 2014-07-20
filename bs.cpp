#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    bool binarySearchRow(vector<int> row, int start, int end, int target) {
        if (end < start) 
            return false;
        int mid = (start+end)/2;
        if (row[mid] == target) 
            return true;
        else if (target < row[mid]) {
            return binarySearchRow(row, start, mid-1, target);
        } else {
            return binarySearchRow(row, mid+1, end, target);
        }
    }
    bool binarySearchMatrix(vector<vector<int> >& matrix, int start, int end, int target) {
      std::cout << "binarySeachMatrix: start, end, target " << start<<end<<target << std::endl; 
        if (end <= start) 
            return false;
        int mid = (start + end) / 2;
        std::cout << "mid = " << mid << std::endl;
        std::cout << "front " << matrix.at(mid).front() << std::endl;
        std::cout << "back " << matrix.at(mid).back() << std::endl;  
        std::cout << "target " << target << std::endl;
        if (target < matrix.at(mid).front()) {
          std::cout << "case 1" << std::endl;
            return binarySearchMatrix(matrix, start, mid - 1, target);
        }
        else 
        if (target > matrix.at(mid).back()){
          std::cout << "case 2" << std::endl;
            return binarySearchMatrix(matrix, mid+1, end, target);
        } 
        else  {
          std::cout << "case 3" << std::endl;
            return binarySearchRow(matrix.at(mid), 0, matrix.at(mid).size(), target);
        }
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int size = matrix.size();
        if (size == 0) {
            return false;
        }
        return binarySearchMatrix(matrix, 0, size, target);
        
    }
};

int main() {
  vector<vector<int> > matrix;
  vector<int> row;
  row.push_back(1);
  matrix.push_back(row);
  Solution sol;
  if (sol.searchMatrix(matrix, 2))
    std::cout << "T" << std::endl;
  else 
    std::cout << "F" << std::endl;
  return 0;
}
