# Monotonic Stack & Queue Patterns

A structured breakdown of all subtopics and subpatterns that commonly appear in interviews (FAANG, top fintechs, etc.).  
Each subpattern has associated canonical problems (see problem table separately).

---

## 1. Next Greater / Smaller Elements
**Core idea:** Maintain a stack to find the next greater/smaller element for each index in linear time.

- Next Greater Element (linear scan)
- Next Smaller Element (linear scan)
- Next Greater / Smaller in **Circular Arrays**
- Next Greater Node in **Linked Lists**
- Stock Span / Daily Temperatures (variations of NGE)
- Visibility Problems (e.g., queue of people, ocean view)
- Contribution Technique with Next/Prev Greater/Smaller:
  - Sum of Subarray Minimums
  - Sum of Subarray Ranges
  - Min-Product
  - Wizards Strength

---

## 2. Stack-Based Removal / Greedy
**Core idea:** Use a monotonic stack to enforce lexicographic order, remove dominated elements, or stabilize arrays.

- Lexicographically Smallest Subsequence (remove larger elements when possible)
- Remove Duplicate Letters / Keep Distinct Smallest String
- Most Competitive Subsequence
- Removing Stars / Backspace Variants
- Asteroid Collision (simulate using monotone stack)
- Steps to Make Array Non-Decreasing
- Count Collisions on Road
- 132 Pattern Detection
- Parentheses Scoring / Balancing via stack
- String Cleanup Problems (e.g., “make string good”)

---

## 3. Contribution Tricks (Subarray Minimums / Maximums)
**Core idea:** For each element, compute how many subarrays it is the minimum/maximum of, using next/prev greater/less.

- Count of Subarrays Where `arr[i]` is Minimum
- Count of Subarrays Where `arr[i]` is Maximum
- Sum of Subarray Minimums
- Sum of Subarray Ranges (max − min contribution)
- Maximum Subarray Min-Product
- Total Strength of Wizards (double prefix-sum + contribution)
- Subarray With Elements Greater Than Threshold
- Mountain/Tower Building (beautiful towers, peaks/valleys)

---

## 4. Monotonic Queue (Deque)
**Core idea:** Maintain a deque that is always monotonic to handle sliding windows or DP with constraints.

- Sliding Window Maximum (classic)
- Sliding Window Minimum
- Jump Game VI (max over last `k` DP states)
- Constrained Subsequence Sum
- Max Value of Equation (slope trick + deque)
- Shortest Subarray With Sum ≥ K (prefix sums + deque)
- Longest Subarray with Absolute Difference ≤ Limit

---

## 5. Linked List / Array Variants
**Core idea:** Apply monotonic reasoning on linked structures or two-pass arrays.

- Next Greater Node in Linked List
- Remove Nodes From Linked List (reverse + monotonic stack)
- Good Days to Rob the Bank (two-pass with monotonic constraints)
- Mountain / Tower building problems

---

## 6. Array Shaping / Visibility Problems
**Core idea:** Use decreasing/increasing stacks to model “who can see whom” or “ocean/mountain views.”

- Buildings With Ocean View
- Number of Visible People in a Queue
- Remove dominated heights to stabilize views

---

## 7. String Problems With Monotone Stack
**Core idea:** Maintain monotonic order to build smallest lexicographic strings or enforce constraints.

- Robot Printing Lexicographically Smallest String
- Smallest Subsequence With Occurrences of a Letter
- Most Competitive Subsequence
- Smallest Subsequence of Distinct Characters
- Remove Duplicate Letters
- Removing Stars From a String (stack cleanup)

---

# Canonical Solution Patterns
- **Next Greater/Smaller**: Use increasing/decreasing stack, scan once (or twice for circular).
- **Contribution Technique**: Compute left span & right span (strict vs non-strict matters) → contribution = value × countLeft × countRight.
- **Lexicographic Removal**: While stack top > current and quota/occurrences allow, pop.
- **Monotonic Queue**: For sliding window, maintain max/min in deque; for DP, maintain candidate states.
- **Linked List / Array Variants**: Reverse + monotone stack, or two-pointer + monotonic logic.
- **Visibility**: Decreasing stack, pop until taller element found; count neighbors.
- **Strings**: Stack ensures smallest lexicographic order while respecting frequency/uniqueness.

---

🔥 This README gives you the **entire taxonomy** of monotonic stack/queue questions.  
The problem list you already have plugs into each of these buckets.
