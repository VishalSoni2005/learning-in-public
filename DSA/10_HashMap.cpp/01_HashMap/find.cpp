/**
 * * find() return an iterator if element exit otherwise it return end() iterator
 * ! T.C. => o(1)
 * ? nums.end() -> iterator that point next to last element in map
 * ? nums.begin() -> iterator that point to first element
 * * we search using key not by values. to search using value you should leaner traversal
 * 
 * 
 */
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
  unordered_map<int, int> m = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

  cout << "Enter the no. you wanna search : ";
  int n;
  cin >> n;
  auto it = m.find(n);
  if(it != m.end()) 
    cout << "Requested Element is : " << it->second;
  else
    cout << "Requested Element is : Unavailable";
  cout << endl;

  return 0;
}