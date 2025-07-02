#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

  int x = 10;
  int y = x;

  int *x_ptr = &x;
  int *y_ptr = &y;

  printf("x: %d, y: %d\n", x, y);
  printf("x_ptr: %p, y_ptr: %p\n", x_ptr, y_ptr);

  printf("x_ptr points to value: %d\n", *x_ptr);
  printf("y_ptr points to value: %d\n", *y_ptr);

  int *z_ptr = x_ptr;
  printf("z_ptr points to value: %p\n", z_ptr);
    
}