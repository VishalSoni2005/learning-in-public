# 📚 Stack Interview Patterns – FAANG Preparation Guide

This guide covers the **most frequently asked Stack problem patterns** in interviews at Amazon, Microsoft, Google, and other FAANG-level companies.  
Each section includes:

- A **brief explanation** of the pattern
- **3–4 high-quality problems** (LeetCode + GFG)

---

## **1. Balanced Parentheses & Expression Evaluation**

**Brief:**  
Use a stack to check whether parentheses/brackets are balanced, or to evaluate arithmetic/boolean expressions using operators.

🔗 **Problems**

1. [Valid Parentheses (LeetCode 20)](https://leetcode.com/problems/valid-parentheses/)
2. [Minimum Add to Make Parentheses Valid (LeetCode 921)](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
3. [Check for Balanced Brackets (GFG)](https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1)
4. [Evaluate Reverse Polish Notation (LeetCode 150)](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

---

## **2. Next Greater / Smaller Element (Monotonic Stack)**

**Brief:**  
Maintain a **monotonic increasing/decreasing stack** to efficiently find the next greater/smaller element for each item in an array in O(n).

🔗 **Problems**

1. [Next Greater Element I (LeetCode 496)](https://leetcode.com/problems/next-greater-element-i/)
2. [Next Greater Element II (LeetCode 503)](https://leetcode.com/problems/next-greater-element-ii/)
3. [Next Greater Element (GFG)](https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1)
4. [Daily Temperatures (LeetCode 739)](https://leetcode.com/problems/daily-temperatures/)

---

## **3. Min/Max Stack (O(1) GetMin/GetMax)**

**Brief:**  
Augment a normal stack with an auxiliary stack (or store pairs) to support **push, pop, top, getMin/getMax** in constant time.

🔗 **Problems**

1. [Min Stack (LeetCode 155)](https://leetcode.com/problems/min-stack/)
2. [Max Stack (LeetCode 716 - Premium, similar on GFG)](https://leetcode.ca/all/716.html)
3. [Special Stack – GFG](https://practice.geeksforgeeks.org/problems/special-stack/1)

---

## **4. Histogram / Largest Rectangle Problems**

**Brief:**  
Use **monotonic stacks** to find nearest smaller elements on both sides of each bar to compute the largest rectangle in a histogram or matrix.

🔗 **Problems**

1. [Largest Rectangle in Histogram (LeetCode 84)](https://leetcode.com/problems/largest-rectangle-in-histogram/)
2. [Maximal Rectangle (LeetCode 85)](https://leetcode.com/problems/maximal-rectangle/)
3. [Largest Rectangle in Histogram – GFG](https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1)

---

## **5. Stock Span / Span Problems**

**Brief:**  
A variation of **nearest greater element** where the stack is used to compute spans of stock prices or daily temperature trends.

🔗 **Problems**

1. [Stock Span Problem (GFG)](https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1)
2. [Online Stock Span (LeetCode 901)](https://leetcode.com/problems/online-stock-span/)
3. [Daily Temperatures (LeetCode 739)](https://leetcode.com/problems/daily-temperatures/)

---

## **6. Implementing Data Structures (with Stacks)**

**Brief:**  
Use stacks to simulate or implement other data structures like Queues, or manage multiple stacks in one array.

🔗 **Problems**

1. [Implement Queue using Stacks (LeetCode 232)](https://leetcode.com/problems/implement-queue-using-stacks/)
2. [Implement Stack using Queues (LeetCode 225)](https://leetcode.com/problems/implement-stack-using-queues/)
3. [Two Stacks in an Array – GFG](https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1)

---

# ✅ How to Use This File

1. Study **pattern by pattern**.
2. Attempt the **problems first** before looking at solutions.
3. Notice **recurring stack strategies** (monotonic stacks, auxiliary stacks, simulating structures).
4. Revisit problems after a week to reinforce patterns.

---
