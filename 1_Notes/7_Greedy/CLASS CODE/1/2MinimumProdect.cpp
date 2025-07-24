#include<bits/stdc++.h>
using namespace std;
int minProduct(vector<int> &arr, int n){
    int cp = 0;// count positive number
    int cz = 0;// count zero digits
    int cn = 0;// count negative number
    int pord_pos = 1;
    int pord_neg = 1;
    int largestNegative = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            cp++;
            pord_pos *= arr[i];
        }
        else if(arr[i] < 0){
            cn++;
            pord_neg *= arr[i];
            largestNegative = max(largestNegative, arr[i]);
        }
        else{
            cz++;
        }
    }
    // form above loop we find the number of positive and negative numbers and zero digits
    // and also the largest negative number
    // prod_pos is the product of all positive numbers
    // prod_neg is the product of all negative numbers

    if(cn == 0){
        if(cz > 0) return 0;
        else {
            auto it = min_element(arr.begin(), arr.end());
            return *it;
        }
    }
    else {
        if(n % 2 == 0) return (pord_neg / largestNegative) * (pord_pos);
        else return pord_neg * pord_pos;
    }

}
int main(){
    
    vector<int> arr {1,2,3,4,-1,-1};
    int n = arr.size();
    cout << minProduct(arr, n);
}