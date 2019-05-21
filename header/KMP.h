#ifndef KMP_KMP_H
#define KMP_KMP_H

#include <vector>
#include <string>

#include "prefix_func.h"

std::vector<size_t> KMP(std::string const& str, std::string const& pattern);


#endif //KMP_KMP_H
