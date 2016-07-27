#include "./simple_test.hpp"

#include <tuple>

template <auto A>
struct s
{
};

auto testa()
{
  s<1> a;
}

int main()
{

  testa();

  return ::test_result();
}
