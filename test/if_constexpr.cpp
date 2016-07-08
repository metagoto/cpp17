#include "./simple_test.hpp"

#include <tuple>


auto testa() {
  if constexpr(1 == 1) {
    CHECK(true);
  }
  else {
    CHECK(false);
  }
}

auto testb() {
  if constexpr(1 == 2) {
    CHECK(false);
  }
  else {
    CHECK(true);
  }
}

int main() {

  testa();
  testb();

  return ::test_result();
}
