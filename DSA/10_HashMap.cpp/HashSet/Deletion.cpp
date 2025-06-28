
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

  //* we use erase() fn to delete

  num1.erase(2);

  for (auto i : num1)
    cout << i << " ";
  cout << endl;

  num1.erase(num1.begin());
  for (auto i : num1)
    cout << i << " ";
  cout << endl;

  num1.erase(next(num1.begin(), 3)); // delete 1
  for (auto i : num1)
    cout << i << " ";
  cout << endl;

  cout << "Count Of Element => " << num1.size();
}