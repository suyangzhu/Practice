#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
  string str = "hello world";
  vector<string> vec;
  vec.push_back(str);
  std::cout << str.size() << std::endl;
  std::cout << vec[0][0] << std::endl;
  return 0;
}
