#include <iostream>
using namespace std;

void permutation(string &str, int l, int r)
{
  if (l == r) // base cose{
    cout << str << endl;
  return;
  for (int i = l; i <= r; i++)
  {
    swap(str[l], str[i]);
    permutation(str, l + 1, r);
    swap(str[l], str[i]);
  }
}

int main()
{
  string s = "abc";

  permutation(s, 0, s.length() - 1);
  return 0;
}