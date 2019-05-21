#include <string>
#include <iostream>
#include <vector>

#include "../header/KMP.h"

int main() {
  std::string pattern, str;
  std::cin >> pattern >> str;
  std::vector<size_t> res = KMP(str, pattern);

  // output
  if (res.size() > 0){
    for (int i = 0; i < res.size(); i++) {
      std::cout << res[i];
      if (i != res.size() - 1) {
        std::cout << ",";
      }
    }
  }
  else {
    std::cout << "-1";
  }

  return 0;
}