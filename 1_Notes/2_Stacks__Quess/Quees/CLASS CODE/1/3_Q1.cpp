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

void reverse(queue<int>& q) {
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
}

void removeAtEven(queue<int>& qeu) {
    int n = qeu.size();
    for(int i=0; i<n; i++) {
        if(i % 2 != 0) {
            int x = qeu.front();
            qeu.push(x);
        }
        qeu.pop();
    }
}
 

int main() {
    queue<int> q;
    cout << "Fill the queue sir : ";
    for(int i=1; i<=5; i++) {
        int c;
        cin>>c;
        q.push(c);
    }
    display(q);
    removeAtEven(q);
    display(q);


}