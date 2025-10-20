/** Use this main to test exercises. See the example with 'as1.0' below. 
 *  You can add all the exercise tests inside the same main.
 *  Don't forget to add includes properly.
 * */

 #include "as1.hpp"
#include <iostream>

using namespace homework;

int main() { 
  int a = 1;
  int b = 2;
  int c = 3;

  int* ptr_a = &a;
  int* ptr_b = &b;
  int* ptr_c = &c;

std::cout << "Pointer a : " << *ptr_a << std::endl;
std::cout << "Pointer b : " << *ptr_b << std::endl;
std::cout << "Pointer c : " << *ptr_c << std::endl;

swap_ptr(ptr_a, ptr_b, ptr_c);

std::cout << "Swapping pointer values." << std::endl;

std::cout << "Pointer a : " << *ptr_a << std::endl;
std::cout << "Pointer b : " << *ptr_b << std::endl;
std::cout << "Pointer c : " << *ptr_c << std::endl;

std::cout << "as1.2" << std::endl;

UniqueData myData(2);

std::cout << myData.get() << std::endl;

myData.set(5);

std::cout << "Setting data to 5" << std::endl;

std::cout << myData.get() << std::endl;

return 0;
}

