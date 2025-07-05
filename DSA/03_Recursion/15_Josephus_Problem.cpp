/**
 * ! TC : O(n^2)
 * * SC = O(n);
 */

#include <bits/stdc++.h>
using namespace std;

int predict_the_winner(int n, int k, vector<bool> &track, int person_left, int idx)
{
  if (person_left == 1)
  {
    for (int i = 0; i < track.size(); i++)
    {
      if (track[i] == 0)
        return i;
    }
  }

  // find position of person to be killed
  int kill = (k - 1) % person_left;

  while (kill--)
  {
    idx = (idx + 1) % n;

    // next alive person
    while (track[idx] == 1)
      idx = (idx + 1) % n;
  }

  track[idx] = 1;

  // next alive person
  while (track[idx] == 1)
    idx = (idx + 1) % n;

  int ans = predict_the_winner(n, k, track, person_left - 1, idx);
  return ans;
}

int optimised_josephus(int members, int steps)
{
  //! tc : o(n) and sc: o(n)
  if (members == 1)
    return 0;

  return (optimised_josephus(members - 1, steps) + steps) % members;
}

int main()
{
  int members = 8;
  int steps = 3;

  vector<bool> track(members, 0);
  int person_left = members;

  cout << "Winner is : " << predict_the_winner(members, steps, track, person_left, 0);

  cout << endl;
  cout << "From optimised solution : ";

  cout << optimised_josephus(members, steps) << endl;
}