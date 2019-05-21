#include "../header/KMP.h"

std::vector<size_t> KMP(std::string const& str, std::string const& pattern) {
  std::vector<size_t> p = prefix_func(pattern);
  std::vector<size_t> result;
  size_t str_i = 0, pattern_i = 0;
  while (str_i < str.length()){
    if (str[str_i] == pattern[pattern_i]){
      str_i++;
      pattern_i++;
      if (pattern_i == pattern.size()){
        result.push_back(str_i-pattern.size());
      }
    }
    else if (pattern_i == 0){
      str_i++;
    }
    else {
      pattern_i = p[pattern_i-1];
    }
  }

  return result;
}
