#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string &str) {
    if(str.length() % 2 != 0) return false;
    stack<char> ans;
    
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(') ans.push(str[i]);
        else if(str[i] == ')') {
            //analyse the stack
            if(ans.top() == '(') ans.pop();
            else ans.push(str[i]);
        }
    }
    if(ans.size() == 0) return true; 
    else return false;

}
int main() {
    string str = "())()(";
    cout << isBalanced(str);
    
}