#include "std_quick_sort.h"
#include "common.h"

std::vector<std::string> StdQuickSort(std::vector<std::string> arr) {
  if (arr.size() <= 1) {
    return arr;
  }

  std::string pivot = arr[arr.size() / 2];

  std::vector<std::string> arr_less;
  std::vector<std::string> arr_equal;
  std::vector<std::string> arr_great;
  for (std::string str : arr) {
    int c = CompareStrings(str, pivot);
    if (c < 0) {
      arr_less.push_back(str);
    } else if (c > 0) {
      arr_great.push_back(str);
    } else {
      arr_equal.push_back(str);
    }
  }

  arr_less = StdQuickSort(arr_less);
  arr_great = StdQuickSort(arr_great);

  std::vector<std::string> res;
  res.insert(res.end(), arr_less.begin(), arr_less.end());
  res.insert(res.end(), arr_equal.begin(), arr_equal.end());
  res.insert(res.end(), arr_great.begin(), arr_great.end());
  return res;
}
