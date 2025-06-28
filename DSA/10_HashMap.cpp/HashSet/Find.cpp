/**
 * * find() return an iterator if element exit otherwise it return end() iterator
 * ! T.C. => o(1)
 * ? nums.end() -> iterator that point next to last element in set
 */
#include <unordered_set>
#include <iostream>
using namespace std;


int main()
{
  cout << endl;
  unordered_set<int> nums = {1, 2, 3, 4, 5};
  int n;
  cout << "What you wanna search in nums : ";
  cin >> n;

  cout << "Enter the no. you wanna insert : ";
  int z;
  cin >> z;

  auto it = nums.find(n);
  if (it != nums.end())
    cout << "Requested Element is : " << *it;
  else
    cout << "Requested Element is : Unavailable";
  cout << endl;

  //? Using find() Before Insertion (Avoid Duplicates)

  unordered_set<int> nums2 = {1, 2, 3, 4, 5, 6, 7};
  

  if(nums2.find(z) == nums2.end() ) { //! we are comparing with end() because when element is not find via find() it returns end() iterator
    cout << "Inserted an unique entry";
  }
  else cout << "It is not an unique entry : Rejected.";

}