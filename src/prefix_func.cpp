#include "../header/prefix_func.h"

std::vector<int> prefix_func(std::string str) {
  std::vector<int> entries(str.length());
  for (int i = 1; i < str.length(); i++) {
    int j = entries[i - 1];
    while ((j > 0) && (str[i] != str[j]))
      j = entries[j - 1];
    if (str[i] == str[j])
      ++j;
    entries[i] = j;
  }
  return entries;
}