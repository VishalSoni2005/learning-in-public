#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    double r1 = (p1.first * 1.0) / (p2.second * 1.0);
    double r2 = (p2.first * 1.0) / (p2.second * 1.0);
    return r1 > r2;
}
double AmountStoredInSack(vector<int>& profit, vector<int>&value, int num, int capacity) {
    vector<pair<int, int>>arr;
    for(int i=0; i<num; i++) arr.push_back({profit[i], value[i]});

    sort(arr.begin(), arr.end(), cmp);
    // we need to sort in decending order so this sort will not work 

    double res = 0;
    for(int i=0; i<num; i++) {
        if(arr[i].second <= capacity) {
            res += arr[i].first;
            capacity -= arr[i].second;
        }
        else {
            res += ((arr[i].first * 1.0)/ arr[i].second * 1.0) * capacity;
            capacity = 0;
            break;
        }
    }
    return res;
}
int main() {
    vector<int>profit = {70, 80, 90, 50, 40};
    vector<int>value = {10, 20, 30, 40, 50};
    int n = 5;
    int weight = 100;
    cout << AmountStoredInSack(profit, value, n, weight);


}