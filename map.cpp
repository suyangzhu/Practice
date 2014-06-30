#include <cstdio>
#include <cstdlib>
#include <map>
#include <iterator>
#include <iostream>

typedef std::map<int, int> mapType;
int main() {
  mapType testMap;
  testMap[5] =  1;
  testMap[5] = 2;
  mapType::iterator it = testMap.find(5);
  std::cout << (it->second) << std::endl; 
  
  return 0;
}
