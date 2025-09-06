// Count / Frequency-based Sliding Window
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int solve(string s, string pattern, int k = -1) {
    unordered_map<char, int> freq;  // frequency map for current window
    unordered_map<char, int> need;  // target freq (used in anagrams/permutation)

    for (char c : pattern) need[c]++;

    int left = 0, matched = 0, result = 0;

    for (int right = 0; right < s.size(); right++) {
      char c = s[right];
      freq[c]++;

      // If exact frequency matched, count it
      if (need.count(c) && freq[c] == need[c]) {
        matched++;
      }

      // When window size exceeds k (for fixed-length substring problems)
      if (k != -1 && right - left + 1 > k) {
        char d = s[left++];
        if (need.count(d) && freq[d] == need[d]) {
          matched--;
        }
        freq[d]--;
        if (freq[d] == 0) freq.erase(d);
      }

      // ✅ Check condition (depends on problem)
      // Example 1: Find Anagrams
      if (k != -1 && right - left + 1 == k && matched == need.size()) {
        result++;
      }

      // Example 2: Longest Substring with ≤ k distinct chars
      // while (freq.size() > k) {
      //     freq[s[left]]--;
      //     if (freq[s[left]] == 0) freq.erase(s[left]);
      //     left++;
      // }
      // result = max(result, right - left + 1);
    }

    return result;  // can also return maxLen, indices, etc.
  }
};
