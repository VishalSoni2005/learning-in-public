//! Longest Substring with K Uniques
class Solution {
 public:
  int longestKSubstr(string &s, int k) {
    // code here

    int ml = -1;
    unordered_map<char, int> mp;
    int l = 0;

    for (int r = 0; r < s.length(); r++) {
      mp[s[r]]++;

      while (mp.size() > k) {
        mp[s[l]]--;

        if (mp[s[l]] == 0) mp.erase(s[l]);
        l++;
      }

      if (mp.size() == k) ml = max(ml, r - l + 1);
    }
    return ml;
  }
};