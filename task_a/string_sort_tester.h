#ifndef STRING_SORT_TESTER_H
#define STRING_SORT_TESTER_H

#include <string>
#include <vector>

class StringSortTester {
  public:
  struct Result {
    double avg_time_us;
    double avg_cmp;
  };

  Result Measure(std::vector<std::string> input, int sort_id, int runs = 5);

  private:
  void RunSort(std::vector<std::string>& data, int sort_id);
};

#endif
