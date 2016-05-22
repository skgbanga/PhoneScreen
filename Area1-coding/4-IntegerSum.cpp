/* Sum integers from a file, one int per line */

#include <fstream>
#include <string>
#include <iostream>

int main()
{
   // Basic: Take this file from argc, argv
   std::ifstream file ("MyCode/input.txt");
   auto sum = 0u;

   // Basic: Sanity checks
   if (!file.is_open())
   {
      std::cerr << "Unable to open the file. Exiting...";
      return -1;
   }

   // Sol1
   // Basic: knowledge of stream state variables
   for (std::string line; std::getline(file, line);)
   {
      // Basic: assumption about the size of integers
      // Basic2: does this take of negative numbers?
      // Basic3: What if there are non integral number.
      auto num = std::stoi(line);
      // Basic: check for overflow
      if (num + sum < sum)
      {
         std::cerr << "Overflow detected. Try to sum in a larger type";
         return -1;
      }
      sum += num;
   }
   std::cout << "Sum is " << sum << '\n';

   // Sol2: Directly read as formatted input
   // Medium: What is the difference between formatted and unformatted input
   std::ifstream file2 ("MyCode/input.txt");
   auto N = 0;
   auto sum2 = 0;
   while (file2 >> N)
   {
      sum2 += N;
   }
   std::cout << "Sum is " << sum2 << '\n';

   // Basic: Do we need to close the file?
}
