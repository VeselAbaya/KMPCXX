#include <iostream>
#include <string>

#include "../header/cycle_shift.h"

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
  std::cout << cycle_shift(s1, s2);

  return 0;
}
