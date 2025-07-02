#include <bits/stdc++.h>
using namespace std;

void subset(vector<vector<int>> &ans, vector<int> &v, vector<int> helper, int size)
{
  if (size == 0)
  {
    ans.push_back(helper);
    return;
  }

  subset(ans, v, helper, size - 1);
  helper.push_back(v[size - 1]);
  subset(ans, v, helper, size - 1);
  helper.pop_back();
  
}

int main()
{
  vector<vector<int>> ans;
  vector<int> v = {3, 4, 5};
  vector<int> helper;

  subset(ans, v, helper, 3);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  vector<int> subsetSum;
  for (auto i : ans)
  {
    int count = 0;
    for (auto j : i)
    {
      count += j;
    }
    subsetSum.push_back(count);
  }

  cout << "Array of Sum is : ";
  for (int i : subsetSum)
    cout << i << " ";

  cout << "\nTotal sum : ";
  int count = 0;
  for (auto i : subsetSum)
    count += i;
  cout << count;
}
