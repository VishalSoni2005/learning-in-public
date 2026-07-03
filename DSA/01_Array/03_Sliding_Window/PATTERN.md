# Sliding Window

A range `[l → r]` that moves across the input. Converts O(n²) brute force into O(n) by reusing prior computation.

**Apply when:** problem involves contiguous subarrays / substrings and asks for optimal, longest, shortest, or count of something.

---

## Core Types

| Type              | When to use               | Mechanism                                             |
| ----------------- | ------------------------- | ----------------------------------------------------- |
| **Fixed size**    | Window size = k is given  | Add right element, remove left element each step      |
| **Variable size** | Condition determines size | Expand right until violation, shrink left until valid |

---

## 1. Fixed Size Window

### Must Do

| Problem                                  | Link                                                                                    |
| ---------------------------------------- | --------------------------------------------------------------------------------------- |
| Maximum average subarray of size k       | [LC 643](https://leetcode.com/problems/maximum-average-subarray-i/)                     |
| Sliding window maximum ⭐⭐              | [LC 239](https://leetcode.com/problems/sliding-window-maximum/)                         |
| First negative in every window of size k | [GFG](https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/)        |
| Count distinct elements in every window  | [GFG](https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/) |

---

## 2. Variable Size Window

### Sub-pattern A — Longest Subarray / Substring

> Maximize window length. Expand right freely, shrink left on violation.

| Problem                                           | Link                                                                                        |
| ------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| Longest substring without repeating characters ⭐ | [LC 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/)       |
| Longest repeating character replacement ⭐        | [LC 424](https://leetcode.com/problems/longest-repeating-character-replacement/)            |
| Max consecutive ones III                          | [LC 1004](https://leetcode.com/problems/max-consecutive-ones-iii/)                          |
| Fruit into baskets                                | [LC 904](https://leetcode.com/problems/fruit-into-baskets/)                                 |
| Longest subarray of 1s after deleting one element | [LC 1493](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/) |

---

### Sub-pattern B — Smallest / Minimum Window

> Minimize window size. Shrink from left as soon as condition is satisfied.

| Problem                                   | Link                                                                                          |
| ----------------------------------------- | --------------------------------------------------------------------------------------------- |
| Minimum window substring ⭐⭐             | [LC 76](https://leetcode.com/problems/minimum-window-substring/)                              |
| Smallest subarray with sum greater than x | [GFG](https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1) |
| Minimum size subarray sum                 | [LC 209](https://leetcode.com/problems/minimum-size-subarray-sum/)                            |
| Shortest subarray with sum ≥ k            | [LC 862](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)                |
| Replace the substring for balanced string | [LC 1234](https://leetcode.com/problems/replace-the-substring-for-balanced-string/)           |

---

### Sub-pattern C — Count of Valid Subarrays

> Each valid window ending at `r` contributes `(r - l + 1)` subarrays.

```
count += (r - l + 1)
```

| Problem                                              | Link                                                                                           |
| ---------------------------------------------------- | ---------------------------------------------------------------------------------------------- |
| Number of subarrays with at most k distinct ⭐       | [LC 992](https://leetcode.com/problems/subarrays-with-k-different-integers/)                   |
| Binary subarrays with sum                            | [LC 930](https://leetcode.com/problems/binary-subarrays-with-sum/)                             |
| Count number of nice subarrays                       | [LC 1248](https://leetcode.com/problems/count-number-of-nice-subarrays/)                       |
| Number of substrings containing all three characters | [LC 1358](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) |
| Count complete subarrays in an array                 | [LC 2799](https://leetcode.com/problems/count-complete-subarrays-in-an-array/)                 |

---

### Sub-pattern D — Exactly K (Indirect Count)

> Can't count "exactly k" directly with a single window. Use subtraction.

```
exact(k) = atMost(k) - atMost(k - 1)
```

| Problem                                        | Link                                                                                           |
| ---------------------------------------------- | ---------------------------------------------------------------------------------------------- |
| Subarrays with k different integers ⭐         | [LC 992](https://leetcode.com/problems/subarrays-with-k-different-integers/)                   |
| Count number of nice subarrays (exactly k odd) | [LC 1248](https://leetcode.com/problems/count-number-of-nice-subarrays/)                       |
| Binary subarrays with sum = goal               | [LC 930](https://leetcode.com/problems/binary-subarrays-with-sum/)                             |
| Number of substrings with all three characters | [LC 1358](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) |

> **Note:** LC 992 is the canonical problem for this trick — solve it consciously using atMost.

---

### Sub-pattern E — Window + Data Structure

> When you need max/min inside the window efficiently.
> Use **monotonic deque** for O(1) range max/min. Use **two heaps** for median.

| Problem                                           | Link                                                                                                                 |
| ------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| Sliding window maximum ⭐⭐                       | [LC 239](https://leetcode.com/problems/sliding-window-maximum/)                                                      |
| Sliding window median ⭐                          | [LC 480](https://leetcode.com/problems/sliding-window-median/)                                                       |
| Longest continuous subarray with abs diff ≤ limit | [LC 1438](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) |
| Maximum number of robots within budget            | [LC 2398](https://leetcode.com/problems/maximum-number-of-robots-within-budget/)                                     |
| Jump game VI (deque DP)                           | [LC 1696](https://leetcode.com/problems/jump-game-vi/)                                                               |

---

## Quick Decision Guide

```
Is window size fixed?
  └── Yes → Fixed window
  └── No  → Variable window
        ├── Maximize length?       → Sub-pattern A
        ├── Minimize length?       → Sub-pattern B
        ├── Count valid windows?   → Sub-pattern C  (count += r - l + 1)
        ├── Count exactly k?       → Sub-pattern D  (atMost(k) - atMost(k-1))
        └── Need max/min in window → Sub-pattern E  (deque / heap)
```

---

## Complexity

| Approach                   | Time       | Space                 |
| -------------------------- | ---------- | --------------------- |
| Brute force (nested loops) | O(n²)      | O(1)                  |
| Sliding window             | O(n)       | O(k) for window state |
| Window + deque             | O(n)       | O(k)                  |
| Window + two heaps         | O(n log k) | O(k)                  |
