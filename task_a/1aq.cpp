#include "1aq.h"
#include "common.h"

std::vector<std::string> TernaryQuickSort(std::vector<std::string> str_arr, int l) {
  if (str_arr.size() <= 1) {
    return str_arr;
  }

  std::vector<std::string> arr_excl;
  std::vector<std::string> arr_active;
  for (std::string str : str_arr) {
    if (str.size() == l) {
      arr_excl.push_back(str);
    } else {
      arr_active.push_back(str);
    }
  }

  if (arr_active.empty()) {
    return arr_excl;
  }

  std::string pivot = arr_active[arr_active.size() / 2];

  std::vector<std::string> arr_less;
  std::vector<std::string> arr_equal;
  std::vector<std::string> arr_great;
  for (std::string str : arr_active) {
    ++cmp_count;
    if (str[l] < pivot[l]) {
      arr_less.push_back(str);
    } else if (str[l] > pivot[l]) {
      arr_great.push_back(str);
    } else {
      arr_equal.push_back(str);
    }
  }

  arr_less = TernaryQuickSort(arr_less, l);
  arr_equal = TernaryQuickSort(arr_equal, l + 1);
  arr_great = TernaryQuickSort(arr_great, l);

  std::vector<std::string> res;
  res.insert(res.end(), arr_excl.begin(), arr_excl.end());
  res.insert(res.end(), arr_less.begin(), arr_less.end());
  res.insert(res.end(), arr_equal.begin(), arr_equal.end());
  res.insert(res.end(), arr_great.begin(), arr_great.end());
  return res;
}
