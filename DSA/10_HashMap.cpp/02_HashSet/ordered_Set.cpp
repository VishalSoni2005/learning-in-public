/**
 * binary search tree
 * ! set do not allow multiple entry;
 * * by default it is sorted in ascending order
 * traversal using iterator
 */
#include <iostream>
#include <set>
using namespace std;

int main()
{
  set<int> nums = { 3, 2, 1, 4, 5 };
  for (auto i : nums)
    cout << i << " ";
  cout << endl;

  cout << "Traversing => ";
  for(auto it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " -> ";
  }
  cout << "((.) (.))" << endl;

  return 0;
}