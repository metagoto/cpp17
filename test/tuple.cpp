#include "./simple_test.hpp"

#include <tuple>
#include <type_traits>

using namespace std;

auto test() {

  auto a = make_tuple(1, 2.0);

}

int main() {

  test();

  return ::test_result();
}
