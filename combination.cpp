#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
/* need to think more about this problem.
   think about more about combinations. */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > vec;
        queue<vector<int> > combineQueue;
        if (k > n)  
            return vec;
        int i;
        for (i = 1; i <= n; i++) {
            vector<int> initRow;
            initRow.push_back(i);
            combineQueue.push(initRow);
        }
        while (!combineQueue.empty()) {
            vector<int> current = combineQueue.front();
            combineQueue.pop();
            if (current.size() == k)  {
                vec.push_back(current);
            } else {
                for (i = 1; i <= n; i++) { 
                  if (find(current.begin(), current.end(), i) == current.end()) {
                    vector<int> next = current;
                    next.push_back(i);
                    combineQueue.push(next);
                  }
                }
            }
        }
        return vec;
    }
};

int main() {
  Solution sol;
  vector<vector<int> > vec = sol.combine(4, 4);
  int i, j;
  int size1 = vec.size();
  for (i = 0; i < size1; i++) {
    for (j = 0; j < 4; j++) {
      std::cout << vec[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
