#include "std_merge_sort.h"
#include "common.h"

std::vector<std::string> StdMerge(std::vector<std::string> p, std::vector<std::string> q) {
  std::vector<std::string> res;
  size_t i = 0;
  size_t j = 0;
  while (i < p.size() && j < q.size()) {
    if (CompareStrings(p[i], q[j]) <= 0) {
      res.push_back(p[i]);
      ++i;
    } else {
      res.push_back(q[j]);
      ++j;
    }
  }
  while (i < p.size()) {
    res.push_back(p[i]);
    ++i;
  }
  while (j < q.size()) {
    res.push_back(q[j]);
    ++j;
  }
  return res;
}

std::vector<std::string> StdMergeSort(std::vector<std::string> arr) {
  if (arr.size() <= 1) {
    return arr;
  }
  size_t m = arr.size() / 2;
  auto p = StdMergeSort(std::vector<std::string>(arr.begin(), arr.begin() + m));
  auto q = StdMergeSort(std::vector<std::string>(arr.begin() + m, arr.end()));
  return StdMerge(p, q);
}
