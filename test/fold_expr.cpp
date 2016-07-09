#include "./simple_test.hpp"

auto testa() {

    CHECK(true);

}

int main() {

  testa();

  return ::test_result();
}
