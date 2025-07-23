# PROBLEM SOLVED IN DP: 

### 1D DP Pattern Questions: 
|  # | Problem Name                                  | LeetCode # | Pattern                       |
| -: | --------------------------------------------- | ---------- | ----------------------------- |
|  1 | Factorial (Recursive + Memo)                  | –          | Recursion + Memoization       |
|  2 | Climbing Stairs                               | 70         | Fibonacci-style               |
|  3 | Min Cost Climbing Stairs                      | 746        | Minimum Path                  |
|  4 | Frog Jump (Min Energy GFG)                    | –          | Min Cost                      |
|  5 | House Robber                                  | 198        | Non-adjacent elements         |
|  6 | House Robber II                               | 213        | Circular constraint           |
|  7 | House Robber III                              | 337        | Tree DP (Advanced)            |
|  8 | Maximum Subarray                              | 53         | Kadane’s Algorithm            |
|  9 | Decode Ways                                   | 91         | Ways to decode a string       |
| 10 | Jump Game I                                   | 55         | Greedy/DP hybrid              |
| 11 | Jump Game II (Min Jumps)                      | 45         | Greedy/DP hybrid              |
| 12 | Integer Break                                 | 343        | DP with Math                  |
| 13 | Partition Equal Subset Sum                    | 416        | Subset Sum DP                 |
| 14 | Target Sum                                    | 494        | Subset Sum variation          |
| 15 | Best Time to Buy and Sell Stock with Cooldown | 309        | DP with State Transitions     |
| 16 | Longest Increasing Subsequence (Tabulation)   | 300        | DP + Binary Search (Advanced) |
| 17 | Combination Sum IV                            | 377        | Counting combinations         |
| 18 | Arithmetic Slices                             | 413        | Count subarrays               |
| 19 | Paint Fence                                   | 276        | Coloring with constraints     |
| 20 | Tribonacci Number                             | 1137       | Fibonacci-style variant       |


### 2D DP pattern Questions: 
  |  # | Problem Name                     | LeetCode # | Pattern                    |
| -: | -------------------------------- | ---------- | -------------------------- |
|  1 | 0/1 Knapsack                     | – / 416    | Pick/Not pick              |
|  2 | Coin Change                      | 322        | Min coins                  |
|  3 | Coin Change II                   | 518        | Count combinations         |
|  4 | Longest Common Subsequence       | 1143       | Classic LCS                |
|  5 | Edit Distance                    | 72         | String Transform           |
|  6 | Longest Palindromic Subsequence  | 516        | Subsequence based          |
|  7 | Longest Palindromic Substring    | 5          | Substring-based DP         |
|  8 | Distinct Subsequences            | 115        | Count subsequences         |
|  9 | Interleaving String              | 97         | DP with 3 indices          |
| 10 | Minimum Path Sum                 | 64         | Grid DP                    |
| 11 | Unique Paths                     | 62         | Combinatorics/Grid         |
| 12 | Unique Paths II (with obstacles) | 63         | Grid DP with Blocked cells |
| 13 | Maximum Profit in Job Scheduling | 1235       | DP with Binary Search      |
| 14 | Cherry Pickup                    | 741        | DP on 2D grid              |
| 15 | Dungeon Game                     | 174        | DP from bottom-up          |


### 🔥 Important Patterns in 1D DP
| Pattern             | Description                               | Examples                               |
| ------------------- | ----------------------------------------- | -------------------------------------- |
| **Fibonacci-style** | `dp[i] = dp[i-1] + dp[i-2]`               | Climbing Stairs, Tribonacci            |
| **Min/Max Path**    | `dp[i] = min(dp[i-1], dp[i-2]) + cost[i]` | Min Cost Climbing, Frog Jump           |
| **Take or Skip**    | Either take current or not                | House Robber, Integer Break            |
| **Partitioning**    | Subset sum logic                          | Partition Equal Subset Sum, Target Sum |
| **Counting Ways**   | Count combinations/permutations           | Decode Ways, Combination Sum IV        |


### 🔥 Important Patterns in 2D DP

| Pattern                    | Description                              | Examples                                  |
| -------------------------- | ---------------------------------------- | ----------------------------------------- |
| **LCS Family**             | Compare characters across two strings    | LCS, Edit Distance, Distinct Subsequences |
| **Grid-based**             | Move in directions (right/down)          | Unique Paths, Minimum Path Sum            |
| **Knapsack Family**        | Choices to include or not include item   | 0/1 Knapsack, Coin Change                 |
| **Palindrome-based**       | Check for palindromes using two pointers | Longest Palindromic Subsequence/Substr    |
| **Subsequence Count**      | Count valid subsequences                 | Distinct Subsequences                     |
| **DP + State Compression** | Reduce space to 1D from 2D               | Coin Change, Knapsack                     |
| **DP on Trees**            | Solve for nodes/subtrees recursively     | House Robber III                          |

