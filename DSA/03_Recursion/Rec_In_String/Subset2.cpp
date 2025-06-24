#include<bits/stdc++.h>
using namespace std;
void subset(string original, string dummy, vector<string>&ans, bool flag) {
  if()
}

int main() //! string can have dublicate can but ans should be unique
{
    vector<string>ans;
    subset("aabc", "", ans, true);
    sort(ans.begin(), ans.end());

    for(string s : ans) {
      if(s == "") cout << "\"\"" << " ";
      else cout << s << " ";
    }
    return 0;
}