
#include <unordered_set>
#include <iostream>
using namespace std;

int main()
{
  cout << endl;
  unordered_set<int> num1 = {1, 2, 3, 4, 5};

  cout << "Traversing => ";

  for (auto it = num1.begin(); it != num1.end(); it++)
    cout << *it << " ";
  cout << endl;

  cout << "Count Of Element => " << num1.size();
}