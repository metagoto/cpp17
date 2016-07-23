#include "./simple_test.hpp"

constexpr int next(int i) {
  return [i] { return i + 1; }();
}

int main() {

  static_assert(next(0) == 1);
  CHECK(true);
  return ::test_result();
}
