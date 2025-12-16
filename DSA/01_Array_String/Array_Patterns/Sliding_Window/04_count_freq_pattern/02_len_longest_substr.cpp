int lengthOfLongestSubstring(string s) {
  unordered_set<char> us;
  int maxLength = 0;
  int left = 0;

  for (int right = 0; right < s.length(); right++) {
    // If current character already exists in the window
    while (us.count(s[right])) {
      // Remove characters from left until duplicate is gone
      us.erase(s[left]);
      left++;
    }

    // Add current character to set
    us.insert(s[right]);

    // Update maximum length
    maxLength = max(maxLength, right - left + 1);
  }

  return maxLength;
}