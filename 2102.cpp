#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

// enum for word.
  std::string str1[10] = {" ", "one", "two", "three",
                          "four", "five", "six",
                          "seven", "nine"};
  std::string str2[10] = {"ten", "eleven", "twelve",
                          "thirteen", "fourteen", "fifteen",
                          "sixteen", "seventeen", "eighteen",
                          "ninteen"};
  std::string str3[8] = {"twenty", "thirty", "forty",
                          "fifty", "sixty", "seventy",
                          "eighty", "ninety"};
std::string digit2word(int num) {
  int m, n, k;
  std::string str = "";
  m = num / 100;        /**< hundred digit. */
  n = ((num % 100)/10); /**< ten digit. */
  k = ((num % 100) % 10); /**< number digit. */
  if (m != 0) {
    str = str1[m] + " hundred";
  } 

  if (n == 0) {
    if (k == 0) {
      return str;
    }
    else { 
      if (m)
         str += " and " + str1[k];
      else 
        str += str1[k];
      return str;
    }
  } else {
    if (n == 1) { 
      if (m)
        str += " and " +str2[k];
      else 
        str += str2[k];
    } 
    else {
      if (m)
        str += " and " + str3[n-2] +" " + str1[k];
      else 
        str += str3[n-2] + " " + str1[k];
    }
  }
  return str;
}
std::string translate(int num) {
  int digitCnt = 0;
  std::string str1 = "";
  std::string str2 = "";
  if (num == 0)
    return "zero"; 
  if (num > 999) {
    str1 = digit2word(num / 1000);
    if (num % 1000)
      str1 += " thousand, ";
    else 
      str1 += " thousand ";
  }
  str2 = digit2word (num % 1000);
  return str1 + str2; 
}

int main() {
  while (1) {
    int num;
    std::cout << "INPUT Number" << std::endl;
    std::cin >> num;
    std::string str = translate(num);
    std::cout <<str << std::endl;
  }
  return 0;
}
