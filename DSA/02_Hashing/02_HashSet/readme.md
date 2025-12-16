| Operation                    | `set` (`std::set`) | `unordered_set` (`std::unordered_set`) |
| ---------------------------- | ------------------ | -------------------------------------- |
| `insert(x)`                  | `O(log n)`         | **`O(1)`** on average, `O(n)` worst    |
| `erase(x)`                   | `O(log n)`         | **`O(1)`** on average, `O(n)` worst    |
| `find(x)`                    | `O(log n)`         | **`O(1)`** on average, `O(n)` worst    |
| `count(x)`                   | `O(log n)`         | **`O(1)`** on average                  |
| `size()`                     | `O(1)`             | `O(1)`                                 |
| `empty()`                    | `O(1)`             | `O(1)`                                 |
| `clear()`                    | `O(n)`             | `O(n)`                                 |
| `begin()` / `end()`          | `O(1)`             | `O(1)`                                 |
| `*it` (dereference iterator) | `O(1)`             | `O(1)`                                 |
| `lower_bound(x)`             | `O(log n)`         | ❌ Not available                        |
| `upper_bound(x)`             | `O(log n)`         | ❌ Not available                        |
| `equal_range(x)`             | `O(log n)`         | ❌ Not available                        |
