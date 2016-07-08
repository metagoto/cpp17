#include "./simple_test.hpp"



auto testa() {
  if (int i = 1; i) {
    CHECK(true);
  }
}

int main() {

  testa();

  return ::test_result();
}
