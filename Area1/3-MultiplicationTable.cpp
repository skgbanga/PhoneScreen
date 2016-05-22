/* print grade school multiplication table */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>

// sol1 - Medium: think about optimizations.
void multi_table(std::size_t num)
{
   // Bonus - thinking about formatting output
   auto max = num * num;
   auto digits = 1u;
   while (max /= 10)
      ++digits;

   std::ostringstream os {};
   for (auto i = 1u; i <= num; ++i)
   {
      for (auto j = 1u; j <= num; ++j)
      {
         // Bonus - do not inlude extra space at the end
         char sentinel = (j == num) ? '\n' : ' ';
         os << std::setw(digits) << i * j << sentinel;

         // Bonus2: Do not do sentinel check on each iternation
         //os << std::setw(digits) << i * j << ' ';
      }
      // Bonus 2: contd
      //os.seekp(-1, std::ios_base::end);
      //os << '\n';
   }
   std::cout << os.str();
}

// Medium: sol2 - no nested raw loops (just a fun exercise)
void multi_table2(std::size_t num)
{
   std::vector<std::size_t> v;
   // Basic: Why do a reserver beforehand
   v.reserve(num);
   for (int i = 1u; i <= num; ++i)
   {
      auto index = 1u;
      std::generate_n(std::back_inserter(v), num, [&i, &index]() { return i * index++; });
      std::copy(v.cbegin(), v.cend(), std::ostream_iterator<std::size_t>(std::cout, " "));
      std::cout << '\n';
      v.clear();
   }
}

int main()
{
   const auto N = 12u;
   multi_table(N);

   multi_table2(N);
}
