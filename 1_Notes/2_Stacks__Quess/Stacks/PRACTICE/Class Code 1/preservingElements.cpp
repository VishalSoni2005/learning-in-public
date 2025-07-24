#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int>ss;
    for(int i=1; i<=10; i++) ss.push(i*10);
    stack<int>ans;
    // cout << "Showing while deletion -> ";
    
    // cout << endl;
    // cout << "Elements of stacks are stored in vector -> ";
    // for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    // cout << endl;
    // // for(int i=1; i<=10; i++) ss.push(i)
    // cout << "Extracting form vector : ";
    // for(int i=0; i<10; i++) ss.push(ans[i]);
    // while(ss.size()>0) {
    //     cout << ss.top() << " ";
    //     // ans.push_back(ss.top());
    //     ss.pop();
    // }

    while(ss.size() > 0) {
        cout << ss.top() << " ";
        ans.push(ss.top());
        ss.pop();
    }
    cout << endl;
    while(ans.size() > 0) {
        cout << ans.top() << " ";
        ss.push(ans.top());
        ans.pop();
    }
    // cout << endl;
    // while(ss.size() > 0) {
    //     cout << ss.top() << " ";
    //     // ans.push(ss.top());
    //     ss.pop();
    // }
}