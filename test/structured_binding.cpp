#include "./simple_test.hpp"

#include <tuple>

auto f()
{
  return std::make_tuple(1, 1.f);
}

auto testa()
{
  auto x = f();
  auto [a, b] = f();

  CHECK(a == 1);
}

int main()
{

  testa();

  return ::test_result();
}
