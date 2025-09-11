#include <stdio.h>
// #include <stdlib.h>
char* sayHello(int n, int j) {
    return (char*)(n + j);
}
int void_int(void) {
    return 69;
}

int main() {
    // printf("Hello, World!\n");
    printf("C does not have strings like C++.\n");
    // printf("C uses character arrays for strings.\n");
    printf("\n");

    const char ch = 'A';
    // ch = 'B'; // This line will cause a compilation error because 'ch' is a const variable.
    const char str[] = "Hello, C!";
    const char *str2 = "Vishal Soni";
    printf("Character: %c\n", ch);
    printf("String: %s\n", str);
    printf("String pointer: %s\n", str2);

    // for(int i = 0; str2[i] != '\0'; i++) {
    //     printf("Character at index %d: %c\n", i, str2[i]);
        
    // }
    printf("\n");
    printf("Using function : %d\n", sayHello(5, 10));
    printf("Using void function : %d\n", void_int());

    printf("\n");
    printf("Size of char* : %d\n", sizeof(char*));
    printf("Size of char[] : %d\n", sizeof(str));
    printf("Size of const char* : %d\n", sizeof(str2));
    printf("Size of const char : %d\n", sizeof(ch));

    printf("\n");
    signed int a = -258;   // a % 256 = 2, so it will store 2 in the variable.
    unsigned char b = 258; // b % 256 = 2, so it will store 2 in the variable.
    printf("sizeof(signed char) : %d\n", sizeof(a));
    printf("sizeof(unsigned char) : %d\n", sizeof(b));
    printf("signed char value: %d\n", a);
    printf("unsigned char value: %d\n", b);

    return 0;
}