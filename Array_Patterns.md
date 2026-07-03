# 📊 Array Patterns Roadmap — DSA Preparation

A quick-reference guide + flowchart for the 12 most-asked array patterns in coding interviews.

---

## 🗺️ Pattern Flowchart

```mermaid
flowchart TD
    A[Array Problem] --> B{What's the clue?}

    B -->|Sorted array + pair/triplet sum| C[1. Two Pointers]
    B -->|Contiguous subarray/substring with condition| D[2. Sliding Window]
    B -->|Range sum queries / subarray sum = K| E[3. Prefix Sum]
    B -->|Max/min subarray sum| F[4. Kadane's Algorithm]
    B -->|Cycle or duplicate detection| G[5. Fast & Slow Pointers]
    B -->|Overlapping ranges/intervals| H[6. Merge Intervals]
    B -->|Numbers in range 1 to n| I[7. Cyclic Sort]
    B -->|Sorted/rotated array search or search space| J[8. Binary Search]
    B -->|Custom ordering needed| K[9. Sorting-based Patterns]
    B -->|Need O1 lookups / counting| L[10. Hashing / Frequency Counting]
    B -->|2D grid traversal/rotation| M[11. Matrix Patterns]
    B -->|Local optimal choice works| N[12. Greedy on Arrays]

    C --> C1[Two Sum II, 3Sum, Container With Most Water]
    D --> D1[Max Sum Subarray K, Longest Substring, Min Window Substring]
    E --> E1[Subarray Sum = K, Range Sum Query, Product Except Self]
    F --> F1[Maximum Subarray, Circular Subarray, Max Product Subarray]
    G --> G1[Find Duplicate Number, Circular Array Loop]
    H --> H1[Merge Intervals, Insert Interval, Non-overlapping Intervals]
    I --> I1[Missing Number, Find All Duplicates, First Missing Positive]
    J --> J1[Rotated Sorted Array Search, Peak Element, Koko Eating Bananas]
    K --> K1[Merge Sorted Array, Sort Colors, Meeting Rooms]
    L --> L1[Two Sum, Group Anagrams, Longest Consecutive Sequence]
    M --> M1[Spiral Matrix, Rotate Image, Set Matrix Zeroes]
    N --> N1[Jump Game, Gas Station, Candy Distribution]
```

---

## 📚 Pattern Reference Table

| #   | Pattern                          | When to Use                                    | Example Problems                                                      |
| --- | -------------------------------- | ---------------------------------------------- | --------------------------------------------------------------------- |
| 1   | **Two Pointers**                 | Sorted array, pair/triplet sum                 | Two Sum II, 3Sum, Container With Most Water                           |
| 2   | **Sliding Window**               | Contiguous subarray/substring with a condition | Max Sum Subarray of Size K, Longest Substring Without Repeating Chars |
| 3   | **Prefix Sum**                   | Range sum queries, subarray sum = K            | Subarray Sum Equals K, Range Sum Query, Product of Array Except Self  |
| 4   | **Kadane's Algorithm**           | Max/min contiguous subarray sum                | Maximum Subarray, Maximum Circular Subarray Sum                       |
| 5   | **Fast & Slow Pointers**         | Cycle or duplicate detection                   | Find Duplicate Number, Circular Array Loop                            |
| 6   | **Merge Intervals**              | Overlapping ranges                             | Merge Intervals, Insert Interval                                      |
| 7   | **Cyclic Sort**                  | Numbers in range [1, n]                        | Find Missing Number, First Missing Positive                           |
| 8   | **Binary Search**                | Sorted/rotated array or search space problems  | Search in Rotated Sorted Array, Koko Eating Bananas                   |
| 9   | **Sorting-based**                | Custom order + greedy logic                    | Merge Sorted Array, Sort Colors, Meeting Rooms                        |
| 10  | **Hashing / Frequency Counting** | Need O(1) lookups, avoid nested loops          | Two Sum, Group Anagrams, Longest Consecutive Sequence                 |
| 11  | **Matrix Patterns**              | 2D array traversal/rotation                    | Spiral Matrix, Rotate Image, Set Matrix Zeroes                        |
| 12  | **Greedy on Arrays**             | Local optimal choice → global optimum          | Jump Game, Gas Station, Candy Distribution                            |

---

## ✅ Suggested Practice Order

```
Two Pointers → Sliding Window → Prefix Sum → Kadane's Algorithm
→ Hashing → Sorting-based → Cyclic Sort → Binary Search
→ Merge Intervals → Matrix Patterns → Greedy → Fast/Slow Pointers
```

**Tip:** Solve 3–5 problems (easy → medium → hard) per pattern before moving on.

---

## 📝 Progress Tracker

- [ ] Two Pointers
- [ ] Sliding Window
- [ ] Prefix Sum
- [ ] Kadane's Algorithm
- [ ] Fast & Slow Pointers
- [ ] Merge Intervals
- [ ] Cyclic Sort
- [ ] Binary Search
- [ ] Sorting-based Patterns
- [ ] Hashing / Frequency Counting
- [ ] Matrix Patterns
- [ ] Greedy on Arrays

---

_Last updated: keep this file in your DSA repo and check off patterns as you master them!_
