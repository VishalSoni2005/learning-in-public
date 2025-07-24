#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {3, 1, 2, 5, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int pge[n];
    stack<int>st;
    pge[0] = -1;
    st.push(arr[0]);
    for(int i=1; i<n; i++) {
        //p0p
        while(st.size() > 0 && st.top()<= arr[i]) st.pop();
        //ans
        if(st.size() == 0) pge[i] = -1;
        else pge[i] = st.top();
        //push
        st.push(arr[i]);
    }


     //printing
    for(int i=0; i<n; i++) {
        cout << pge[i] << " ";
    }
    cout << endl;
}