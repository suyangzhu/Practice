#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
/**
 * Definition for binary tree */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int digitValue(int digit) {
        int val = 1;
        int i;
        for (i = 0; i < digit; i++) 
            val *= 10;
        return val;
    }
    int vec2num(vector<TreeNode*>& vec) {
        int sum = 0; 
        int i;
        int size = vec.size();
        for (i = 0; i < size ; i++) {
          std::cout << vec[i]->val;
            sum += vec[i]->val * digitValue(size - i - 1);
        }
        std::cout << std::endl;
        return sum;
    }
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        int i;
        int size;
        vector<TreeNode*> vec;
        queue<vector<TreeNode*> > myQueue;
        vec.push_back(root);
        myQueue.push(vec);
        if (!root) 
            return 0;

                while (!myQueue.empty()) {
               vector<TreeNode*> cur = myQueue.front();
               myQueue.pop();
               if (cur.back()->left != NULL) {
                    vector<TreeNode*> leftVec = cur;
                    leftVec.push_back(cur.back()->left);
                    myQueue.push(leftVec);
               } 
               if (cur.back()->right != NULL) {
                   vector<TreeNode*> rightVec = cur;
                   rightVec.push_back(cur.back()->right);
                   myQueue.push(rightVec);
               }
               if(cur.back()->left == NULL && cur.back()->right == NULL)  {

                    sum += vec2num(cur);
               }
               
        }
        return sum;
    }
};

int main() {
  TreeNode root(1);
  TreeNode left(2);
  TreeNode right(3);
  TreeNode leftLeft(4);
  TreeNode leftRight(5);
  TreeNode rightLeft(7);
  root.left = &left;
  root.right = &right;
  left.left = &leftLeft;
  left.right = &leftRight;
 right.left = &rightLeft;
  Solution sol;
  cout << sol.sumNumbers(&root) << endl;
  return 0;

}
