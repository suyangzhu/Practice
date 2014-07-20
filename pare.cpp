#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        int i, j;
        if (n == 0) 
            return vec;
        if (n == 1) {
            vec.push_back("()");
            return vec;
        }
        
        vector<string> prev = generateParenthesis(n - 1);
        int size = prev.size();
        for (i = 0; i < size; i++) {
            int len = prev[i].length();
            
            for (j = 0; j < len; j++) {
                string str = prev[i];
                str.insert(j, ")");
                str = "(" + str;
                vector<string>::iterator it;               
                for (it = vec.begin() ; it != vec.end(); it++) {
                  if (str == *it)
                    break;
                }
                if (it == vec.end()) 
                  vec.push_back(str);
            }
        }
        return vec;
    }
};

int main () {
Solution sol;
 vector<string> vec = sol.generateParenthesis(3);
 for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) 
   std::cout << *it << std::endl;

 return 0;
 
}
