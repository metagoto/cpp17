#include "./simple_test.hpp"

namespace a {
}

namespace a::b {
auto test()
{
  CHECK(true);
}
}

namespace c::d {
auto test()
{
  CHECK(true);
}
}

int main()
{

  a::b::test();
  c::d::test();

  return ::test_result();
}
