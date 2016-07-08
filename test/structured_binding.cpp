#include "./simple_test.hpp"

#include <tuple>

auto testa() {

  auto [a, b] = std::make_tuple(1, 1.f);

}


int main() {

  testa();

  return ::test_result();
}
