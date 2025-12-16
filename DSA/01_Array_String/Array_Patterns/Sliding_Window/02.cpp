class Solution {
 public:
  int longestUniqueSubstr(string &s) {
    // code here

    unordered_set<char> us;

    int l = 0;
    int r = 0;
    int ml = 0;

    while (r < s.length()) {
      while (us.count(s[r])) us.erase(s[l++]);

      us.insert(s[r]);
      ml = max(ml, r - l + 1);
      r++;
    }
    return ml;
  }
};
