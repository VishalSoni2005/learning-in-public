# 🚀 Classic Queue Problems (Sliding Window + Monotonic Queue)

This list covers **frequent interview problems** that use **sliding window** and **monotonic queue** patterns.  
Mastering these ensures you can solve 90% of queue-related interview questions.

---

## 📌 Sliding Window Problems

1. **[239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)** 🏆

   - The _most famous_ monotonic deque problem.
   - Maintain decreasing deque of window candidates.

2. **[209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)**

   - Shrink & grow window until condition is met.

3. **[76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)**

   - Hard, but a _classic_ sliding window with hashmap + queue pattern.

4. **[3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)**

   - Sliding window with set/map to maintain unique characters.

5. **[438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)**
   - Sliding window + frequency counting.

---

## 📌 Monotonic Queue Problems

1. **[239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)**

   - Centerpiece problem for monotonic deque.

2. **[862. Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)**

   - Uses monotonic deque + prefix sums.

3. **[1425. Constrained Subsequence Sum](https://leetcode.com/problems/constrained-subsequence-sum/)**

   - Dynamic programming + monotonic deque optimization.

4. **[1438. Longest Continuous Subarray With Absolute Diff ≤ Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)**
   - Maintain **two deques** (min + max).

---

## 📌 Other Queue-Based Window Problems

- **[First Negative Integer in Every Window of Size K](https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/)** (GFG classic)
- **[346. Moving Average from Data Stream](https://leetcode.com/problems/moving-average-from-data-stream/)**
- **[1004. Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)**
- **[727. Minimum Window Subsequence](https://leetcode.com/problems/minimum-window-subsequence/)**

---

## ✅ Interview-Repeat Essentials

If you’re short on time, focus on these:

- **239. Sliding Window Maximum**
- **First Negative Integer in Every Window (GFG)**
- **862. Shortest Subarray with Sum at Least K**
- **1438. Longest Subarray with Abs Diff ≤ Limit**
- **209. Minimum Size Subarray Sum**

---

💡 **Tip:** Once you understand how the **monotonic deque** works in **Sliding Window Maximum**, the rest will feel much easier.
