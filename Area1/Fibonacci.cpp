/* Compute fibonacci over natural numbers indexed by whole numbers */

#include <iostream>
#include <vector>
#include <numeric>

// Sol1 - recursive
std::size_t fibonacci(std::size_t num)
{
   // Advanced: bitwise vs logical operations
   if ((num == 0) | (num == 1))
      return 1;

   return fibonacci(num - 1) + fibonacci(num - 2);
}

// Sol2 - iterative
// Basic: Pros/Cons of recusion vs iteration
std::size_t fibonacci2(std::size_t num)
{
   if ((num == 0) | (num == 1))
      return 1;

   auto temp = 0u;
   auto first = 1u;
   auto second = 1u;
   // Bonus: getting the indexes right in the very first try
   for (auto i = 1u; i < num; ++i)
   {
      auto temp = first;
      first = second;
      second = first + temp;
   }
   return second;
}

// compile time 1 - c++03
template <std::size_t N>
struct fibonacci3
{
   static const std::size_t value = fibonacci3<N - 1>::value + fibonacci3<N - 2>::value;
};

template <>
struct fibonacci3<0>
{
   static const std::size_t value = 1;
};

template <>
struct fibonacci3<1>
{
   static const std::size_t value = 1;
};

// compile time 2 - c++11
constexpr std::size_t fibonacci4(const std::size_t num)
{
   // Advanced: c++14 constexpr rules
   return (num == 0) ? 1 : (num == 1) ? 1 : fibonacci4(num - 1) + fibonacci4(num - 2);
}

// using stl
// Advanced: tell them algorithm and interface, and implement the function
std::size_t fibonacci5(std::size_t num)
{
   std::vector<std::size_t> v (num + 1, 1);
   std::adjacent_difference(v.begin(), v.end() - 1, v.begin() + 1, std::plus<std::size_t>{});
   return v.back();
}

int main()
{
   const auto num = 10u;
   std::cout << fibonacci(num) << '\n';
   std::cout << fibonacci2(num) << '\n';
   std::cout << fibonacci5(num) << '\n';

   // Basic: static assert vs std::cout
   static_assert(fibonacci3<num>::value == 89, "");
   static_assert(fibonacci4(num) == 89, "");
}
