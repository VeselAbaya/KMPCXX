#include "../header/cycle_shift.h"

int cycle_shift(std::string const &s1, std::string const &s2){
  int index = prefix_func(s1 + "|" + s2).back();

  if (index == s1.size()) {
    return 0;
  }

  return index + prefix_func(s2 + "|" + s1).back() == s1.size() ? index: -1;
}
