#include <bits/stdc++.h>
using namespace std;

void storeSubset(string ans, string original, vector<string> &v, bool flag)
{
  if (original == "")
  {
    v.push_back(ans);
    return;
  }

  char ch = original[0];

  // If only one character is left
  if (original.length() == 1)
  {
    if (flag == true)
      storeSubset(ans + ch, original.substr(1), v, true); // take it
    storeSubset(ans, original.substr(1), v, true);        // skip it
    return;
  }

  char dh = original[1];

  if (ch == dh)
  {
    // Include current character only if flag allows
    if (flag == true)
      storeSubset(ans + ch, original.substr(1), v, true);
    // Skip current character and block future includes for this duplicate
    storeSubset(ans, original.substr(1), v, false);
  }
  else
  {
    // Not a duplicate – safe to include or skip
    storeSubset(ans + ch, original.substr(1), v, true);
    storeSubset(ans, original.substr(1), v, true);
  }
}

int main()
{
  string s = "aabc";
  sort(s.begin(), s.end()); // Sort to bring duplicates together

  vector<string> v;
  storeSubset("", s, v, true);

  sort(v.begin(), v.end());                     // Optional: sort results
  v.erase(unique(v.begin(), v.end()), v.end()); // Remove any duplicates (if logic fails)

  for (string str : v)
  {
    if (str == "")
      cout << "\"\" ";
    else
      cout << str << " ";
  }

  return 0;
}
