#include<bits/stdc++.h>
using namespace std;
void display(queue<int>& ans) {
    cout << "Your Queue Sir : ";
    int n = ans.size();
    for(int i=1; i<=n; i++) {
        int x = ans.front(); 
        cout << x << " ";
        ans.pop();
        ans.push(x);
    }
    cout << endl;
}
int main() {
    queue<int> q;
    for(int i=1; i<=10; i++) q.push(i*10);
    display(q);

    stack<int> helper;
    for(int i=0; i<10; i++) {
        int x = q.front();
        helper.push(x);
        q.pop();
    }
    display(q);
    while(!helper.empty()) {
        int x = helper.top();
        helper.pop();
        q.push(x);
    }
    display(q);

}