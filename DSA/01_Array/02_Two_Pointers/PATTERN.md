| Pattern                 | Recognition Clues                         | Complexity                 | Common Tricks                 | Frequently Asked Companies |
| ----------------------- | ----------------------------------------- | -------------------------- | ----------------------------- | -------------------------- |
| Opposite Direction      | Sorted array, pair search, palindrome     | O(n)                       | Move left/right intelligently | Google, Amazon, Microsoft  |
| Same Direction          | Remove elements, overwrite, deduplication | O(n)                       | Slow writes, fast scans       | Amazon, Adobe, Walmart     |
| Pair Sum                | Need exactly 2 numbers                    | O(n) sorted / O(n) hashmap | Sort vs HashMap tradeoff      | Meta, Uber                 |
| Three Sum               | Need triplets                             | O(n²)                      | Sort + fix one + pair sum     | Google, Amazon             |
| Four Sum / K Sum        | Need quadruplets or generalized K numbers | O(n³) / recursion          | Reduce to Two Sum recursively | Google, Atlassian          |
| Deduplication           | Remove duplicates                         | O(n)                       | Write pointer                 | Amazon                     |
| Remove / Overwrite      | Remove value in-place                     | O(n)                       | Stable overwrite              | Microsoft                  |
| Dutch National Flag     | Three categories                          | O(n)                       | Three pointers                | Google                     |
| Partitioning            | Pivot based rearrangement                 | O(n)                       | Lomuto/Hoare style            | Amazon                     |
| Container Pattern       | Max area between boundaries               | O(n)                       | Greedy pointer movement       | Google                     |
| Trapping Water          | Water accumulation                        | O(n)                       | Smaller boundary decides      | Meta                       |
| Fast & Slow Pointer     | Cycle, middle node                        | O(n)                       | Floyd Algorithm               | Amazon                     |
| Merge Pattern           | Merge sorted arrays/lists                 | O(n+m)                     | Compare fronts                | Microsoft                  |
| Palindrome Validation   | Compare ends                              | O(n)                       | Skip invalid chars            | Meta                       |
| Linked List Two Pointer | Cycle, intersection, nth node             | O(n)                       | Distance maintenance          | Google                     |

Two pointer revision plan · MD

# Two Pointer Mastery — 4-Day Revision Plan (3rd Pass)

**For: Product-based SDE interviews (Google, Amazon, Microsoft, Atlassian, Uber, Adobe, Walmart Global Tech, Goldman Sachs, JPMorgan, Morgan Stanley, Flipkart, PhonePe)**

This is a curated, non-redundant set of 24 problems. Every problem earns its slot by teaching a distinct sub-pattern or combining two sub-patterns in a way interviewers actually test. No filler.

---

## PART 1 — Two Pointer Sub-Patterns

### 1. Opposite Direction (Converging Pointers)

- **Recognition clues:** Array is sorted (or can be treated as sorted), you need a pair/condition involving both ends, you're checking symmetry.
- **Time complexity:** O(n)
- **Tricks:** Move the pointer that "hurts" you — e.g., in container problems always move the shorter wall; in pair-sum move left if sum too small, right if sum too large. Never move both blindly.
- **Companies:** Amazon, Google, Microsoft, Adobe — extremely common as warm-up or sub-routine inside harder DP/greedy questions.

### 2. Same Direction (Slow-Fast Read/Write)

- **Recognition clues:** "In-place," "remove element," "overwrite," array/string compaction without extra space.
- **Time complexity:** O(n)
- **Tricks:** `slow` = write pointer (next valid position), `fast` = scan pointer. The invariant is "everything before `slow` is already correct." Off-by-one at boundaries is the #1 bug source.
- **Companies:** Amazon, Microsoft, Flipkart — classic "in-place array manipulation" round.

### 3. Fast & Slow Pointer (Floyd's Cycle Detection)

- **Recognition clues:** Linked list, "find middle," "detect cycle," "find duplicate number in array (as implicit linked list)."
- **Time complexity:** O(n), O(1) space
- **Tricks:** `slow` moves 1 step, `fast` moves 2. For "find cycle start," after they meet, reset one pointer to head and move both 1 step at a time — meeting point is the cycle start (math: distance from head to cycle start == distance from meeting point to cycle start along the cycle).
- **Companies:** Microsoft, Amazon, Adobe, Goldman Sachs — a linked-list round staple.

### 4. Dutch National Flag (3-Way Partitioning)

- **Recognition clues:** "Sort an array of only 3 distinct values," "partition around a pivot without extra space," "segregate 0s/1s/2s."
- **Time complexity:** O(n), single pass
- **Tricks:** Three pointers — `low`, `mid`, `high`. When you swap with `high`, do NOT advance `mid` (the swapped-in element is unexamined). When you swap with `low`, you CAN advance `mid` (swapped-in element was already `mid`-processed range).
- **Companies:** Google, Amazon, Morgan Stanley — often disguised as "partition array" or "segregate even/odd."

### 5. Pair Sum (Sorted Array)

- **Recognition clues:** "Find a pair that sums to target," array is sorted.
- **Time complexity:** O(n) vs O(n) space+time hashmap alternative — interviewers want you to justify why two-pointer beats hashing here (O(1) space, and sortedness is free info you should use).
- **Companies:** Every company — this is the "can you even do two pointer" filter question.

### 6. Triplet Sum (3Sum family)

- **Recognition clues:** "Find triplets/three numbers," sum/target condition, need to avoid duplicate triplets.
- **Time complexity:** O(n²) after O(n log n) sort
- **Tricks:** Fix one pointer via loop, two-pointer the rest. Skip duplicates at ALL THREE positions carefully. `3Sum Closest` and `3Sum Smaller` reuse the exact skeleton — this is why mastering one 3Sum gives you three problems for free.
- **Companies:** Amazon, Google, Adobe, Flipkart — one of the top 5 most-repeated interview questions across all companies.

### 7. K-Sum Generalization (4Sum and beyond)

- **Recognition clues:** "Find k numbers summing to target."
- **Time complexity:** O(n^(k-1)) — two nested loops to fix k-2 elements, then two-pointer on remainder.
- **Tricks:** Recursive/generalized kSum reduces to 2Sum base case. Prune with sorted-array bounds checks (`nums[i]*k > target` etc.) to avoid TLE.
- **Companies:** Google, Amazon — often asked as a follow-up: "now generalize to k."

### 8. Container / Area Maximization

- **Recognition clues:** "Maximum area/volume between two lines/walls," array represents heights.
- **Time complexity:** O(n)
- **Tricks:** Greedy proof — moving the taller pointer can never increase area (width shrinks, height is capped by the shorter one anyway), so always move the shorter wall. Interviewers frequently ask you to _prove_ this greedy choice.
- **Companies:** Amazon, Google, Uber — classic greedy + two pointer hybrid.

### 9. Trapping Rain Water

- **Recognition clues:** "Water trapped between bars," elevation map.
- **Time complexity:** O(n), O(1) space (two-pointer version beats the O(n) prefix-max/suffix-max array approach)
- **Tricks:** Maintain `leftMax`, `rightMax`. Move the pointer with the smaller max — water at that position is bounded by that smaller max. This is the single most important "prove you understand WHY two pointer beats brute force" question.
- **Companies:** Google, Amazon, Adobe, Goldman Sachs — a top-tier "hard" bar-raiser question.

### 10. Merge Pattern

- **Recognition clues:** "Merge two sorted arrays/lists," in-place merge.
- **Time complexity:** O(m+n)
- **Tricks:** For in-place array merge (LC 88 style), merge from the BACK to avoid overwriting unprocessed elements — this "merge from the end" trick is a favorite interview twist.
- **Companies:** Microsoft, Amazon — foundational, also appears inside merge sort / external sorting discussions.

### 11. Deduplication Pattern

- **Recognition clues:** "Remove duplicates in-place," "allow at most k duplicates."
- **Time complexity:** O(n)
- **Tricks:** Generalize with a counter check: `nums[write] = nums[read]` only if `nums[write - k] != nums[read]`. This single trick solves "at most 1 dup," "at most 2 dups," "remove all dups" uniformly — a strong thing to say out loud in an interview.
- **Companies:** Amazon, Flipkart — common warm-up.

### 12. Linked List Two Pointer (Offset / Gap Technique)

- **Recognition clues:** "Nth node from end," "intersection of two lists," "middle without length count."
- **Time complexity:** O(n), single pass, O(1) space
- **Tricks:** For "nth from end," advance one pointer n steps first, then move both together. For "intersection," switch each pointer to the other list's head when it hits null — they meet at the intersection or both hit null simultaneously (elegant length-equalization trick).
- **Companies:** Microsoft, Amazon, Adobe — classic linked-list round question.

### 13. Palindrome Validation

- **Recognition clues:** "Check if array/string/linked list is palindrome," ignoring non-alphanumeric, case-insensitive.
- **Time complexity:** O(n)
- **Tricks:** For strings — skip non-alphanumeric with a `while` inside the main loop (don't use extra passes to clean the string). For linked lists — combine fast/slow (find middle) + reverse second half + compare (this is why LC 234 is a capstone).
- **Companies:** Amazon, Microsoft, Google — very common, especially the linked-list variant.

### 14. Partitioning / Greedy Opposite-Direction

- **Recognition clues:** "Rearrange array so condition X holds using minimum operations," "pair elements to satisfy a constraint," boats/capacity problems.
- **Time complexity:** O(n log n) (sort) + O(n)
- **Tricks:** Sort first, then greedily pair smallest with largest. Recognizing "this is secretly two-pointer + greedy" is the hard part — the problem rarely says "array" explicitly.
- **Companies:** Amazon, Uber, Goldman Sachs — appears in "resource allocation" style word problems.

---

## PART 2 — The 24-Question, 4-Day Plan

### DAY 1 — Foundations: Opposite Direction + Same Direction

_Goal: Re-anchor pointer-movement invariants before layering complexity._

**1. Valid Palindrome**

- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/valid-palindrome/
- Sub-pattern: Opposite Direction / Palindrome Validation
- Why it matters: Cleanest intro to converging pointers with a skip-condition — sets up LC 234 later.
- Frequency: High
- Companies: Amazon, Microsoft, Google, Adobe
- Prerequisites: None
- Similar: Valid Palindrome II (LC 680), Palindrome Linked List (Day 3)
  **2. Two Sum II – Input Array Is Sorted**
- Platform/Difficulty: LeetCode — Medium (Easy in practice)
- Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
- Sub-pattern: Pair Sum
- Why it matters: The atomic building block for 3Sum/4Sum — if this isn't instant, stop and drill it before moving on.
- Frequency: High
- Companies: Amazon, Google, JPMorgan, Flipkart
- Prerequisites: None
- Similar: Two Sum (hashmap version), 3Sum
  **3. Squares of a Sorted Array**
- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/squares-of-a-sorted-array/
- Sub-pattern: Opposite Direction (merge-style)
- Why it matters: Forces you to reason about pointers converging while writing to a _third_ array from the back — a distinct trick from pure pair-sum.
- Frequency: Medium
- Companies: Amazon, Microsoft
- Prerequisites: Q1–Q2
- Similar: Merge Sorted Array (Day 4)
  **4. Move Zeroes**
- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/move-zeroes/
- Sub-pattern: Same Direction / Overwrite
- Why it matters: Cleanest slow-fast write-pointer intro; the invariant here recurs in every dedup problem.
- Frequency: High
- Companies: Amazon, Microsoft, Bloomberg
- Prerequisites: None
- Similar: Remove Element (LC 27), Sort Array By Parity (Day 4)
  **5. Remove Duplicates from Sorted Array**
- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
- Sub-pattern: Same Direction / Deduplication
- Why it matters: The base case of the "allow k duplicates" generalization used in Q11 (Day 2).
- Frequency: High
- Companies: Amazon, Microsoft, Flipkart
- Prerequisites: Q4
- Similar: Remove Duplicates from Sorted Array II (Day 2)
  **6. Container With Most Water**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/container-with-most-water/
- Sub-pattern: Opposite Direction / Container Maximization
- Why it matters: First "prove the greedy" question. If you can't articulate WHY moving the shorter wall is safe, you're not ready for Trapping Rain Water on Day 4.
- Frequency: High
- Companies: Amazon, Google, Uber, Adobe
- Prerequisites: Q1–Q2
- Similar: Trapping Rain Water (Day 4)

---

### DAY 2 — Sorting-Driven Multi-Pointer: Dutch Flag + Triplet/K-Sum Family

_Goal: Layer a third (and fourth) moving reference on top of Day 1's converging-pointer instincts._

**7. Sort Colors**

- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/sort-colors/
- Sub-pattern: Dutch National Flag
- Why it matters: Only 3-pointer partitioning problem in the set — the "don't advance mid on high-swap" subtlety is a favorite interviewer trap.
- Frequency: High
- Companies: Google, Amazon, Morgan Stanley
- Prerequisites: Day 1 completed
- Similar: Sort Array By Parity (Day 4), 3-way partition in quicksort
  **8. 3Sum**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/3sum/
- Sub-pattern: Triplet Sum
- Why it matters: THE most-repeated two-pointer question industry-wide. Master the "fix i, two-pointer j/k, skip-duplicates at all 3 positions" skeleton — everything else today reuses it.
- Frequency: High
- Companies: Amazon, Google, Adobe, Flipkart, Goldman Sachs
- Prerequisites: Q2
- Similar: 3Sum Closest, 4Sum, 3Sum Smaller
  **9. 3Sum Closest**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/3sum-closest/
- Sub-pattern: Triplet Sum (variant)
- Why it matters: Same skeleton as Q8 but no duplicate-skipping and a running "closest diff" — tests whether you memorized the pattern or the code.
- Frequency: Medium
- Companies: Amazon, Microsoft
- Prerequisites: Q8
- Similar: 3Sum, 3Sum Smaller
  **10. 3Sum Smaller**
- Platform/Difficulty: LeetCode — Medium (Premium — use GFG "Count triplets with sum smaller than target" as free alternative: https://www.geeksforgeeks.org/dsa/count-triplets-with-sum-smaller-than-a-given-value/)
- Link: https://leetcode.com/problems/3sum-smaller/
- Sub-pattern: Triplet Sum (counting variant)
- Why it matters: Introduces the "count all valid pairs at once" trick (`right - left` pairs are all valid when condition holds) — a different pointer-movement payoff than exact-match 3Sum.
- Frequency: Medium
- Companies: Google, Amazon
- Prerequisites: Q8
- Similar: Valid Triangle Number (Day 4) — same counting trick
  **11. Remove Duplicates from Sorted Array II**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
- Sub-pattern: Same Direction / Deduplication (generalized, allow-k)
- Why it matters: Direct generalization of Day 1 Q5 — cements the `nums[write-k] != nums[read]` trick that solves the whole dedup family in one line of reasoning.
- Frequency: Medium
- Companies: Amazon, Microsoft
- Prerequisites: Day 1 Q5
- Similar: Remove Duplicates from Sorted Array
  **12. 4Sum**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/4sum/
- Sub-pattern: K-Sum Generalization
- Why it matters: Forces you to nest two nested loops around the 2-pointer core and add pruning bounds — the natural "generalize to k" follow-up interviewers ask after 3Sum.
- Frequency: Medium-High
- Companies: Google, Amazon, Adobe
- Prerequisites: Q8
- Similar: 3Sum, kSum (generalized recursive version — good to mention verbally)

---

### DAY 3 — Fast & Slow + Linked List Two Pointer

_Goal: Move the same core intuition (converging / racing pointers) onto pointer-based (not index-based) structures._

**13. Linked List Cycle**

- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/linked-list-cycle/
- Sub-pattern: Fast & Slow Pointer
- Why it matters: The canonical Floyd's algorithm intro — must be automatic, no hesitation.
- Frequency: High
- Companies: Microsoft, Amazon, Adobe
- Prerequisites: None
- Similar: Linked List Cycle II, Happy Number (LC 202 — same technique on numbers)
  **14. Middle of the Linked List**
- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/middle-of-the-linked-list/
- Sub-pattern: Fast & Slow Pointer
- Why it matters: Simplest application of the 1x/2x speed trick without cycle logic — this exact sub-routine is embedded inside Q18 (Palindrome Linked List).
- Frequency: High
- Companies: Amazon, Microsoft
- Prerequisites: Q13
- Similar: Palindrome Linked List, Reorder List (LC 143)
  **15. Linked List Cycle II**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/linked-list-cycle-ii/
- Sub-pattern: Fast & Slow Pointer (find cycle start)
- Why it matters: Tests whether you actually understand the _math_ behind Floyd's (distance equality after meeting), not just memorized code — a common interviewer follow-up: "why does resetting one pointer to head work?"
- Frequency: High
- Companies: Amazon, Microsoft, Google
- Prerequisites: Q13
- Similar: Find the Duplicate Number (LC 287 — same algorithm on an array-as-linked-list)
  **16. Intersection of Two Linked Lists**
- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
- Sub-pattern: Linked List Two Pointer (length-equalization trick)
- Why it matters: A completely different two-pointer trick from fast/slow — switching heads to equalize traversal length is elegant and frequently asked as a "no extra space" constraint check.
- Frequency: High
- Companies: Amazon, Microsoft, Adobe
- Prerequisites: None
- Similar: Remove Nth Node From End (offset variant)
  **17. Remove Nth Node From End of List**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
- Sub-pattern: Linked List Two Pointer (gap/offset technique)
- Why it matters: The "advance one pointer n steps first" gap trick — a single-pass alternative to the naive two-pass (length-then-remove) approach; interviewers explicitly probe for single-pass.
- Frequency: High
- Companies: Amazon, Microsoft, Google
- Prerequisites: Q16
- Similar: Middle of Linked List
  **18. Palindrome Linked List**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/palindrome-linked-list/
- Sub-pattern: Fast & Slow + Reversal + Opposite Direction (combo capstone)
- Why it matters: Combines THREE sub-patterns from this plan (find middle via fast/slow, reverse second half, compare with converging pointers) in one question — the best single test of whether Day 3 actually landed.
- Frequency: High
- Companies: Amazon, Google, Microsoft, Adobe
- Prerequisites: Q1, Q14
- Similar: Reorder List

---

### DAY 4 — Capstone: Merge, Partition, Greedy & Hard Combos

_Goal: Recognize two-pointer opportunities in problems that don't announce themselves, and combine sub-patterns under time pressure._

**19. Merge Sorted Array**

- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/merge-sorted-array/
- Sub-pattern: Merge Pattern
- Why it matters: The "merge from the back" trick is a distinct insight from forward merging — very commonly asked precisely because the naive forward approach breaks the in-place constraint.
- Frequency: High
- Companies: Microsoft, Amazon
- Prerequisites: Q3
- Similar: Merge Two Sorted Lists (LC 21)
  **20. Sort Array By Parity**
- Platform/Difficulty: LeetCode — Easy
- Link: https://leetcode.com/problems/sort-array-by-parity/
- Sub-pattern: Partitioning (2-way, warm-up for greedy problems)
- Why it matters: Quick confirmation that partitioning intuition from Sort Colors generalizes to arbitrary predicates, not just fixed values.
- Frequency: Medium
- Companies: Amazon, Flipkart
- Prerequisites: Q7
- Similar: Sort Colors
  **21. Boats to Save People**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/boats-to-save-people/
- Sub-pattern: Greedy Opposite-Direction / Partitioning
- Why it matters: The problem statement never mentions "array" or "pointer" — pure pattern-recognition test disguised as a word problem, exactly what real interviews look like at this stage.
- Frequency: Medium
- Companies: Amazon, Uber, Goldman Sachs
- Prerequisites: Q6
- Similar: Valid Triangle Number
  **22. Valid Triangle Number**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/valid-triangle-number/
- Sub-pattern: Triplet Counting (opposite direction)
- Why it matters: Reuses the "count all valid pairs in one shot" trick from Q10 but applied to a geometric constraint — tests transferability, not memorization.
- Frequency: Medium
- Companies: Google, Amazon
- Prerequisites: Q10
- Similar: 3Sum Smaller
  **23. Trapping Rain Water**
- Platform/Difficulty: LeetCode — Hard
- Link: https://leetcode.com/problems/trapping-rain-water/
- Sub-pattern: Trapping Rain Water (leftMax/rightMax two pointer)
- Why it matters: The single highest-signal "hard" two-pointer question asked at Google/Amazon/Adobe bar-raiser rounds. Requires justifying O(1) space over the more intuitive prefix/suffix array approach — a direct evolution of Q6's greedy proof.
- Frequency: High
- Companies: Google, Amazon, Adobe, Goldman Sachs, Morgan Stanley
- Prerequisites: Q6
- Similar: Trapping Rain Water II (matrix + heap, optional stretch goal)
  **24. 3Sum With Multiplicity**
- Platform/Difficulty: LeetCode — Medium
- Link: https://leetcode.com/problems/3sum-with-multiplicity/
- Sub-pattern: Triplet Sum + Counting (advanced combo)
- Why it matters: Final capstone — combines the 3Sum skeleton (Q8) with combinatorial counting when duplicates are present (`C(k,2)` and `k*(k-1)` cases), which is exactly the kind of "now count instead of just find" twist interviewers add to a familiar pattern to gauge depth.
- Frequency: Medium
- Companies: Google, Amazon
- Prerequisites: Q8, Q10
- Similar: 4Sum, 3Sum Smaller

---

## PART 3 — Top 10 Must-Do Questions (Highest ROI)

If you only had time for 10, do these — they cover ~90% of two-pointer interview surface area:

1. **3Sum** (LC 15) — most repeated two-pointer question in industry
2. **Trapping Rain Water** (LC 42) — the hard bar-raiser
3. **Container With Most Water** (LC 11) — greedy proof staple
4. **Two Sum II** (LC 167) — atomic building block
5. **Sort Colors** (LC 75) — only 3-pointer partition question, very common
6. **Remove Nth Node From End of List** (LC 19) — single-pass gap trick, very common
7. **Linked List Cycle II** (LC 142) — tests real algorithmic understanding
8. **Palindrome Linked List** (LC 234) — 3-pattern combo, frequently asked
9. **4Sum** (LC 18) — the natural "generalize" follow-up
10. **Valid Palindrome** (LC 125) — fast, near-guaranteed easy-round opener

## PART 4 — Top 5 Hard / Combo Questions

Questions that force you to combine ≥2 sub-patterns — use these as your final mock-interview set:

1. **Trapping Rain Water** (LC 42) — greedy + two max-trackers
2. **Palindrome Linked List** (LC 234) — fast/slow + reversal + opposite direction
3. **3Sum With Multiplicity** (LC 923) — triplet sum + combinatorics
4. **Boats to Save People** (LC 881) — greedy + disguised partitioning
5. **4Sum** (LC 18) — nested loop pruning + two pointer core

## PART 5 — Common Mistakes Candidates Make

- **Forgetting to skip duplicates correctly in 3Sum/4Sum** — skipping at the wrong index (before vs after the match check) either misses valid triplets or emits duplicates.
- **Advancing `mid` after a swap with `high` in Dutch National Flag** — the swapped-in value from the high partition is unexamined; advancing `mid` skips checking it.
- **Using two pointers on an unsorted array without sorting first** (when sorting is legal) — many candidates try opposite-direction pointers on raw input and get wrong results, forgetting the technique's core precondition.
- **Not handling empty array / single element / all-same-element edge cases** — especially in dedup and 3Sum, `n < 3` guards are frequently forgotten.
- **In "remove nth from end," forgetting the dummy head** — when the node to remove is the head itself, missing a dummy node causes null-pointer bugs.
- **Conflating sliding window with two pointer** — same-direction two pointer (fixed relationship) is not the same as a variable-size sliding window (both pointers move independently based on a condition); candidates often can't articulate the difference when asked.
- **Off-by-one in the "count all valid pairs" trick** (3Sum Smaller / Valid Triangle Number) — forgetting that `right - left` pairs are ALL valid once the condition holds, and redoing O(n) work per pair instead of O(1).
- **Not proving the greedy choice out loud** — in Container With Most Water / Trapping Rain Water, jumping straight to code without stating "the shorter wall bounds the water/area, so moving the taller pointer cannot help" signals shallow understanding to the interviewer.
- **Recomputing length for linked list problems** — using two-pass (compute length, then traverse again) when a single-pass gap-based or fast/slow approach is expected and explicitly tests O(1) extra pass discipline.
- **Ignoring integer overflow** in sum comparisons — rare in Java/Python, but candidates using C++ with large constraint sums forget to use `long long`.

## PART 6 — Recognition Decision Tree

```
Is the input a linked list?
├── YES
│   ├── Need cycle detection / start of cycle? ────────────► Fast & Slow Pointer
│   ├── Need the middle node? ─────────────────────────────► Fast & Slow Pointer
│   ├── Need nth node from the end? ───────────────────────► Gap/Offset Technique
│   ├── Need intersection of two lists? ───────────────────► Length-Equalization Technique
│   └── Need palindrome check? ────────────────────────────► Fast/Slow + Reversal + Opposite Direction
│
└── NO (array / string)
    ├── Is the array sorted (or sortable, and order doesn't matter for the answer)?
    │   ├── YES
    │   │   ├── Need a PAIR summing to target? ────────────► Opposite Direction / Pair Sum
    │   │   ├── Need TRIPLETS? ─────────────────────────────► 3Sum family (exact / closest / count)
    │   │   ├── Need K numbers (k>3)? ──────────────────────► K-Sum Generalization
    │   │   ├── Need max area/water between two bars? ─────► Container / Trapping Rain Water
    │   │   ├── Need to count pairs/triplets satisfying an inequality? ─► Counting variant (right-left trick)
    │   │   └── Need to merge with another sorted array/list? ─► Merge Pattern (merge from back if in-place)
    │   │
    │   └── NO (unsorted, and sorting is either not allowed or order matters)
    │       ├── Need to remove/overwrite elements in-place? ─► Same Direction (slow-fast write pointer)
    │       ├── Need to remove duplicates (sorted array, order preserved)? ─► Deduplication Pattern
    │       ├── Need to segregate into exactly 3 known categories (e.g. 0/1/2)? ─► Dutch National Flag
    │       ├── Need to partition by a predicate (even/odd, greedy pairing)? ─► Partitioning
    │       └── Need to check symmetry (palindrome string)? ─► Opposite Direction / Palindrome Validation
    │
    └── If NONE of the above fit, and you only need a window that grows/shrinks based on a running condition (sum, distinct count, etc.) → that's Sliding Window, NOT classic Two Pointer. Don't force-fit it.
```

**Key litmus test:** if you can eliminate half the remaining search space with every pointer move (not just shrink a window by 1), it's two pointer. If pointers move independently based on an accumulating condition (like "shrink while sum > target"), it's sliding window — a cousin pattern, not this one.

---

## PART 7 — Reusable C++ Templates

### Template 1: Opposite Direction (Pair Sum)

```cpp
// Time: O(n) | Space: O(1)
// Use when: sorted array, need pair satisfying sum/comparison condition
bool pairSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
// Modifications: for "closest," track min(abs(sum-target));
// for "count pairs < target," valid pairs = right-left when sum < target, then right--.
```

### Template 2: Same Direction (Slow-Fast Write Pointer)

```cpp
// Time: O(n) | Space: O(1)
// Use when: in-place removal/overwrite/compaction
int removeInPlace(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }
    return slow; // new length
}
// Modification for "allow k duplicates":
// if (slow < k || nums[fast] != nums[slow - k]) nums[slow++] = nums[fast];
```

### Template 3: Fast & Slow (Floyd's Cycle Detection)

```cpp
// Time: O(n) | Space: O(1)
// Use when: linked list cycle / middle detection
ListNode* findCycleStart(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) { slow = slow->next; fast = fast->next; }
            return slow; // cycle start
        }
    }
    return nullptr; // no cycle
}
```

### Template 4: Dutch National Flag

```cpp
// Time: O(n) single pass | Space: O(1)
// Use when: 3-way partition around fixed pivot values (e.g., 0,1,2)
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]); // do NOT advance mid here
    }
}
```

### Template 5: Triplet Sum (3Sum Skeleton)

```cpp
// Time: O(n^2) after O(n log n) sort | Space: O(1) extra (excl. output)
// Use when: triplets satisfying exact/closest/inequality target
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < (int)nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip dup anchor
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++; right--;
            } else if (sum < 0) left++;
            else right--;
        }
    }
    return res;
}
// Modification for K-Sum: wrap this in an outer loop / recursion fixing k-2 elements.
```

### Template 6: Container / Trapping Rain Water

```cpp
// Container: Time O(n) | Space O(1)
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1, best = 0;
    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        best = max(best, area);
        if (height[left] < height[right]) left++;
        else right--;
    }
    return best;
}

// Trapping Rain Water: Time O(n) | Space O(1)
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
            left++;
        } else {
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
            right--;
        }
    }
    return water;
}
```

### Template 7: Merge Pattern (In-Place, From the Back)

```cpp
// Time: O(m+n) | Space: O(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}
```

### Template 8: Linked List Gap / Length-Equalization

```cpp
// Nth from end — Time O(n) | Space O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0); dummy.next = head;
    ListNode *fast = &dummy, *slow = &dummy;
    for (int i = 0; i < n; i++) fast = fast->next;
    while (fast->next) { fast = fast->next; slow = slow->next; }
    slow->next = slow->next->next;
    return dummy.next;
}

// Intersection — Time O(m+n) | Space O(1)
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *a = headA, *b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a; // intersection node or nullptr
}
```

---

## PART 8 — Interview Notes (What Experienced Interviewers Expect)

- **State the invariant before coding.** For same-direction problems, say out loud: "everything before `slow` is finalized/correct." For 3Sum: "array is sorted, so once I fix `i`, the remaining is a 2Sum on a sorted sub-array." This single sentence signals seniority far more than fast typing.
- **Always ask about duplicates and edge cases up front** for 3Sum/4Sum-family questions — "should the output contain duplicate triplets?" is a real clarifying question interviewers expect, not a stalling tactic.
- **Know the space complexity trade-off cold**: two pointer on a sorted array is O(1) extra space vs O(n) for a hashmap-based pair sum. Say this explicitly when asked "can you do better than O(n) space."
- **For Trapping Rain Water, be ready to explain three approaches on request**: brute force O(n²), prefix/suffix max arrays O(n) space, and two pointer O(1) space — this progression is a very common live follow-up.
- **Dry-run on a tiny example with duplicates** (e.g., `[0,0,1,1,2,2]` for Sort Colors, `[-1,-1,0,1,1]` for 3Sum) before declaring "done" — this catches 80% of pointer-movement bugs before the interviewer has to.
- **Linked list problems: always ask about a dummy head** when the operation might affect the head node (removal, reversal) — forgetting this is one of the most common silent bugs.
- **Mention the sliding window boundary explicitly** if the interviewer's problem sounds two-pointer-ish but actually needs variable window growth (e.g., "minimum subarray with sum ≥ target") — correctly identifying "this is actually sliding window, not two pointer" is itself a signal of maturity.
- **For "prove your greedy is correct" questions (Container With Most Water, Boats to Save People)** — have a one-line proof ready. Interviewers at Google/Amazon bar-raiser level will ask "why does this work?" even if your code is correct.
- **Time-box yourself**: on a 45-minute round, a two-pointer Medium should be coded and dry-run within 15–18 minutes, leaving room for a follow-up (e.g., "now generalize to k" or "now do it with O(1) space").
- **Don't forget to discuss the sorted-order side effect** — if the original array order needs to be preserved but you must sort for two-pointer to work, mention that you'd need to sort a copy of indices, not the values themselves (relevant in variants of Two Sum that need original indices returned).
