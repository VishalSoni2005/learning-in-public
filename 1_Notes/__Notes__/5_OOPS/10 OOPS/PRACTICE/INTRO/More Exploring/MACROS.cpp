// MACROS ARE PERPROCESS DIRECTIVE
#include<iostream>
using namespace std;

#define PI 3.141

float AreaCircle(int radius) {
    return PI * radius * radius;
}
int main() {
    cout << AreaCircle(5);
}