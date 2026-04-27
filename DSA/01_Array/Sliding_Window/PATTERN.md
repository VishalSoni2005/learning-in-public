🔥 Sliding Window — Complete Pattern Guide
🧠 What is Sliding Window?

Used when:

You are working with subarrays / substrings
You need optimal (usually O(n)) instead of brute force O(n²)
Window = a range [l → r] that moves
⚡ Core Types of Sliding Window

There are 2 major patterns:

# 1. 🟢 Fixed Size Window

💡 Idea:

Window size is constant → just slide it

🔑 Common Variations:
Max sum of size k
First negative number in window
Count distinct elements in window of size k
🧪 Must Do Problems:
Maximum Sum Subarray of Size K
First Negative Number in Every Window of Size K
Count Distinct Elements in Every Window
Sliding Window Maximum (important - uses deque)

# 2. 🔴 Variable Size Window (Most Important)

💡 Idea:

Window expands and shrinks based on condition

🔥 Sub-patterns inside Variable Window

# 🔹 A. Longest Subarray / Substring

🧠 Goal:

Maximize length

🧪 Must Do:
Longest Substring Without Repeating Characters ⭐
Longest Repeating Character Replacement ⭐
Max Consecutive Ones III
Fruit Into Baskets

# 🔹 B. Smallest / Minimum Window

🧠 Goal:

Minimize window size

🧪 Must Do:
Minimum Window Substring ⭐ (VERY IMPORTANT)
Smallest Subarray with Sum ≥ K
Minimum Size Subarray Sum

# 🔹 C. Count of Subarrays

🧠 Trick:

Instead of counting directly → use:

count = r - l + 1
🧪 Must Do:
Number of Subarrays with At Most K Distinct ⭐
Binary Subarrays With Sum
Count Number of Nice Subarrays

# 🔹 D. Exactly K (IMPORTANT TRICK)

🧠 Trick:
Exactly K = AtMost(K) - AtMost(K-1)
🧪 Must Do:
Subarrays with K Distinct Integers ⭐
Count Subarrays with Exactly K Odd Numbers

# 🔹 E. Sliding Window + Data Structure

Used when:

Need max/min in window
Use deque / heap
🧪 Must Do:
Sliding Window Maximum ⭐⭐ (deque based)
Sliding Window Median
