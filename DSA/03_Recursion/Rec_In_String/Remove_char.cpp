#include <iostream>
using namespace std;

string rchar(string ans, string original, char remove)
{
  if (original.length() == 0)
    return ans;
  char temp = original[0];
  if (temp == remove)
    return rchar(ans, original.substr(1), remove);

  ans.push_back(temp);
  return rchar(ans, original.substr(1), remove);
}

int main()
{
  cout << "New Char => " << rchar("", "abaaalskdjfa;lskdjf;alkjdfbsx", 'a');
}