/* Format an RGB value (represented at 3 uint8_ts) as 6-digit hex */

#include <iostream>
#include <iomanip>

// sol1
// Basic: Understand base system
void printChar(uint8_t num)
{
   uint8_t quot = num/16;
   uint8_t rem  = num%16;
   printf("%x%x", quot, rem);
}

void printHex(uint8_t red, uint8_t green, uint8_t blue)
{
   printChar(red);
   printChar(green);
   printChar(blue);
   printf("\n");
}

// sol2 - use streams
// Basic: Performance penalty of streams
void printHex2(uint8_t red, uint8_t green, uint8_t blue)
{
   auto fmt = [](uint8_t color)
   {
      std::cout << std::setfill('0') << std::setw(2) << std::hex << +color;
   };
   fmt(red);
   fmt(green);
   fmt(blue);
   std::cout << '\n';
}

int main()
{
   const uint8_t red = 173;
   const uint8_t green = 34;
   const uint8_t blue = 6;

   printHex(red, green, blue);
   printHex2(red, green, blue);
}
