#include <bits/stdc++.h>
using namespace std;
void helper(vector<string> &ans, int n, string s, int no1 = 0, int noz = 0)
{
  if (s.size() == n)
  {
    ans.push_back(s);
    return;
  }

  // You can always add '1'
  s.push_back('1');
  helper(ans, n, s, no1 + 1, noz);
  s.pop_back();

  // Add '0' only if number of 1s > number of 0s
  if (no1 > noz)
  {
    s.push_back('0');
    helper(ans, n, s, no1, noz + 1);
    s.pop_back();
  }
}

int main()
{
  int n = 2;
  //@VishalSoni2005 Bit Manipulation
  // for (int i = 0; i < (1 << n); i++) {
  //   for (int j = 0; j < n; j++) {
  //     if (i & (1 << j)) {
  //       cout << 1;
  //     } else {
  //       cout << 0;
  //     }
  //   }
  //   cout << endl;
  // }

  vector<string> ans;

  string s = "";
  helper(ans, n, s);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
  }
}