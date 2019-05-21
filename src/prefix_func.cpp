#include "../header/prefix_func.h"

std::vector<size_t> prefix_func(std::string const& str) {
  std::vector<size_t> entries(str.length());
  for (int forward_i = 1; forward_i < str.length(); forward_i++) {
    int back_i = entries[forward_i - 1];

    while ((back_i > 0) && (str[forward_i] != str[back_i])) {
      back_i = entries[back_i - 1];
    }

    if (str[forward_i] == str[back_i]) {
      ++back_i;
    }

    entries[forward_i] = back_i;
  }

  return entries;
}