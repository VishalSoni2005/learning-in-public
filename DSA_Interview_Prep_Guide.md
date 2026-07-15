# DSA Interview Preparation Handbook

A complete, pattern-first roadmap for cracking coding interviews at top product-based companies (Google, Amazon, Microsoft, Meta, Flipkart, etc.). Topics are ordered from foundational to advanced. Within each topic, patterns are ordered by interview frequency.

---

## Table of Contents

1. [Arrays](#1-arrays)
2. [Strings](#2-strings)
3. [Two Pointers](#3-two-pointers)
4. [Sliding Window](#4-sliding-window)
5. [Hashing](#5-hashing)
6. [Sorting](#6-sorting)
7. [Binary Search](#7-binary-search)
8. [Recursion & Backtracking](#8-recursion--backtracking)
9. [Linked List](#9-linked-list)
10. [Stack & Queue](#10-stack--queue)
11. [Trees](#11-trees)
12. [Binary Search Trees (BST)](#12-binary-search-trees-bst)
13. [Heaps / Priority Queue](#13-heaps--priority-queue)
14. [Tries](#14-tries)
15. [Graphs](#15-graphs)
16. [Dynamic Programming](#16-dynamic-programming)
17. [Greedy Algorithms](#17-greedy-algorithms)
18. [Bit Manipulation](#18-bit-manipulation)
19. [Intervals](#19-intervals)
20. [Final Revision Strategy](#20-final-revision-strategy)

---

## 1. Arrays

### Prerequisites

None — starting topic.

### Concepts to Learn

- Static vs dynamic arrays, memory layout
- Time complexity of insert/delete/access/search
- In-place vs extra-space manipulation
- Prefix sum / suffix sum
- Kadane's Algorithm
- Cyclic sort
- Dutch National Flag partitioning

### Question Patterns Asked

**Pattern: Prefix Sum**

- Sub-pattern: Range sum queries
- Sub-pattern: Subarray sum equals K (with HashMap)
- Sub-pattern: Equilibrium / pivot index

| Problem                            | Platform | Difficulty |
| ---------------------------------- | -------- | ---------- |
| Range Sum Query - Immutable        | LeetCode | Easy       |
| Subarray Sum Equals K              | LeetCode | Medium     |
| Product of Array Except Self       | LeetCode | Medium     |
| Find Pivot Index                   | LeetCode | Easy       |
| Continuous Subarray Sum            | LeetCode | Medium     |
| Maximum Size Subarray Sum Equals K | LeetCode | Medium     |

**Pattern: Kadane's Algorithm (Max/Min Subarray)**

- Sub-pattern: Maximum sum subarray
- Sub-pattern: Maximum product subarray
- Sub-pattern: Circular array variant

| Problem                         | Platform | Difficulty |
| ------------------------------- | -------- | ---------- |
| Maximum Subarray                | LeetCode | Easy       |
| Maximum Product Subarray        | LeetCode | Medium     |
| Maximum Sum Circular Subarray   | LeetCode | Medium     |
| Best Time to Buy and Sell Stock | LeetCode | Easy       |
| House Robber                    | LeetCode | Medium     |

**Pattern: In-place Manipulation**

- Sub-pattern: Rearrangement (move zeroes, sort colors)
- Sub-pattern: Rotation
- Sub-pattern: Cyclic sort (missing/duplicate number)

| Problem                                  | Platform | Difficulty |
| ---------------------------------------- | -------- | ---------- |
| Move Zeroes                              | LeetCode | Easy       |
| Sort Colors (Dutch National Flag)        | LeetCode | Medium     |
| Rotate Array                             | LeetCode | Medium     |
| Find All Numbers Disappeared in an Array | LeetCode | Easy       |
| Find the Duplicate Number                | LeetCode | Medium     |
| First Missing Positive                   | LeetCode | Hard       |

**Pattern: Matrix (2D Array)**

- Sub-pattern: Traversal (spiral, diagonal)
- Sub-pattern: In-place transformation
- Sub-pattern: Search in matrix

| Problem            | Platform | Difficulty |
| ------------------ | -------- | ---------- |
| Rotate Image       | LeetCode | Medium     |
| Spiral Matrix      | LeetCode | Medium     |
| Set Matrix Zeroes  | LeetCode | Medium     |
| Search a 2D Matrix | LeetCode | Medium     |
| Word Search        | LeetCode | Medium     |

### Key Observations

- If a problem mentions "contiguous subarray" + sum/product condition, think Kadane's or prefix sum + HashMap first.
- If values are bounded within `[1, n]`, cyclic sort is often the O(n) time / O(1) space trick — commonly tested via "missing number" and "duplicate number" variants.
- Common mistake: forgetting integer overflow in product-based problems and not resetting running min/max in Kadane's product variant when a zero is encountered.
- Matrix rotation in-place is a classic transpose + reverse trick — memorize it, don't derive it under pressure.

---

## 2. Strings

### Prerequisites

Arrays

### Concepts to Learn

- Character arrays vs immutable strings (language-specific mutability)
- ASCII/frequency counting
- String building efficiency (StringBuilder vs concatenation)
- Palindrome properties
- Anagram properties
- Basic pattern matching intuition (before KMP/Rabin-Karp)

### Question Patterns Asked

**Pattern: Frequency Counting / Hashing on Strings**

- Sub-pattern: Anagram detection & grouping
- Sub-pattern: Character frequency comparison

| Problem                       | Platform | Difficulty |
| ----------------------------- | -------- | ---------- |
| Valid Anagram                 | LeetCode | Easy       |
| Group Anagrams                | LeetCode | Medium     |
| Find All Anagrams in a String | LeetCode | Medium     |
| Ransom Note                   | LeetCode | Easy       |
| Isomorphic Strings            | LeetCode | Easy       |

**Pattern: Palindrome**

- Sub-pattern: Validity check (two pointers)
- Sub-pattern: Longest palindromic substring/subsequence (expand-around-center / DP)
- Sub-pattern: Palindrome partitioning (backtracking)

| Problem                         | Platform | Difficulty |
| ------------------------------- | -------- | ---------- |
| Valid Palindrome                | LeetCode | Easy       |
| Longest Palindromic Substring   | LeetCode | Medium     |
| Palindromic Substrings          | LeetCode | Medium     |
| Longest Palindromic Subsequence | LeetCode | Medium     |
| Palindrome Partitioning         | LeetCode | Medium     |

**Pattern: String Parsing / Simulation**

- Sub-pattern: Expression evaluation
- Sub-pattern: String compression/decompression
- Sub-pattern: Custom tokenizing

| Problem             | Platform | Difficulty |
| ------------------- | -------- | ---------- |
| String Compression  | LeetCode | Medium     |
| Decode String       | LeetCode | Medium     |
| Basic Calculator II | LeetCode | Medium     |
| Zigzag Conversion   | LeetCode | Medium     |
| Multiply Strings    | LeetCode | Medium     |

**Pattern: Pattern Matching (Advanced)**

- Sub-pattern: Substring search
- Sub-pattern: Wildcard/regex matching (usually solved via DP)

| Problem                     | Platform | Difficulty |
| --------------------------- | -------- | ---------- |
| Implement strStr()          | LeetCode | Easy       |
| Repeated String Match       | LeetCode | Medium     |
| Wildcard Matching           | LeetCode | Hard       |
| Regular Expression Matching | LeetCode | Hard       |

### Key Observations

- Anagram checks: sorting gives O(n log n), frequency array gives O(n) — always mention both and justify your choice.
- Longest palindromic substring: expand-around-center is O(n²) with O(1) space and is usually preferred over the DP table approach unless the interviewer explicitly wants DP practice.
- Common mistake: off-by-one errors in two-pointer palindrome checks, and forgetting to handle empty string / single character edge cases.
- KMP and Rabin-Karp are worth understanding conceptually (linear time matching) but are rarely coded from scratch in a 45-minute interview — know when to say "I'd use KMP here" without necessarily implementing it unless asked.

---

## 3. Two Pointers

### Prerequisites

Arrays, Strings

### Concepts to Learn

- Opposite-direction pointers (start/end converging)
- Same-direction pointers (fast/slow)
- Pointer movement conditions based on comparison
- When two pointers requires a sorted array first

### Question Patterns Asked

**Pattern: Opposite-Direction Pointers**

- Sub-pattern: Pair sum in sorted array
- Sub-pattern: Container / area maximization
- Sub-pattern: Palindrome checking

| Problem                            | Platform | Difficulty |
| ---------------------------------- | -------- | ---------- |
| Two Sum II - Input Array Is Sorted | LeetCode | Medium     |
| Container With Most Water          | LeetCode | Medium     |
| Trapping Rain Water                | LeetCode | Hard       |
| 3Sum                               | LeetCode | Medium     |
| 4Sum                               | LeetCode | Medium     |
| Valid Palindrome II                | LeetCode | Easy       |

**Pattern: Same-Direction Pointers**

- Sub-pattern: In-place deduplication
- Sub-pattern: Partitioning by condition

| Problem                             | Platform | Difficulty |
| ----------------------------------- | -------- | ---------- |
| Remove Duplicates from Sorted Array | LeetCode | Easy       |
| Remove Element                      | LeetCode | Easy       |
| Sort Colors                         | LeetCode | Medium     |
| Merge Sorted Array                  | LeetCode | Easy       |
| Squares of a Sorted Array           | LeetCode | Easy       |

**Pattern: Fast & Slow Pointers**

- Sub-pattern: Cycle detection
- Sub-pattern: Middle-of-sequence detection

| Problem                   | Platform | Difficulty |
| ------------------------- | -------- | ---------- |
| Linked List Cycle         | LeetCode | Easy       |
| Find the Duplicate Number | LeetCode | Medium     |
| Middle of the Linked List | LeetCode | Easy       |
| Happy Number              | LeetCode | Easy       |

### Key Observations

- If the array is sorted (or can be sorted without losing needed info) and you're looking for pairs/triplets matching a sum, two pointers beats brute force O(n²)/O(n³).
- 3Sum/4Sum: sort first, fix one/two elements, two-pointer the rest — skip duplicates carefully at each level.
- Common mistake: not skipping duplicate values after finding a valid pair/triplet, leading to duplicate results.
- Fast/slow pointer (Floyd's algorithm) is the standard tool for cycle detection — recognize it instantly when "cycle" or "duplicate within bounded range" is mentioned.

---

## 4. Sliding Window

### Prerequisites

Two Pointers, Hashing

### Concepts to Learn

- Fixed-size window
- Variable-size (expand/shrink) window
- Window state tracking with HashMap/frequency array
- Monotonic deque for window max/min

### Question Patterns Asked

**Pattern: Fixed-Size Window**

- Sub-pattern: Max/min sum or average of size K
- Sub-pattern: Fixed-size anagram/permutation detection

| Problem                       | Platform | Difficulty |
| ----------------------------- | -------- | ---------- |
| Maximum Average Subarray I    | LeetCode | Easy       |
| Permutation in String         | LeetCode | Medium     |
| Find All Anagrams in a String | LeetCode | Medium     |
| Sliding Window Maximum        | LeetCode | Hard       |

**Pattern: Variable-Size Window (Longest/Shortest Subarray)**

- Sub-pattern: Longest substring with constraint (distinct chars, no repeat)
- Sub-pattern: Shortest window satisfying a condition
- Sub-pattern: At-most-K distinct generalization

| Problem                                              | Platform | Difficulty |
| ---------------------------------------------------- | -------- | ---------- |
| Longest Substring Without Repeating Characters       | LeetCode | Medium     |
| Longest Substring with At Most K Distinct Characters | LeetCode | Medium     |
| Minimum Window Substring                             | LeetCode | Hard       |
| Longest Repeating Character Replacement              | LeetCode | Medium     |
| Fruit Into Baskets                                   | LeetCode | Medium     |
| Minimum Size Subarray Sum                            | LeetCode | Medium     |

### Key Observations

- Trigger phrase: "contiguous subarray/substring" + "longest/shortest/max/min" + some constraint → sliding window.
- Variable window pattern: expand right pointer always; shrink left pointer only while the window violates (or satisfies, depending on problem) the constraint.
- Monotonic deque is the go-to for window max/min in O(n) — don't default to a heap (that gives O(n log k)).
- Common mistake: updating the answer at the wrong point in the loop (before vs after shrinking the window), and mishandling window state cleanup when the left pointer moves.

---

## 5. Hashing

### Prerequisites

Arrays, Strings

### Concepts to Learn

- HashMap / HashSet operations and average time complexity
- Collision handling (conceptual understanding)
- Frequency counting
- Using hashing to convert O(n²) brute force into O(n)

### Question Patterns Asked

**Pattern: Existence / Lookup**

- Sub-pattern: Pair/triplet existence
- Sub-pattern: Duplicate detection

| Problem                      | Platform | Difficulty |
| ---------------------------- | -------- | ---------- |
| Two Sum                      | LeetCode | Easy       |
| Contains Duplicate           | LeetCode | Easy       |
| Contains Duplicate II        | LeetCode | Easy       |
| Longest Consecutive Sequence | LeetCode | Medium     |

**Pattern: Frequency-Based Grouping**

- Sub-pattern: Grouping by signature (anagram, sorted key)
- Sub-pattern: Top-K frequent elements

| Problem                      | Platform | Difficulty |
| ---------------------------- | -------- | ---------- |
| Group Anagrams               | LeetCode | Medium     |
| Top K Frequent Elements      | LeetCode | Medium     |
| Sort Characters By Frequency | LeetCode | Medium     |
| Subarray Sum Equals K        | LeetCode | Medium     |

**Pattern: HashMap as State Tracker**

- Sub-pattern: Sliding window with frequency map
- Sub-pattern: Prefix-sum + hashmap combination

| Problem                                                | Platform | Difficulty |
| ------------------------------------------------------ | -------- | ---------- |
| Minimum Window Substring                               | LeetCode | Hard       |
| Longest Substring with At Most Two Distinct Characters | LeetCode | Medium     |
| Continuous Subarray Sum                                | LeetCode | Medium     |
| 4Sum II                                                | LeetCode | Medium     |

### Key Observations

- Any O(n²) brute force involving "does this pair/complement exist" should immediately trigger "can I use a HashMap to make this O(n)?"
- Longest Consecutive Sequence: the trick is to only start counting from a number that has no predecessor in the set — this keeps it O(n) instead of O(n log n).
- Common mistake: not accounting for hashmap iteration order assumptions (don't rely on insertion order unless the language guarantees it), and forgetting to handle integer key collisions when combining two values into one key (use tuples/pairs, not string concatenation with ambiguous separators).

---

## 6. Sorting

### Prerequisites

Arrays

### Concepts to Learn

- Comparison-based sorts: merge sort, quick sort, heap sort — time/space tradeoffs
- Non-comparison sorts: counting sort, bucket sort, radix sort
- Stability of sorting algorithms
- Custom comparators
- When sorting first simplifies a problem (even if not asked directly)

### Question Patterns Asked

**Pattern: Sort Then Process**

- Sub-pattern: Interval problems
- Sub-pattern: Two/three pointer problems requiring sorted input

| Problem                   | Platform | Difficulty |
| ------------------------- | -------- | ---------- |
| Merge Intervals           | LeetCode | Medium     |
| Meeting Rooms II          | LeetCode | Medium     |
| Non-overlapping Intervals | LeetCode | Medium     |
| Largest Number            | LeetCode | Medium     |
| Sort Array By Parity      | LeetCode | Easy       |

**Pattern: Custom Comparator**

- Sub-pattern: Sorting by multiple keys
- Sub-pattern: Sorting for greedy correctness

| Problem                        | Platform | Difficulty |
| ------------------------------ | -------- | ---------- |
| Custom Sort String             | LeetCode | Medium     |
| Queue Reconstruction by Height | LeetCode | Medium     |
| Task Scheduler                 | LeetCode | Medium     |

**Pattern: Counting/Bucket Sort Application**

- Sub-pattern: Sorting bounded-range values
- Sub-pattern: Top-K via bucket sort

| Problem                                       | Platform | Difficulty |
| --------------------------------------------- | -------- | ---------- |
| Sort Colors                                   | LeetCode | Medium     |
| Top K Frequent Elements (bucket sort variant) | LeetCode | Medium     |
| H-Index                                       | LeetCode | Medium     |

### Key Observations

- Know merge sort and quick sort implementation cold — they're occasionally asked to be implemented from scratch, and understanding them helps explain time complexity confidently.
- Many "hard" array/interval problems become trivial after sorting — always ask "does sorting lose information I need?" before ruling it out.
- Common mistake: using an unstable sort when order among equal elements matters, and writing comparators with incorrect sign conventions (causing subtle bugs).

---

## 7. Binary Search

### Prerequisites

Arrays, Sorting

### Concepts to Learn

- Classic binary search on sorted array
- Binary search on answer space (search space reduction)
- Handling duplicates
- Lower bound / upper bound (first/last occurrence)
- Binary search on rotated arrays

### Question Patterns Asked

**Pattern: Classic Search**

- Sub-pattern: Exact target search
- Sub-pattern: First/last occurrence (lower/upper bound)

| Problem                                                 | Platform | Difficulty |
| ------------------------------------------------------- | -------- | ---------- |
| Binary Search                                           | LeetCode | Easy       |
| Find First and Last Position of Element in Sorted Array | LeetCode | Medium     |
| Search Insert Position                                  | LeetCode | Easy       |
| Find Smallest Letter Greater Than Target                | LeetCode | Easy       |

**Pattern: Search on Rotated / Modified Arrays**

- Sub-pattern: Rotated sorted array search
- Sub-pattern: Peak finding
- Sub-pattern: Finding minimum in rotated array

| Problem                              | Platform | Difficulty |
| ------------------------------------ | -------- | ---------- |
| Search in Rotated Sorted Array       | LeetCode | Medium     |
| Find Minimum in Rotated Sorted Array | LeetCode | Medium     |
| Find Peak Element                    | LeetCode | Medium     |
| Search in Rotated Sorted Array II    | LeetCode | Medium     |

**Pattern: Binary Search on Answer**

- Sub-pattern: Minimize the maximum / maximize the minimum
- Sub-pattern: Search over a monotonic decision function

| Problem                                 | Platform | Difficulty |
| --------------------------------------- | -------- | ---------- |
| Koko Eating Bananas                     | LeetCode | Medium     |
| Capacity To Ship Packages Within D Days | LeetCode | Medium     |
| Split Array Largest Sum                 | LeetCode | Hard       |
| Median of Two Sorted Arrays             | LeetCode | Hard       |
| Find K Closest Elements                 | LeetCode | Medium     |

### Key Observations

- Recognition hint: if brute force is "try every possible value and check if it works" and the check function is monotonic (true...true...false...false or vice versa), it's binary search on answer.
- Always decide upfront: are you searching for `mid` itself, or narrowing `[lo, hi]` toward a boundary? Write the loop invariant before coding.
- Common mistake: infinite loops from incorrect `lo`/`hi` updates (e.g., `lo = mid` instead of `lo = mid + 1`), and integer overflow in `mid = (lo + hi) / 2` for languages where this matters (use `lo + (hi - lo) / 2`).

---

## 8. Recursion & Backtracking

### Prerequisites

Arrays, Strings, basic understanding of call stack

### Concepts to Learn

- Base case + recursive case design
- Recursion tree visualization
- Backtracking = recursion + undo (state restoration)
- Pruning to reduce search space
- Time complexity of exponential recursive solutions

### Question Patterns Asked

**Pattern: Subsets / Combinations**

- Sub-pattern: With/without repetition
- Sub-pattern: Fixed-size combinations

| Problem            | Platform | Difficulty |
| ------------------ | -------- | ---------- |
| Subsets            | LeetCode | Medium     |
| Subsets II         | LeetCode | Medium     |
| Combinations       | LeetCode | Medium     |
| Combination Sum    | LeetCode | Medium     |
| Combination Sum II | LeetCode | Medium     |

**Pattern: Permutations**

- Sub-pattern: Distinct elements
- Sub-pattern: Duplicate elements (pruning)

| Problem                 | Platform | Difficulty |
| ----------------------- | -------- | ---------- |
| Permutations            | LeetCode | Medium     |
| Permutations II         | LeetCode | Medium     |
| Letter Case Permutation | LeetCode | Medium     |

**Pattern: Constraint Satisfaction (Grid/Board)**

- Sub-pattern: Placement problems
- Sub-pattern: Path search with backtracking

| Problem       | Platform | Difficulty |
| ------------- | -------- | ---------- |
| N-Queens      | LeetCode | Hard       |
| Sudoku Solver | LeetCode | Hard       |
| Word Search   | LeetCode | Medium     |
| Rat in a Maze | GfG      | Medium     |

**Pattern: String Backtracking**

- Sub-pattern: Partitioning
- Sub-pattern: Generation under constraints

| Problem                               | Platform | Difficulty |
| ------------------------------------- | -------- | ---------- |
| Palindrome Partitioning               | LeetCode | Medium     |
| Generate Parentheses                  | LeetCode | Medium     |
| Letter Combinations of a Phone Number | LeetCode | Medium     |
| Restore IP Addresses                  | LeetCode | Medium     |

### Key Observations

- Draw the recursion tree for at least one problem per sub-pattern by hand before coding — this is where most conceptual gaps are found.
- For duplicate-avoidance in permutations/combinations: sort input first, then skip `nums[i] == nums[i-1]` at the same recursion depth.
- Common mistake: forgetting to backtrack (undo the choice) after the recursive call returns, and mutating shared data structures without copying when adding to the result list (always add a copy of the current state, not a reference).
- Time complexity is usually exponential (2^n or n!) — be ready to state this and explain the branching factor and depth.

---

## 9. Linked List

### Prerequisites

Recursion basics, Two Pointers

### Concepts to Learn

- Singly vs doubly linked list
- Dummy node technique
- In-place reversal
- Fast/slow pointer applications
- Cycle detection and removal

### Question Patterns Asked

**Pattern: Reversal**

- Sub-pattern: Full reversal
- Sub-pattern: Reversal in groups / sublists

| Problem                  | Platform | Difficulty |
| ------------------------ | -------- | ---------- |
| Reverse Linked List      | LeetCode | Easy       |
| Reverse Linked List II   | LeetCode | Medium     |
| Reverse Nodes in k-Group | LeetCode | Hard       |
| Swap Nodes in Pairs      | LeetCode | Medium     |

**Pattern: Fast & Slow Pointer**

- Sub-pattern: Middle node
- Sub-pattern: Cycle detection/removal
- Sub-pattern: Nth node from end

| Problem                          | Platform | Difficulty |
| -------------------------------- | -------- | ---------- |
| Middle of the Linked List        | LeetCode | Easy       |
| Linked List Cycle II             | LeetCode | Medium     |
| Remove Nth Node From End of List | LeetCode | Medium     |
| Palindrome Linked List           | LeetCode | Easy       |

**Pattern: Merging / Restructuring**

- Sub-pattern: Merge sorted lists
- Sub-pattern: Reordering

| Problem                       | Platform | Difficulty |
| ----------------------------- | -------- | ---------- |
| Merge Two Sorted Lists        | LeetCode | Easy       |
| Merge k Sorted Lists          | LeetCode | Hard       |
| Reorder List                  | LeetCode | Medium     |
| Add Two Numbers               | LeetCode | Medium     |
| Copy List with Random Pointer | LeetCode | Medium     |

### Key Observations

- Always consider using a dummy head node — it eliminates edge-case handling for operations at the head of the list.
- Fast/slow pointer: fast moves 2 steps, slow moves 1 — meeting point logic is reused across cycle detection, middle-finding, and "nth from end" problems.
- Common mistake: losing reference to the next node before rewiring pointers during reversal (always save `next` before overwriting `curr.next`), and off-by-one errors in "remove nth from end" using two pointers.

---

## 10. Stack & Queue

### Prerequisites

Arrays, basic recursion (for understanding call stack analogy)

### Concepts to Learn

- LIFO/FIFO behavior
- Monotonic stack/queue
- Stack for expression evaluation and parsing
- Queue for BFS-style processing
- Deque as a hybrid structure

### Question Patterns Asked

**Pattern: Matching / Validity (Bracket-style)**

- Sub-pattern: Balanced parentheses
- Sub-pattern: Minimum removals to balance

| Problem                                  | Platform | Difficulty |
| ---------------------------------------- | -------- | ---------- |
| Valid Parentheses                        | LeetCode | Easy       |
| Min Remove to Make Valid Parentheses     | LeetCode | Medium     |
| Generate Parentheses                     | LeetCode | Medium     |
| Remove All Adjacent Duplicates In String | LeetCode | Easy       |

**Pattern: Monotonic Stack**

- Sub-pattern: Next greater/smaller element
- Sub-pattern: Histogram-based area problems

| Problem                        | Platform | Difficulty |
| ------------------------------ | -------- | ---------- |
| Next Greater Element I         | LeetCode | Easy       |
| Daily Temperatures             | LeetCode | Medium     |
| Largest Rectangle in Histogram | LeetCode | Hard       |
| Trapping Rain Water            | LeetCode | Hard       |
| Online Stock Span              | LeetCode | Medium     |

**Pattern: Expression Evaluation**

- Sub-pattern: Infix/postfix evaluation
- Sub-pattern: Nested structure decoding

| Problem                          | Platform | Difficulty |
| -------------------------------- | -------- | ---------- |
| Evaluate Reverse Polish Notation | LeetCode | Medium     |
| Basic Calculator                 | LeetCode | Hard       |
| Decode String                    | LeetCode | Medium     |

**Pattern: Queue / Deque Usage**

- Sub-pattern: Sliding window max via deque
- Sub-pattern: BFS-style level processing (also see Trees/Graphs)

| Problem                      | Platform | Difficulty |
| ---------------------------- | -------- | ---------- |
| Sliding Window Maximum       | LeetCode | Hard       |
| Design Circular Queue        | LeetCode | Medium     |
| Implement Stack using Queues | LeetCode | Easy       |
| Implement Queue using Stacks | LeetCode | Easy       |

### Key Observations

- Monotonic stack recognition: "next greater/smaller element" or anything about finding the nearest element satisfying a comparison in O(n) → monotonic stack.
- For histogram/rain-water style problems, think in terms of "what's blocking me on the left and right" — this reframes it into a monotonic stack or two-pointer problem.
- Common mistake: pushing/popping the wrong value (index vs actual value) onto the monotonic stack, and not handling the final cleanup pass after the main loop ends (elements still left in the stack).

---

## 11. Trees

### Prerequisites

Recursion, Queue (for BFS)

### Concepts to Learn

- Tree terminology (depth, height, leaf, subtree)
- DFS traversals: preorder, inorder, postorder (recursive and iterative)
- BFS / level-order traversal
- Recursive tree construction
- Diameter, balance, and height computation patterns

### Question Patterns Asked

**Pattern: Traversal**

- Sub-pattern: DFS (recursive/iterative)
- Sub-pattern: BFS / level order
- Sub-pattern: Vertical/boundary/zigzag traversal

| Problem                                   | Platform | Difficulty |
| ----------------------------------------- | -------- | ---------- |
| Binary Tree Inorder Traversal             | LeetCode | Easy       |
| Binary Tree Level Order Traversal         | LeetCode | Medium     |
| Binary Tree Zigzag Level Order Traversal  | LeetCode | Medium     |
| Binary Tree Right Side View               | LeetCode | Medium     |
| Vertical Order Traversal of a Binary Tree | LeetCode | Hard       |

**Pattern: Tree Properties / Metrics**

- Sub-pattern: Height/depth calculation
- Sub-pattern: Diameter
- Sub-pattern: Balance checking

| Problem                      | Platform | Difficulty |
| ---------------------------- | -------- | ---------- |
| Maximum Depth of Binary Tree | LeetCode | Easy       |
| Diameter of Binary Tree      | LeetCode | Easy       |
| Balanced Binary Tree         | LeetCode | Easy       |
| Symmetric Tree               | LeetCode | Easy       |

**Pattern: Path-Based Problems**

- Sub-pattern: Root-to-leaf paths
- Sub-pattern: Path sum variants
- Sub-pattern: Maximum path sum (any node to any node)

| Problem                      | Platform | Difficulty |
| ---------------------------- | -------- | ---------- |
| Path Sum                     | LeetCode | Easy       |
| Path Sum II                  | LeetCode | Medium     |
| Binary Tree Maximum Path Sum | LeetCode | Hard       |
| Sum Root to Leaf Numbers     | LeetCode | Medium     |

**Pattern: Construction / Serialization**

- Sub-pattern: Build tree from traversals
- Sub-pattern: Serialize/deserialize

| Problem                                                   | Platform | Difficulty |
| --------------------------------------------------------- | -------- | ---------- |
| Construct Binary Tree from Preorder and Inorder Traversal | LeetCode | Medium     |
| Serialize and Deserialize Binary Tree                     | LeetCode | Hard       |
| Populating Next Right Pointers in Each Node               | LeetCode | Medium     |

**Pattern: Lowest Common Ancestor (LCA)**

- Sub-pattern: General binary tree LCA
- Sub-pattern: BST-specific LCA (see BST section)

| Problem                                     | Platform | Difficulty |
| ------------------------------------------- | -------- | ---------- |
| Lowest Common Ancestor of a Binary Tree     | LeetCode | Medium     |
| Lowest Common Ancestor of a Binary Tree III | LeetCode | Medium     |

### Key Observations

- Most tree problems reduce to "what do I compute at this node using results from left and right subtrees" — always define what a recursive call returns before writing code.
- Diameter and max path sum both use the same trick: compute a value to return upward (height) while updating a global/outer answer using both subtrees combined.
- Common mistake: confusing "path" (must be a straight line without branching) with "any connected route," and not handling `null`/`None` nodes explicitly in recursive base cases.

---

## 12. Binary Search Trees (BST)

### Prerequisites

Trees, Binary Search

### Concepts to Learn

- BST property (left < node < right)
- Inorder traversal gives sorted order
- Insertion/deletion maintaining BST property
- Validating BST
- Self-balancing BSTs (conceptual: AVL, Red-Black — rarely implemented, just know they exist)

### Question Patterns Asked

**Pattern: Validation & Search**

- Sub-pattern: Validity checking
- Sub-pattern: Search/insert/delete operations

| Problem                          | Platform | Difficulty |
| -------------------------------- | -------- | ---------- |
| Search in a Binary Search Tree   | LeetCode | Easy       |
| Validate Binary Search Tree      | LeetCode | Medium     |
| Insert into a Binary Search Tree | LeetCode | Medium     |
| Delete Node in a BST             | LeetCode | Medium     |

**Pattern: Order Statistics**

- Sub-pattern: Kth smallest/largest
- Sub-pattern: Closest value queries

| Problem                          | Platform | Difficulty |
| -------------------------------- | -------- | ---------- |
| Kth Smallest Element in a BST    | LeetCode | Medium     |
| Closest Binary Search Tree Value | LeetCode | Easy       |
| Two Sum IV - Input is a BST      | LeetCode | Easy       |

**Pattern: Structural / LCA**

- Sub-pattern: LCA using BST property
- Sub-pattern: BST construction/conversion

| Problem                                        | Platform | Difficulty |
| ---------------------------------------------- | -------- | ---------- |
| Lowest Common Ancestor of a Binary Search Tree | LeetCode | Medium     |
| Convert Sorted Array to Binary Search Tree     | LeetCode | Easy       |
| Balance a Binary Search Tree                   | LeetCode | Medium     |
| Recover Binary Search Tree                     | LeetCode | Medium     |

### Key Observations

- Inorder traversal of a BST always yields sorted order — this single fact solves validation, kth-smallest, and many "closest value" problems elegantly.
- BST LCA is simpler than general tree LCA: use the property that the split point where the target values diverge (one less, one greater) than the current node is the LCA — no need for full traversal.
- Common mistake: validating a BST using only immediate parent-child comparison instead of tracking a valid `(min, max)` range for each subtree.

---

## 13. Heaps / Priority Queue

### Prerequisites

Trees, Arrays

### Concepts to Learn

- Min-heap vs max-heap
- Heapify operation and complexity
- Using heaps for top-K problems
- Two-heap technique for median-finding
- Custom comparator heaps

### Question Patterns Asked

**Pattern: Top-K Elements**

- Sub-pattern: Kth largest/smallest
- Sub-pattern: K closest elements

| Problem                         | Platform | Difficulty |
| ------------------------------- | -------- | ---------- |
| Kth Largest Element in an Array | LeetCode | Medium     |
| Top K Frequent Elements         | LeetCode | Medium     |
| K Closest Points to Origin      | LeetCode | Medium     |
| Kth Largest Element in a Stream | LeetCode | Easy       |

**Pattern: Two-Heap Technique**

- Sub-pattern: Running median
- Sub-pattern: Balancing two halves of a dataset

| Problem                      | Platform | Difficulty |
| ---------------------------- | -------- | ---------- |
| Find Median from Data Stream | LeetCode | Hard       |
| Sliding Window Median        | LeetCode | Hard       |
| IPO                          | LeetCode | Hard       |

**Pattern: Merge / Scheduling with Heap**

- Sub-pattern: Merging k sorted structures
- Sub-pattern: Task/meeting scheduling

| Problem              | Platform | Difficulty |
| -------------------- | -------- | ---------- |
| Merge k Sorted Lists | LeetCode | Hard       |
| Task Scheduler       | LeetCode | Medium     |
| Meeting Rooms II     | LeetCode | Medium     |
| Reorganize String    | LeetCode | Medium     |

### Key Observations

- Recognition hint: "kth largest/smallest," "top K," "closest K," or "continuously find min/max while inserting" almost always means heap.
- Two-heap technique (max-heap for smaller half, min-heap for larger half) is the standard solution for streaming median problems — memorize the balancing invariant.
- Common mistake: using a heap of size n when only a heap of size K is needed (blows up to O(n log n) instead of O(n log k)), and forgetting most languages' built-in heap is a min-heap by default (negate values for max-heap behavior if needed).

---

## 14. Tries

### Prerequisites

Trees, Strings, HashMap

### Concepts to Learn

- Trie node structure (children map/array + end-of-word flag)
- Insertion, search, prefix search
- Space-time tradeoffs vs HashMap for string problems
- Trie combined with DFS/backtracking

### Question Patterns Asked

**Pattern: Core Trie Operations**

- Sub-pattern: Insert/search/startsWith
- Sub-pattern: Word dictionary with wildcard search

| Problem                                    | Platform | Difficulty |
| ------------------------------------------ | -------- | ---------- |
| Implement Trie (Prefix Tree)               | LeetCode | Medium     |
| Design Add and Search Words Data Structure | LeetCode | Medium     |
| Replace Words                              | LeetCode | Medium     |

**Pattern: Trie + Search/Backtracking**

- Sub-pattern: Word search on a grid using trie pruning
- Sub-pattern: Auto-complete style suggestions

| Problem                           | Platform | Difficulty |
| --------------------------------- | -------- | ---------- |
| Word Search II                    | LeetCode | Hard       |
| Design Search Autocomplete System | LeetCode | Hard       |
| Longest Word in Dictionary        | LeetCode | Medium     |

### Key Observations

- Use a trie when the problem repeatedly needs prefix-based lookups — a plain HashSet can't answer "does any word start with this prefix" efficiently.
- Word Search II is the classic "trie + backtracking + pruning" problem — build the trie from the word list first, then DFS the grid while pruning branches that don't exist in the trie.
- Common mistake: not marking end-of-word properly (causing prefixes to be misidentified as complete words), and building a fresh trie unnecessarily inside a loop instead of once upfront.

---

## 15. Graphs

### Prerequisites

Trees (as a special case of graphs), Queue, Stack, Recursion

### Concepts to Learn

- Representations: adjacency list vs adjacency matrix
- BFS and DFS traversal (and when to use which)
- Connected components
- Topological sort (Kahn's algorithm and DFS-based)
- Union-Find (Disjoint Set Union) with path compression and union by rank
- Shortest path algorithms: BFS (unweighted), Dijkstra (weighted, non-negative), Bellman-Ford (negative weights)
- Cycle detection (directed vs undirected)
- Minimum Spanning Tree (Kruskal's, Prim's) — conceptual awareness

### Question Patterns Asked

**Pattern: Traversal / Connected Components**

- Sub-pattern: Number of islands / connected regions
- Sub-pattern: Flood fill style problems

| Problem                                               | Platform | Difficulty |
| ----------------------------------------------------- | -------- | ---------- |
| Number of Islands                                     | LeetCode | Medium     |
| Flood Fill                                            | LeetCode | Easy       |
| Number of Connected Components in an Undirected Graph | LeetCode | Medium     |
| Max Area of Island                                    | LeetCode | Medium     |
| Surrounded Regions                                    | LeetCode | Medium     |

**Pattern: Topological Sort**

- Sub-pattern: Dependency resolution
- Sub-pattern: Cycle detection in directed graphs

| Problem                 | Platform | Difficulty |
| ----------------------- | -------- | ---------- |
| Course Schedule         | LeetCode | Medium     |
| Course Schedule II      | LeetCode | Medium     |
| Alien Dictionary        | LeetCode | Hard       |
| Sequence Reconstruction | LeetCode | Medium     |

**Pattern: Shortest Path**

- Sub-pattern: Unweighted (BFS)
- Sub-pattern: Weighted, non-negative (Dijkstra)
- Sub-pattern: Weighted with negative edges (Bellman-Ford)

| Problem                         | Platform | Difficulty |
| ------------------------------- | -------- | ---------- |
| Shortest Path in Binary Matrix  | LeetCode | Medium     |
| Rotting Oranges                 | LeetCode | Medium     |
| Network Delay Time              | LeetCode | Medium     |
| Cheapest Flights Within K Stops | LeetCode | Medium     |
| Path With Minimum Effort        | LeetCode | Medium     |

**Pattern: Union-Find (Disjoint Set Union)**

- Sub-pattern: Connectivity queries
- Sub-pattern: Cycle detection in undirected graphs
- Sub-pattern: Kruskal's MST

| Problem              | Platform | Difficulty |
| -------------------- | -------- | ---------- |
| Number of Provinces  | LeetCode | Medium     |
| Redundant Connection | LeetCode | Medium     |
| Accounts Merge       | LeetCode | Medium     |
| Number of Islands II | LeetCode | Hard       |

**Pattern: Multi-Source BFS**

- Sub-pattern: Simultaneous spreading from multiple origins

| Problem         | Platform | Difficulty |
| --------------- | -------- | ---------- |
| Rotting Oranges | LeetCode | Medium     |
| Walls and Gates | LeetCode | Medium     |
| 01 Matrix       | LeetCode | Medium     |

### Key Observations

- Recognition hint: grid-based "count regions / spread / shortest reachability" → BFS/DFS on an implicit graph where each cell is a node.
- Topological sort recognition: "dependencies," "prerequisites," "build order," "must happen before" → topological sort; a cycle means no valid ordering exists.
- Union-Find is preferred over BFS/DFS when the problem involves incremental connectivity queries (edges added one at a time) rather than a static graph.
- Common mistake: forgetting to mark nodes visited before enqueueing (not just before processing) in BFS, causing duplicate processing; and not handling disconnected components when a single traversal isn't guaranteed to cover the whole graph.

---

## 16. Dynamic Programming

### Prerequisites

Recursion & Backtracking, Arrays

### Concepts to Learn

- Overlapping subproblems + optimal substructure
- Memoization (top-down) vs tabulation (bottom-up)
- State definition — the most important DP skill
- Dimensionality reduction (rolling array optimization)
- Common DP shapes: 1D, 2D grid, interval, subsequence, knapsack, digit DP (advanced/optional)

### Question Patterns Asked

**Pattern: 1D DP**

- Sub-pattern: Climbing stairs style (Fibonacci-like recurrence)
- Sub-pattern: House robber style (include/exclude choice)

| Problem          | Platform | Difficulty |
| ---------------- | -------- | ---------- |
| Climbing Stairs  | LeetCode | Easy       |
| House Robber     | LeetCode | Medium     |
| House Robber II  | LeetCode | Medium     |
| Decode Ways      | LeetCode | Medium     |
| Maximum Subarray | LeetCode | Easy       |

**Pattern: Knapsack Family**

- Sub-pattern: 0/1 Knapsack
- Sub-pattern: Unbounded Knapsack
- Sub-pattern: Subset-sum / partition variants

| Problem                    | Platform | Difficulty |
| -------------------------- | -------- | ---------- |
| Partition Equal Subset Sum | LeetCode | Medium     |
| Target Sum                 | LeetCode | Medium     |
| Coin Change                | LeetCode | Medium     |
| Coin Change II             | LeetCode | Medium     |
| Combination Sum IV         | LeetCode | Medium     |

**Pattern: 2D Grid DP**

- Sub-pattern: Path counting
- Sub-pattern: Path with min/max cost

| Problem          | Platform | Difficulty |
| ---------------- | -------- | ---------- |
| Unique Paths     | LeetCode | Medium     |
| Unique Paths II  | LeetCode | Medium     |
| Minimum Path Sum | LeetCode | Medium     |
| Dungeon Game     | LeetCode | Hard       |

**Pattern: Subsequence / Substring DP**

- Sub-pattern: Longest common subsequence family
- Sub-pattern: Longest increasing subsequence family
- Sub-pattern: Edit distance family

| Problem                         | Platform | Difficulty |
| ------------------------------- | -------- | ---------- |
| Longest Common Subsequence      | LeetCode | Medium     |
| Longest Increasing Subsequence  | LeetCode | Medium     |
| Edit Distance                   | LeetCode | Hard       |
| Distinct Subsequences           | LeetCode | Hard       |
| Longest Palindromic Subsequence | LeetCode | Medium     |

**Pattern: Interval DP**

- Sub-pattern: Optimal split/merge over a range

| Problem                      | Platform | Difficulty |
| ---------------------------- | -------- | ---------- |
| Burst Balloons               | LeetCode | Hard       |
| Matrix Chain Multiplication  | GfG      | Hard       |
| Palindrome Partitioning II   | LeetCode | Hard       |
| Minimum Cost to Merge Stones | LeetCode | Hard       |

**Pattern: DP on Trees/Graphs (Advanced Bridge Topic)**

- Sub-pattern: Combining subtree states

| Problem                                         | Platform | Difficulty |
| ----------------------------------------------- | -------- | ---------- |
| House Robber III                                | LeetCode | Medium     |
| Binary Tree Maximum Path Sum                    | LeetCode | Hard       |
| Longest Path With Different Adjacent Characters | LeetCode | Hard       |

### Key Observations

- The single most important step is defining the state clearly in words before writing any code: "dp[i] represents \_\_\_." If you can't state it in one sentence, you're not ready to code it.
- Always write the brute-force recursive solution first, identify overlapping subproblems, then add memoization — don't jump straight to a tabulated bottom-up array.
- Common mistake: incorrect base case initialization (especially in knapsack/grid DP with boundary rows/columns), and confusing "subsequence" (non-contiguous, order preserved) with "substring/subarray" (contiguous) — they require different DP formulations entirely.
- Space optimization (reducing 2D DP to 1D rolling array) is a strong signal of maturity — mention it even if you don't fully implement it under time pressure.

---

## 17. Greedy Algorithms

### Prerequisites

Sorting, Intervals, basic proof intuition

### Concepts to Learn

- Greedy choice property and how to argue correctness informally
- Exchange argument (conceptual)
- When greedy fails and DP is needed instead
- Common greedy building blocks: sort by end time, sort by ratio, earliest deadline first

### Question Patterns Asked

**Pattern: Interval Scheduling**

- Sub-pattern: Maximum non-overlapping intervals
- Sub-pattern: Minimum resources needed

| Problem                                    | Platform | Difficulty |
| ------------------------------------------ | -------- | ---------- |
| Non-overlapping Intervals                  | LeetCode | Medium     |
| Minimum Number of Arrows to Burst Balloons | LeetCode | Medium     |
| Meeting Rooms                              | LeetCode | Easy       |
| Meeting Rooms II                           | LeetCode | Medium     |

**Pattern: Resource Allocation / Optimization**

- Sub-pattern: Assignment problems
- Sub-pattern: Jump/reachability games

| Problem        | Platform | Difficulty |
| -------------- | -------- | ---------- |
| Jump Game      | LeetCode | Medium     |
| Jump Game II   | LeetCode | Medium     |
| Gas Station    | LeetCode | Medium     |
| Candy          | LeetCode | Hard       |
| Assign Cookies | LeetCode | Easy       |

**Pattern: String / Array Greedy Construction**

- Sub-pattern: Building an optimal sequence greedily

| Problem                  | Platform | Difficulty |
| ------------------------ | -------- | ---------- |
| Partition Labels         | LeetCode | Medium     |
| Remove Duplicate Letters | LeetCode | Medium     |
| Reorganize String        | LeetCode | Medium     |
| Boats to Save People     | LeetCode | Medium     |

### Key Observations

- Greedy problems almost always start with sorting by some key (end time, ratio, deadline) — figuring out the right sort key is 80% of the problem.
- Before committing to greedy, sanity-check with a small counterexample — if a locally optimal choice can be shown to break a later constraint, it's likely a DP problem instead.
- Common mistake: assuming greedy works without justification and getting it wrong on edge cases — always mentally verify with 2-3 test cases including edge cases (empty input, all same values).

---

## 18. Bit Manipulation

### Prerequisites

Basic number systems (binary representation)

### Concepts to Learn

- AND, OR, XOR, NOT, shifts
- XOR properties (self-cancelling, identity)
- Bit masking for subset generation
- Counting set bits (Brian Kernighan's algorithm)
- Checking power of two, isolating lowest set bit

### Question Patterns Asked

**Pattern: XOR-Based Tricks**

- Sub-pattern: Single/unique number detection
- Sub-pattern: Missing number detection

| Problem           | Platform | Difficulty |
| ----------------- | -------- | ---------- |
| Single Number     | LeetCode | Easy       |
| Single Number II  | LeetCode | Medium     |
| Single Number III | LeetCode | Medium     |
| Missing Number    | LeetCode | Easy       |

**Pattern: Counting / Manipulating Bits**

- Sub-pattern: Counting set bits
- Sub-pattern: Bit reversal

| Problem          | Platform | Difficulty |
| ---------------- | -------- | ---------- |
| Number of 1 Bits | LeetCode | Easy       |
| Counting Bits    | LeetCode | Easy       |
| Reverse Bits     | LeetCode | Easy       |
| Power of Two     | LeetCode | Easy       |

**Pattern: Bitmask for Subsets/DP**

- Sub-pattern: Subset enumeration via bitmask
- Sub-pattern: Bitmask DP (advanced)

| Problem                          | Platform | Difficulty |
| -------------------------------- | -------- | ---------- |
| Subsets                          | LeetCode | Medium     |
| Sum of Two Integers              | LeetCode | Medium     |
| Partition to K Equal Sum Subsets | LeetCode | Medium     |

### Key Observations

- XOR of a number with itself is 0, and with 0 is itself — this single property solves most "find the unique element" problems in O(n) time, O(1) space.
- Bitmask DP is an advanced technique typically reserved for problems with small n (n ≤ 20) where a state needs to represent "which subset of elements has been used."
- Common mistake: forgetting operator precedence issues (e.g., `&` vs `==` precedence in some languages), and not handling negative numbers correctly under bitwise operations (two's complement behavior).

---

## 19. Intervals

### Prerequisites

Sorting, Greedy

### Concepts to Learn

- Representing and sorting intervals (by start or end)
- Merging overlapping intervals
- Interval intersection
- Sweep line technique

### Question Patterns Asked

**Pattern: Merging / Insertion**

- Sub-pattern: Merge overlapping intervals
- Sub-pattern: Insert new interval into sorted list

| Problem            | Platform | Difficulty |
| ------------------ | -------- | ---------- |
| Merge Intervals    | LeetCode | Medium     |
| Insert Interval    | LeetCode | Medium     |
| Employee Free Time | LeetCode | Hard       |

**Pattern: Intersection / Overlap Counting**

- Sub-pattern: Pairwise intersection
- Sub-pattern: Overlap counting (sweep line)

| Problem                     | Platform | Difficulty |
| --------------------------- | -------- | ---------- |
| Interval List Intersections | LeetCode | Medium     |
| Meeting Rooms II            | LeetCode | Medium     |
| My Calendar I               | LeetCode | Medium     |
| Car Pooling                 | LeetCode | Medium     |

### Key Observations

- Sort by start time for merging problems, but sort by end time for scheduling/greedy selection problems — mixing these up is a very common source of bugs.
- The sweep line technique (treat interval starts as +1 events and ends as -1 events, then scan chronologically) elegantly solves "max overlapping intervals at any point" problems.
- Common mistake: off-by-one errors when intervals are inclusive vs exclusive on the boundary (`[1,3]` and `[3,5]` — do they overlap or not? — always clarify with the interviewer).

---

## 20. Final Revision Strategy

Once all topics above are covered, structure your last phase of preparation as follows:

1. **Pattern flashcards** — for each pattern name in this document, be able to state the recognition trigger and core idea in under 15 seconds without looking anything up.
2. **Timed mixed practice** — solve problems from a shuffled mix of topics (not grouped by pattern) to simulate real interview conditions, where you don't know the pattern in advance.
3. **Mock interviews** — practice explaining your approach out loud before coding, including time/space complexity, for every problem you attempt in this phase.
4. **Weak-topic drilling** — maintain a running list of problems you got wrong or were slow on; revisit them after a few days rather than immediately, to test true retention.
5. **Company-specific problem sets** — once comfortable, search for previously-asked questions at your target companies (via LeetCode's company tag feature or similar) and prioritize those patterns.

---

_End of Handbook._
