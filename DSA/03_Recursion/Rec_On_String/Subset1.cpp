#include<bits/stdc++.h>
using namespace std;

void subset(string original,string dummy, vector<string>&ans) {
  if(original.length() == 0) {
    ans.push_back(dummy);
    return;
  }
  char temp = original[0];
  subset(original.substr(1), dummy + temp, ans);
  subset(original.substr(1), dummy, ans);
}

int main() //! string have unique characters
{
    vector<string>ans;
    subset("abc","", ans);
    sort(ans.begin(), ans.end());

    for (string s : ans)
    {
      if (s == "")
        cout << "\"\"" << " ";
      else
        cout << s << " ";
    }

    return 0;
}