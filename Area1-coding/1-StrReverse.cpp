/* Reverse a string */

// Advanced: Cost of including iostream vs other headers
// Medium: iostreams vs printf
#include <iostream>
#include <cstring>
#include <algorithm>
// Bonus: on gettng all the headers correct without compilation

// solution 2
// std::string
// Basic: Pass by reference and pass by value
// Advanced: Short String optimzation
std::string strrev2(std::string str)
{
   // Medium: Types of iterators
   std::reverse(str.begin(), str.end());

   // Basic: what happens on empty string
   return str;
}

// solution 1: loop through the string from both sides, and finish in the middle
// Basic: Precondition: str null terminated
char* strrev1(char* head)
{
   // Basic: boundary case
   if (!head)
      return nullptr;

   // Advanced: Implement strlen in a polymophic lambda
   std::size_t count = std::strlen(head);

   auto* strhead = head;
   auto* end = head + count - 1;

   while (head != end)
   {
      std::iter_swap(head, end);

      // Basic: pre-increment and post increment
      ++head;
      --end;
   }

   return strhead;

   // Basic: Use stl with naked pointers
   //auto* end = head + count;
   //std::reverse(head, end);
   //return head;
}

// Basic: return type int, but not returning anything
int main()
{
   // Sol 1 - c style string
   const char* str = "Madam, I'm Adam";
   char buffer[32];
   std::strncpy(buffer, str, sizeof(buffer));

   char* new_str = strrev1(buffer);
   // Medium: std::cout vs "\n" vs '\n'
   std::cout << new_str << '\n';

   // Sol2
   std::string str2 = "Madam, I'm Adam";
   // Medium: Lifetime extension of primary
   const auto& new_str2 = strrev2(str2);
   std::cout << new_str2 << '\n';
}
