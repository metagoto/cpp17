#include "./simple_test.hpp"

template <typename... A>
auto sum(A&&... a)
{
  return (a + ...);
}

template <typename... A>
auto sum2(A&&... a)
{
  return (a + ... + 0);
}

auto testa()
{
  CHECK(sum(1, 2, 3) == 6);
  // CHECK(sum() == 0);
  CHECK(sum2() == 0);
}

int main()
{
  testa();

  return ::test_result();
}
