#include "./simple_test.hpp"

#include <tuple>
#include <type_traits>

auto testa()
{
  if constexpr(1 == 1) { CHECK(true); }
  else {
    CHECK(false);
  }
}

auto testb()
{
  if constexpr(1 == 2) { CHECK(false); }
  else {
    CHECK(true);
  }
}

struct a
{
  using type = int;
};

template <typename T>
auto test_sfinae()
{
  if constexpr(std::is_same_v<int, typename T::type>) { CHECK(true); }
  else {
    CHECK(false);
  }
}

int main()
{

  testa();
  testb();
  test_sfinae<a>();
  // test_sfinae<int>();

  return ::test_result();
}
