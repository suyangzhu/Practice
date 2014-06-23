#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
int IntVal(const float& var) {
  return ((int) var);
}

float FloatVal(const float& var) {
  return (var - IntVal(var));
}

std::string IntBinary(const float& var) {
  int intValue = IntVal(var);
  std::string result = "0x";
  std::string bit;
  std::vector<std::string> digitContainer;
  while (intValue > 0) {
    bit = std::to_string(intValue % 2);
    digitContainer.push_back(bit);
    intValue /= 2;
  }
  for (std::vector<std::string>::iterator it = digitContainer.end() -1;
       it >= digitContainer.begin(); it--) {
    result += *it;
  }
  return result;
}

std::string FloatBinary(const float& var) {
  float floatValue = FloatVal(var);
  // 10 digits at most;
  int precision = 10;
  int intValue;
  std::string result = ".";
  std::string bit;
  std::vector<std::string> digitContainer;
  while (precision) {
    if (floatValue == 0) {
      break;
    } else {
      intValue = IntVal(floatValue * 2);
      bit = std::to_string(intValue);
      digitContainer.push_back(bit);
      floatValue = floatValue * 2 - intValue;
      precision--;
    }
  }
  for (std::vector<std::string>::iterator it = digitContainer.end() -1;
       it >= digitContainer.begin(); it--) {
    result += *it;
  }
  return result;
}

std::string Decimal2Binary (const float& var) {
  return IntBinary(var) + FloatBinary(var);
}


int main()  {
  std::cout << Decimal2Binary(4.0121) <<  std::endl;
  return 0;
}
