// todo:  Substrings with K Distinct

class Solution {
 public:
  int atMostK(string &s, int k) {
    int ml = 0;
    int l = 0;
    unordered_map<char, int> us;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
      us[s[i]]++;

      while (us.size() > k) {
        us[s[l]]--;
        if (us[s[l]] == 0) us.erase(s[l]);
        l++;
      }

      ml += i - l + 1;
      {
      }
      return ml;
    }

    int countSubstr(string & s, int k) {
      // code here
      return atMostK(s, k) - atMostK(s, k - 1);
    }
  };
