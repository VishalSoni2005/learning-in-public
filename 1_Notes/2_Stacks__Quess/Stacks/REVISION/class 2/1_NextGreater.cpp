#include <iostream>
#include <stack>
using namespace std;
int main() {
    int arr[] = {3,1,2,5,4,6,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int nge[n];
    nge[n-1] = -1;
    stack<int>st;
    st.push(arr[n-1]);
    
    for(int i=n-2; i >= 0; i--) {
        //pop
        while(st.size() > 0 && st.top()<= arr[i]) st.pop();
        //ans
        if(st.size() == 0) nge[i] = -1;
        else nge[i] = st.top();
        //push
        st.push(arr[i]);
    }

    //printing
    for(int i=0; i<n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

}