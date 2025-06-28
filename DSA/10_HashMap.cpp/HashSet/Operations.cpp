/** 
 * ! set do not allow multiple entry;
 * * basic operations are -> insert, find, erase, 
 */

#include <unordered_set>
#include <iostream>
using namespace std;

int main()
{

  // deceleration and displaying
  unordered_set<int> num1 = {1, 2, 3, 4, 5};
  num1.insert(10);
  for(auto i : num1) cout << i << " ";
  cout << endl;

  // 

  return 0;
}