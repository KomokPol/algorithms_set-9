#include "common.h"
#include "1arq.h"
#include "1aq.h"
#include "1ar.h"

std::vector<std::string> MSBRadixSortHybrid(std::vector<std::string> str_arr, int l) {
  if (str_arr.size() < 74) {
    return TernaryQuickSort(str_arr, l);
  }

  std::vector<std::string> r_excl;
  std::vector<std::string> to_sort;
  for (const std::string& s : str_arr) {
    if (s.size() == l) {
      r_excl.push_back(s);
    } else {
      to_sort.push_back(s);
    }
  }

  std::vector<std::string> sorted_bucket = CountingSort(to_sort, l);

  std::vector<std::vector<std::string>> buckets(128);
  for (const std::string& s : sorted_bucket) {
    buckets[s[l]].push_back(s);
  }

  std::vector<std::string> res = r_excl;
  for (int c = 0; c < 128; ++c) {
    if (buckets[c].empty()) {
      continue;
    }
    std::vector<std::string> rec = MSBRadixSortHybrid(buckets[c], l + 1);
    res.insert(res.end(), rec.begin(), rec.end());
  }
  return res;
}
