# ✅ DP on Sequences — Master Table of Must-Do Patterns

|   # | Problem Type                                 | Pattern                    | DP State                        | Based On                       | Use Case                     |
| --: | -------------------------------------------- | -------------------------- | ------------------------------- | ------------------------------ | ---------------------------- |
|   1 | **Longest Common Subsequence (LCS)**         | `2D DP`                    | `dp[i][j]`                      | Match `s1[i-1]` with `s2[j-1]` | Subsequence comparison       |
|   2 | **Longest Repeating Subsequence (LRS)**      | `2D DP (LCS)`              | `dp[i][j]` with `i ≠ j`         | LCS of `s` with itself         | Pattern finding              |
|   3 | **Longest Palindromic Subsequence (LPS)**    | `LCS(s, rev(s))`           | `dp[i][j]`                      | Palindrome property            | Min insertions to palindrome |
|   4 | **Longest Common Substring (LCSS)**          | `2D DP` with reset         | `dp[i][j]` = 0 on mismatch      | Continuous character match     | Bioinformatics, search       |
|   5 | **Edit Distance (Levenshtein)**              | `2D DP`                    | Insert/Delete/Replace ops       | Modify s1 → s2                 | Typo corrections, spellcheck |
|   6 | **Minimum Insertions/Deletions**             | `LCS-based`                | Use `len(s1) - LCS(s1, s2)`     | Make s1 into s2                | String transformation        |
|   7 | **Shortest Common Supersequence (SCS)**      | `LCS-based`                | Build from `s1 + s2 - LCS`      | Merge sequences                | DNA, merge diff              |
|   8 | **Longest Increasing Subsequence (LIS)**     | `1D DP` or `Binary Search` | `dp[i] = max(dp[j] + 1)`        | Strictly increasing            | Sequence growth              |
|   9 | **Longest Bitonic Subsequence**              | `LIS + LDS`                | `dp[i] = LIS[i] + LDS[i] - 1`   | Up then down sequence          | Zigzag paths                 |
|  10 | **Longest Arithmetic Subsequence**           | `HashMap DP`               | `dp[i][diff] = dp[j][diff] + 1` | Constant difference            | AP pattern                   |
|  11 | **Number of LIS**                            | `1D DP + count[]`          | Count all LIS of max length     | Combinatorics on LIS           | Competitive scenarios        |
|  12 | **Maximum Sum Increasing Subsequence**       | `LIS variation`            | Use element values as weight    | Best increasing path           | Path weight problems         |
|  13 | **Subsequence Pattern Matching**             | `LCS variant`              | Check if `s1` in `s2`           | Greedy or DP                   | Search problems              |
|  14 | **Palindrome Partitioning (min cuts)**       | `Memoization`              | `dp[i] = min cuts`              | Slicing into palindromes       | Cut-based segmentation       |
|  15 | **Partition Equal Subset Sum / K Partition** | `Subset Sum`               | `dp[i][j] = true/false`         | Sum or modulo constraints      | Array partitioning           |
