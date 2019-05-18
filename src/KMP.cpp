#include "../header/KMP.h"

std::vector<int> KMP(std::string str, std::string pattern) {
  std::vector<int> p;
  std::vector<int> result;
  p = prefix_func(pattern);
  unsigned long k = 0, j = 0;
  while (k < str.length()){
    if (str[k] == pattern[j]){
      k++;
      j++;
      if (j == pattern.size()){
        result.push_back(k-pattern.size());
      }
    }
    else if (j == 0){
      k++;
    }
    else{
      j = p[j-1];
    }

  }
  return result;
}
