/* largest int value in an int array */

#include <limits>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <utility>

// Sol1: Taking array by reference
template <std::size_t N>
int max_array(const int (&a)[N])
{
   // Basic: good init value of running max
   int running_max = std::numeric_limits<int>::min();
   for (auto i = 0u; i < N; ++i)
      running_max = (a[i] > running_max) ? a[i] : running_max;

   return running_max;
}

// Sol2: Taking array by const pointer and size
// Basic: Decomposition of arrays into pointers
int max_array2(const int* a, std::size_t n)
{
   int running_max = std::numeric_limits<int>::min();
   for (auto i = 0u; i < n; ++i)
      running_max = (a[i] > running_max) ? a[i] : running_max;

   return running_max;
}

// Sol3: stl
template <std::size_t N>
int max_array3(const int (&a)[N])
{
   // Basic: bounds check
   return *std::max_element(std::begin(a), std::end(a));
}

// Very advanced
// This requires c++14
template <typename Array, std::size_t... Is>
constexpr int max_array4_impl(const Array& arr, std::index_sequence<Is...>)
{
   int max = std::numeric_limits<int>::min();
   std::initializer_list<int>{(max = (max > arr[Is]) ? max : arr[Is], 0)...};
   return max;
}

template <std::size_t N, typename IndexSeq = std::make_index_sequence<N>>
constexpr int max_array4(const std::array<int, N>& arr)
{
   return max_array4_impl(arr, IndexSeq{});
}

int main()
{
   const std::size_t sz = 10;
   int arr[sz] {};
   // Advanced: c++11 random numbers
   std::generate(std::begin(arr), std::end(arr), std::rand);

   std::cout << max_array(arr) << '\n';
   std::cout << max_array2(arr, sz) << '\n';
   std::cout << max_array3(arr) << '\n';

   constexpr std::array<int, sz> carr {45, 134, 23, 12, 99, 35, 23, 66, 78, 1};
   static_assert(max_array4(carr) == 134, "");
}
