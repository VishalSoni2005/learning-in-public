/**
 * The iterator points to a std::pair<const Key, Value>:
    Not just the key or just the value
    Not separate pointers to first and second
    A single pointer to the complete pair object in memory

  * it is a iterator pointer
  * *it -> dereference
  * it->second -> access value
  *
  * For unordered maps (std::unordered_map):
    Typically contains a pointer to a hash bucket node
    The node contains the pair plus a pointer to the next node


 */

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
  unordered_map<int, int> m = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

  // it is a iterator pointer
  // *it -> dereference
  // it->second -> access value
  for (auto it = m.begin(); it != m.end(); it++)
  {
    cout << (*it).first << " -> " << it->second << endl;
  }
}