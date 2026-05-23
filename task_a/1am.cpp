#include "1am.h"
#include "common.h"

std::pair<int, int> LcpCompare(std::string a, std::string b, int k) {
  int lcp = k;
  while (lcp < a.size() && lcp < b.size() && a[lcp] == b[lcp]) {
    ++lcp;
    ++cmp_count;
  }

  while (lcp != a.size() && lcp != b.size()) {
    ++cmp_count;
    if (a[lcp] > b[lcp]) {
      return {1, lcp};
    }
    if (a[lcp] < b[lcp]) {
      return {-1, lcp};
    }
    ++lcp;
  }

  if (a.size() < b.size()) {
    return {-1, lcp};
  }
  if (a.size() > b.size()) {
    return {1, lcp};
  }

  return {0, lcp};
}

std::vector<std::pair<std::string, int>> StringMerge(std::vector<std::pair<std::string, int>> p, std::vector<std::pair<std::string, int>> q) {
  std::vector<std::pair<std::string, int>> res;

  size_t i = 0;
  size_t j = 0;
  size_t m = p.size();
  size_t f = q.size();

  while (i < m && j < f) {
    if (p[i].second > q[j].second) {
      res.push_back({p[i].first, p[i].second});
      ++i;
    } else if (p[i].second < q[j].second) {
      res.push_back({q[j].first, q[j].second});
      ++j;
    } else {
      std::pair<int, int> x_and_h = LcpCompare(p[i].first, q[j].first, p[i].second);
      if (x_and_h.first == -1) {
        res.push_back({p[i].first, p[i].second});
        ++i;
        q[j].second = x_and_h.second;
      } else {
        res.push_back({q[j].first, q[j].second});
        ++j;
        p[i].second = x_and_h.second;
      }
    }
  }

  while (i < m) {
    res.push_back({p[i].first, p[i].second});
    ++i;
  }
  while (j < f) {
    res.push_back({q[j].first, q[j].second});
    ++j;
  }

  return res;
}

std::vector<std::pair<std::string, int>> StringMergeSort(std::vector<std::string> str_arr) {
  if (str_arr.size() == 1) {
    std::vector<std::pair<std::string, int>> res;
    res.push_back({str_arr[0], 0});
    return res;
  }
  size_t m = str_arr.size() / 2;
  auto p = StringMergeSort(std::vector<std::string>(str_arr.begin(), str_arr.begin() + m));
  auto q = StringMergeSort(std::vector<std::string>(str_arr.begin() + m, str_arr.end()));

  return StringMerge(p, q);
}
