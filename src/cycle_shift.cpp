#include "../header/cycle_shift.h"

int cycle_shift(std::string const &s1, std::string const &s2){
  int index = prefix_func(s1 + "|" + s2).back();

  if (index == 0) {
    return -1;
  }

  return index % s1.size();
}
