#include <stdio.h>
#include "my_math.h"

int main( void ) {
  printf("ADD : %d\n", add(5, 10));
  printf("SUB : %d\n", sub(10, 5));
  printf("MUL : %d\n", mul(5, 10));
  printf("DIV : %d\n", div(10, 5));

  printf("WELL DONE!\n");
}