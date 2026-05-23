#include "string_sort_tester.h"

#include <chrono>
#include <algorithm>

#include "common.h"
#include "std_quick_sort.h"
#include "std_merge_sort.h"
#include "1aq.h"
#include "1am.h"
#include "1ar.h"
#include "1arq.h"

StringSortTester::Result StringSortTester::Measure(std::vector<std::string> input, int sort_id, int runs) {
  std::vector<double> times;
  std::vector<double> cmps;

  for (int r = 0; r < runs; ++r) {
    std::vector<std::string> data = input;
    cmp_count = 0;

    auto t0 = std::chrono::high_resolution_clock::now();
    RunSort(data, sort_id);
    auto t1 = std::chrono::high_resolution_clock::now();

    double dt = std::chrono::duration<double, std::micro>(t1 - t0).count();
    times.push_back(dt);
    cmps.push_back(static_cast<double>(cmp_count));
  }

  std::sort(times.begin(), times.end());
  std::sort(cmps.begin(), cmps.end());

  Result res;
  res.avg_time_us = times[runs / 2];
  res.avg_cmp = cmps[runs / 2];
  return res;
}

void StringSortTester::RunSort(std::vector<std::string>& data, int sort_id) {
  if (sort_id == 0) {
    data = StdQuickSort(data);
  } else if (sort_id == 1) {
    data = StdMergeSort(data);
  } else if (sort_id == 2) {
    data = TernaryQuickSort(data, 0);
  } else if (sort_id == 3) {
    auto pairs = StringMergeSort(data);
    data.clear();
    for (auto& p : pairs) {
      data.push_back(p.first);
    }
  } else if (sort_id == 4) {
    data = MSBRadixSort(data, 0);
  } else if (sort_id == 5) {
    data = MSBRadixSortHybrid(data, 0);
  }
}
