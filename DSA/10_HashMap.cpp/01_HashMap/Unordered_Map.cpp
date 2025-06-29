/**
 * * stores data in the form of unique key-value pairs.
 * * unordered_map is a container that stores elements in a hash table.
 * ? use hash function to map the values
 * ? hash table is a dynamic array of buckets
 * * average time complexity => O(1)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

void print(unordered_map<int, string> m)
{
  cout << "First {} Second" << endl;
  for (auto i : m)
    cout << i.first << " -> " << i.second << endl;
  cout << endl;
}

void traversal(unordered_map<int, string> m)
{
  cout << "Unordered Map Traversal" << endl;
  for (auto it = m.begin(); it != m.end(); it++)
    cout << it->first << " -> " << it->second << endl;
}

void update_value(unordered_map<int, string> m, int key, string value) {
  m[key] = value;
  cout << "Updated Value : " << m[key] << endl;
}

int main()
{
  // unordered_map<key, value>
  unordered_map<int, string> m = {{1, "Vishal"}, {2, "Varun"}, {3, "Rohit"}, {4, "Vishal"}, {5, "Vishal"}};

  // print(m);

  traversal(m);

  m[69] = "Trash";

  m.insert({10, "Raghav"});

  print(m);

  //? update value
  update_value(m, 1, "Vishal");

  //? delete value
  m.erase(1);

  print(m);

  m.at(2) = "Vishal";
  print(m);

}