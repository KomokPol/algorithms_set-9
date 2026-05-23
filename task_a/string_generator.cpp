#include "string_generator.h"

#include <algorithm>

StringGenerator::StringGenerator(unsigned seed) : rng_(seed) {
  for (int i = 0; i < 3000; ++i) {
    size_t len = rng_() % 191 + 10;
    std::string s(len, ' ');
    for (char& c : s) {
      c = alphabet_[rng_() % 74];
    }
    base_.push_back(std::move(s));
  }
}

std::vector<std::string> StringGenerator::Generate(int size, int type) {
  std::vector<std::string> arr(base_.begin(), base_.begin() + size);

  if (type == 1) {
    std::sort(arr.begin(), arr.end(), std::greater<std::string>());
  } else if (type == 2) {
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < 10; ++i) {
      std::swap(arr[rng_() % size], arr[rng_() % size]);
    }
  }

  return arr;
}
