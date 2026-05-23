#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "string_generator.h"
#include "string_sort_tester.h"

int main() {
  StringGenerator gen(42);
  StringSortTester tester;

  std::vector<std::string> algo_names = {"StdQuickSort", "StdMergeSort", "TernaryQuickSort", "StringMergeSort", "MSBRadixSort", "MSBRadixHybrid"};
  std::vector<std::string> type_names = {"random", "reverse", "almost"};

  std::ofstream out("results.csv");
  out << "algorithm,type,size,time_us,comparisons\n";

  for (int size = 100; size <= 3000; size += 100) {
    for (int type = 0; type < 3; ++type) {
      std::vector<std::string> input = gen.Generate(size, type);
      for (int sort_id = 0; sort_id < 6; ++sort_id) {
        auto r = tester.Measure(input, sort_id, 9);
        out << algo_names[sort_id] << ',' << type_names[type] << ',' << size << ',' << r.avg_time_us << ',' << r.avg_cmp << '\n';
      }
    }
    std::cout << "размер = " << size << '\n';
  }

  out.close();
}
