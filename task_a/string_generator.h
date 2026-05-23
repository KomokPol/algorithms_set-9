#ifndef STRING_GENERATOR_H
#define STRING_GENERATOR_H

#include <random>
#include <string>
#include <vector>

class StringGenerator {
  public:
  explicit StringGenerator(unsigned seed = std::random_device{}());

  std::vector<std::string> Generate(int size, int type);

  private:
  std::mt19937 rng_;
  std::vector<std::string> base_;
  std::string alphabet_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#%:;^&*()-";
};

#endif
