#include <vector>
#include <iostream>

int main()
{
  std::vector<int> vec = {1, 2, 3, 4, 5};

  // Without auto (explicit type)
  for (int x : vec)
  {
    std::cout << x << " ";
  }

  // With auto (compiler deduces type as 'int')
  for (auto x : vec)
  {
    std::cout << x << " ";
  }

  // With auto& (to modify elements or avoid copies)
  for (auto &x : vec)
  {
    x *= 2; // modifies the original vector
  }

  // With const auto& (read-only, no copies)
  for (const auto &x : vec)
  {
    std::cout << x << " ";
  }
}