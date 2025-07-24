#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {100, 80, 60, 81, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pgI[n];
    stack<int>st;
    pgI[0] = 1;

    st.push(0);
    for(int i=1; i<n; i++) {
        //pop
        while(st.size() > 0 && arr[st.top()] <= arr[i]) st.pop();
        //ans
        if(st.size() == 0) pgI[i] = -1;
        else pgI[i] = st.top();
        pgI[i] = i - pgI[i];
        //push
        st.push(i);
    }


     //printing
    for(int i=0; i<n; i++) {
        cout << pgI[i] << " ";
    }
    cout << endl;
}