// size_t Type
// size_t is an unsigned integer type used to represent
// sizes(e.g., array indices, memory allocation sizes)
// It is defined in<stddef.h>,
// <stdio.h>, <stdlib.h>, etc.
// It is platform- dependent(usually unsigned int on 32 - bit systems, unsigned long long on 64 - bit systems).
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  size_t size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of

  for (size_t i = 0; i < size; i++)
  {
    printf("Element %zu: %d\n", i, arr[i]);
  }
  printf("Total number of elements: %zu\n", size);

  size_t num = -1;
  printf("Size of size_t: %zu\n", sizeof(size_t));
}