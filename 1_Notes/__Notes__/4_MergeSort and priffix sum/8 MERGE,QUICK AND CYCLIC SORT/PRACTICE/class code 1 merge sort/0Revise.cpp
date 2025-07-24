#include<iostream>
#include<vector>
using namespace std;
void mergeArray(vector<int>& v1, vector<int>&v2, vector<int>& v){ // v is vector that should hold value of sorted arr
    int n = v1.size();
    int m = v2.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m) {
        if(v1[i] <= v2[j]) v[k++] = v1[i++];
        else v[k++] = v2[j++];
    }
    if(i == n) while(j < m) v[k++] = v2[j++];
    if(j == m) while(i < n) v[k++] = v1[i++];
    return;
}
void divideAndconcer(vector<int>& v) {
    int n = v.size();
    if(n == 1) return;
    int n1 = n/2;
    int n2 = n - n1;
    vector<int>v1(n1);
    vector<int>v2(n2);
    for(int i=0; i<n1; i++) v1[i] = v[i];
    for(int i=0; i<n2; i++) v2[i] = v[i + n1];
    divideAndconcer(v1);
    divideAndconcer(v2);

    mergeArray(v1, v2, v);
    v1.clear();
    v2.clear();
    

}
int main() {
    vector<int> nums = {-6, 8, 4, -8, 0, 13, 64};
    divideAndconcer(nums);
    for(int i=0; i<nums.size(); i++) cout << nums[i] << " ";
}