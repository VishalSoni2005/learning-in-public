/**
 * ! TC: O(n^2)
 * * SC: O(n^2)
 */

#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char src, char helper, char dest)
{
  if (n == 0)
    return;

  TowerOfHanoi(n - 1, src, dest, helper);

  cout << "Move " << n << " from " << src << " to " << dest << endl;

  TowerOfHanoi(n - 1, helper, src, dest);
}
int main()
{
  int n;
  cout << "Enter the number of disks : ";
  cin >> n;
  TowerOfHanoi(n, 'A', 'B', 'C');
}