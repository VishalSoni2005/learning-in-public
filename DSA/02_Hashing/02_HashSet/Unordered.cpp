/**
 * ! most important diff bt set and unordered_set is of arrangement or elements
| Feature              | `set`                         | `unordered_set`        |
| -------------------- | ----------------------------- | ---------------------- |
| Underlying structure | Balanced BST (Red-Black Tree) | Hash Table             |
| Order of elements    | Sorted (ascending by default) | No specific order      |
| Time Complexity      | `O(log n)`                    | `O(1)` on average      |
| Performance          | Slower (but ordered)          | Faster (but unordered) |
| Duplicate elements   | Not allowed                   | Not allowed            |

*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
  unordered_set<int> nums;

  for (int i = 0; i <= 10; i++)
    nums.insert(i * 10);
  nums.insert(1);
  nums.insert(3);

  for (auto i : nums) //? note the order your are observing while these output is completely random
    cout << i << " ";

  return 0;
}
