/* print odd numbers between 1 and 100*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Sol 1
void print_odd(std::size_t start, std::size_t end)
{
   for (std::size_t i = start; i <= end; ++i)
   {
      // Basic: Operator precedence
      if (i % 2 != 0)
         std::cout << i << " ";
   }
   std::cout << '\n';
}

// Sol2 - using stl (again fun exercise)
// assume start to be 1
void print_odd2(std::size_t start, std::size_t end)
{
   std::vector<std::size_t> v{};
   // No assumption about distribution of odd numbers
   std::generate_n(std::back_inserter(v), end, [&start]() { return start++; });
   v.erase(std::remove_if(v.begin(), v.end(), [](std::size_t n) { return n % 2 == 0; }), v.end());
   std::copy(v.begin(), v.end(), std::ostream_iterator<std::size_t>(std::cout, " "));
}

int main()
{
   print_odd(1, 100);
   print_odd2(1, 100);
}
