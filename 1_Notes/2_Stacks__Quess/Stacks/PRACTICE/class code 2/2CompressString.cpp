#include<bits/stdc++.h>
using namespace std;
void display (stack<char>original) {
    stack<char>helper;

    while(original.size() != 0) {
        helper.push(original.top());
        original.pop();
    }

    while(helper.size() != 0) {
        cout << helper.top() << " ";
        original.push(helper.top());
        helper.pop();
    }
    cout << endl;
}


string compress(string &str) {
    stack<char>helper;
    helper.push(str[0]);
    for(int i=1; i<str.length(); i++) {
        if(str[i] == helper.top()) continue;
        else if(str[i] != helper.top()) helper.push(str[i]);
    }
    display(helper);

}
int main() {
    string str = "aaabbcddaab";
    cout << compress(str);
}