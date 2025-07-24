// #include <iostream>
// #include <string>

// int stringToInt(const std::string& str) {
//     int result = 0;
//     bool isNegative = false;

//     // Handling sign
//     size_t i = 0;
//     if (str[0] == '-') {
//         isNegative = true;
//         i = 1;
//     }

//     // Converting digits to integer
//     while (i < str.length()) {
//         if (str[i] >= '0' && str[i] <= '9') {
//             result = result * 10 + (str[i] - '0');
//         } else {
//             // If non-digit character encountered, break the loop
//             break;
//         }
//         i++;
//     }

//     // Adjusting sign if necessary
//     if (isNegative) {
//         result = -result;
//     }

//     return result;
// }

// int main() {
//     std::string str;
//     std::cin>>str;
//     int number = stringToInt(str);
//     std::cout << "The integer value is: " << number << std::endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

void remove(string str, string ans) {
    if(str.length() == 0) {
        cout << ans << endl;
        return;
    }
    char ch = str[0];
    if(ch == 'a') remove(str.substr(1), ans );
    else remove(str.substr(1), ans + ch);
}
int main () {
    string str = "asdfdsaaqa";
     remove(str, "");
}