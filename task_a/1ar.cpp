#include "common.h"
#include "1ar.h"

std::vector<std::string> CountingSort(std::vector<std::string> str_arr, int i) {
  if (str_arr.empty()) {
    return str_arr;
  }
  
  std::vector<int> count(128, 0);
  std::vector<std::string> output(str_arr.size());
    
  for (const std::string& s : str_arr) {
    if (s.size() == i) {
      ++count[0];
    } else {
      ++count[s[i] + 1];
    }
  }
    
  int sum = 0;
  for (int j = 0; j < 128; j++) {
    int temp = count[j];
    count[j] = sum;
    sum += temp;
  }
    
  for (const std::string& s : str_arr) {
    int idx = 0;
    if (s.size() == i) {
      idx = 0;
    } else {
      idx = s[i] + 1;
    }
    int pos = count[idx];
    output[pos] = s;
    ++count[idx];
  }
    
  return output;
}

std::vector<std::string> MSBRadixSort(const std::vector<std::string>& str_arr, int l) {
  if (str_arr.size() <= 1) {
    return str_arr;
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
    std::vector<std::string> rec = MSBRadixSort(buckets[c], l + 1);
    res.insert(res.end(), rec.begin(), rec.end());
  }
  return res;
}
