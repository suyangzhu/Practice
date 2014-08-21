#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int index1 = 0;
        int index3 = 0;
        
        int cnt = 0;
        /* skip all space(if any) at the beginning of the string. */
        while (s[index1] == ' ') {
            index1++;
        }
        /* void string. */
        if (s[index1] == '\0')
            return 0;
        /* delete the spaces at the end of word. */
        while(s[index3] !='\0') {
            index3++;
        }
        index3--;
        while (s[index3] == ' ') {
          std::cout << "_____" << endl;
            index3--;
        }
        std::cout << "index " << index3 << endl;
        while (s[index3] !=' ' && index3 >= 0) {
            cnt++;
            index3--;
        }
        return cnt;
    }
};

int main() {
  char a[10] = "a";
  cout << a[0] << endl;
  cout << a[1] << endl;
  Solution sol;
  cout << sol.lengthOfLastWord(a) << endl;
}
