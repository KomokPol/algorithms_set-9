#include "common.h"

uint64_t cmp_count = 0;

int CompareStrings(const std::string& a, const std::string& b) {
  size_t i = 0;
  while (i < a.size() && i < b.size()) {
    ++cmp_count;
    if (a[i] < b[i]) {
      return -1;
    }
    if (a[i] > b[i]) {
      return 1;
    }
    ++i;
  }
  if (a.size() < b.size()) {
    return -1;
  }
  if (a.size() > b.size()) {
    return 1;
  }
  return 0;
}
