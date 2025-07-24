#include<iostream>
#include<bitset>
using namespace std;
// int main(){
//     bitset<8> me{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
//     me.set(3);   // set bit position 3 to 1 (now we have 0000 1101)
//     me.flip(4);  // flip bit 4 (now we have 0001 1101)
//     me.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

//     cout << "All the bits: " << me << '\n';
//     cout << "Bit 3 has value: " << me.test(3) << '\n';
//     cout << "Bit 4 has value: " << me.test(4) << '\n';
// }
int main(){
    int n;
    cout<<"fill  : ";
    cin>>n;
    cout<<"Number Entered : "<<n<<endl;
    cout<<"hexa form : "<<std::hex<<n<<endl;


}