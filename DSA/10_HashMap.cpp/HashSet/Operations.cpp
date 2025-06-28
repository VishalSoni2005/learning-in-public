/**
 * ! set do not allow multiple entry;
 * * basic operations are -> insert, find, erase,
 * ? indexing in set starts form 0th
 */

#include <unordered_set>
#include <iostream>
using namespace std;

int main()
{
  cout << endl;
  // deceleration and displaying
  unordered_set<int> num1 = {1, 2, 3, 4, 5};
  num1.insert(10);
  cout << "Set one => ";
  for (auto i : num1)
    cout << i << " ";
  cout << endl;

  // * accessing the elements
  unordered_set<int> num2 = {1, 2, 3, 4, 5};
  cout << "Set two => ";
  for (auto i : num2)
    cout << i << " ";
  cout << endl;

  cout << "Element At 2nd position in set two : ";
  auto it = next(num2.begin(), 2); // used next function to access element

  // it -> itarator -> pointer to iterate
  //* num2.begin() → Returns an iterator(like a pointer) to the first element in the unordered_set.

  cout << *it << endl;
  // since the nums.begin() return operator we need to dereference it to ge its value


  return 0;
}