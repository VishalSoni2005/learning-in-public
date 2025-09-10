# 🚀 Queue Interview Patterns – Study Guide

This guide covers the **most important Queue problem-solving patterns** frequently asked in FAANG and top company interviews.  
Each pattern has:

- A **brief explanation**
- A curated list of **high-quality LeetCode/GFG problems**

---

## 1️⃣ Simple Queue (BFS Traversals)

👉 Core idea: Use queue for **level-order traversal** in trees/graphs, **shortest path in unweighted graphs**, and BFS-based grid problems.  
🔑 Most commonly asked queue usage in interviews.

### Problems

- [LeetCode 200 – Number of Islands](https://leetcode.com/problems/number-of-islands/)
- [LeetCode 542 – 01 Matrix](https://leetcode.com/problems/01-matrix/)
- [LeetCode 994 – Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)
- [GFG – Steps by Knight](https://www.geeksforgeeks.org/problems/steps-by-knight5927/1)

---

## 2️⃣ Circular Queue

👉 Queue with **wrap-around behavior**, avoids wasted space when using arrays. Common in **OS scheduling and networking buffers**.

### Problems

- [LeetCode 622 – Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)
- [LeetCode 641 – Design Circular Deque](https://leetcode.com/problems/design-circular-deque/)
- [GFG – Circular Tour](https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1)

---

## 3️⃣ Deque (Double-Ended Queue)

👉 A queue that allows **insertion and deletion from both ends**.  
👉 Often used in **sliding window problems** and maintaining monotonic properties.

### Problems

- [LeetCode 239 – Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- [LeetCode 862 – Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)
- [GFG – Maximum of all subarrays of size k](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)
- [LeetCode 207 – Course Schedule](https://leetcode.com/problems/course-schedule/)

---

## 4️⃣ Monotonic Queue

👉 A special **deque** that maintains **increasing or decreasing order** of elements.  
👉 Useful for problems requiring max/min in a sliding window or prefix optimization.

### Problems

- [LeetCode 239 – Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- [LeetCode 862 – Shortest Subarray with Sum ≥ K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)
- [LeetCode 1696 – Jump Game VI](https://leetcode.com/problems/jump-game-vi/)
- [GFG – Sum of minimum and maximum elements of all subarrays of size k](https://www.geeksforgeeks.org/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k5313/1)

---

## 5️⃣ LRU Cache (Queue + HashMap)

👉 Combination of **queue (or linked list)** and **hash map** for efficient caching.  
👉 Frequently asked in **system design + coding interviews**.

### Problems

- [LeetCode 146 – LRU Cache](https://leetcode.com/problems/lru-cache/)
- [LeetCode 460 – LFU Cache](https://leetcode.com/problems/lfu-cache/)
- [GFG – LRU Cache](https://www.geeksforgeeks.org/problems/lru-cache/1)

---

## 6️⃣ Implementing One DS using Queue

👉 Classic **implementation questions** where you simulate one DS with another.  
👉 Tests your fundamental understanding of queue behavior.

### Problems

- [LeetCode 225 – Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
- [LeetCode 232 – Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
- [GFG – Queue using two Stacks](https://www.geeksforgeeks.org/problems/queue-using-two-stacks/1)

---

# ✅ Study Plan (Recommended Order)

1. **Simple Queue (BFS Traversals)** → Foundation for graphs/trees.
2. **Deque + Monotonic Queue (Sliding Window)** → Must-know for FAANG.
3. **Circular Queue** → Implementation fundamentals.
4. **LRU Cache** → Common in system design interviews.
5. **Implement DS using Queue** → Strengthens fundamentals.

💡 Once you master these patterns, you’ll be ready for **any Queue-related FAANG interview question** 🚀🔥
