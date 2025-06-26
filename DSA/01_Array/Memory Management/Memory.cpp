#include <iostream>
#include <cstdint> // for uintptr_t

int main()
{
  int x = 69;
  int *ptr = &x;

  // Convert pointer to integer
  uintptr_t address = reinterpret_cast<uintptr_t>(ptr);

  std::cout << "Memory address in decimal: " << address << std::endl;

  // Convert integer to pointer
  int *ptr2 = reinterpret_cast<int *>(address);
  std::cout << "Value of ptr2: " << *ptr2 << std::endl;

  // address ot pointer
  std::cout << "Address of ptr => " << ptr << std::endl;
  std::cout << "Address of a => " << &x << std::endl;
  
  printf("Hello World\n"); 

  return 0;
}
