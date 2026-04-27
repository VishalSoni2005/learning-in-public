#include <vector>
#include <iostream>
using namespace std;

void par(vector<string>&ans, string str, int target, int left, int right) {
  if(str.length() == 2 * target ) {
    ans.push_back(str);
    return ;
  }
  if(left < target) par(ans, str + '(',target, left + 1, right);
  if(right < left) par(ans, str + ")", target, left, right + 1);
}

int main()
{
  int x = 3;
  vector<string>ans;
  par(ans, "", x, 0, 0);
  for(auto i : ans) cout << i << endl;
  return 0;
}