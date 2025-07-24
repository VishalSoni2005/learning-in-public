#include<bits/stdc++.h>
using namespace std;
void display(vector<int> nums) {
    if(nums.size() == 0) return;
    cout << nums[nums.size() - 1] << " ";
    nums.pop_back();
    display(nums);
}
int main() {
    vector<int>arr;
    for(int i=1; i<=5; i++) arr.push_back(i);
    display(arr);
}