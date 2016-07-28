#include "./simple_test.hpp"

#include <tuple>
#include <type_traits>

using namespace std;

template <typename T>
using index_for_tuple = make_index_sequence<tuple_size_v<decay_t<T>>>;

template <typename... T>
ostream& operator<<(ostream& o, tuple<T...> const& t);

template <typename T, size_t... I>
auto print_impl(T&& t, index_sequence<I...>)
{
  ((cout << get<I>(t) << " "), ...);
  cout << "\n";
}

template <typename T>
auto print(T&& t)
{
  print_impl(std::forward<T>(t), index_for_tuple<T>{});
}

template <typename... T>
ostream& operator<<(ostream& o, tuple<T...> const& t)
{
  print(t);
  return o;
}

auto test()
{
  auto a = make_tuple(1, 'a', 2.1);
  print(a);
}

/////////////

template <typename A, typename B, size_t... I, size_t... J>
auto zip_impl(A&& a, B&& b, index_sequence<I...>, index_sequence<J...>)
{
  static_assert(sizeof...(I) == sizeof...(J));
  return make_tuple(make_tuple(get<I>(a), get<I>(b))...);
}

template <typename A, typename B>
auto zip(A&& a, B&& b)
{
  return zip_impl(a, b, index_for_tuple<A>{}, index_for_tuple<B>{});
}

auto test_zip()
{
  auto a = make_tuple(1, 2, 3);
  auto b = make_tuple('a', 'b', 'c');
  auto c = zip(a, b);

  print(c);
  auto d = make_tuple(make_tuple(1, 'a'), make_tuple(2, 'b'), make_tuple(3, 'c'));
  CHECK(c == d);
}

/////////////

template <typename T, typename F, size_t... I>
auto tuple_foreach_impl(T&& t, F&& f, index_sequence<I...>)
{
  (f(get<I>(t)), ...);
}

template <typename T, typename F>
auto tuple_foreach(T&& t, F&& f)
{
  tuple_foreach_impl(std::forward<T>(t), std::forward<F>(f), index_for_tuple<T>{});
}

auto test_foreach()
{
  auto a = make_tuple(1, 'a', 2.1, "test");
  tuple_foreach(a, [](auto a) { cout << a << ", "; });
  cout << "\n";
}

/////////////

auto test_apply()
{
  auto a = make_tuple(1, 'a', 2.1, "test");
  apply([](int i, char c, double d, char const* s) { cout << i << c << d << s << "\n"; }, a);
  apply([](auto... a) { (cout << ... << a); }, a);
  cout << "\n";
}

/////////////

int main()
{

  test();
  test_zip();
  test_foreach();
  test_apply();

  return ::test_result();
}
