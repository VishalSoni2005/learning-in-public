// User function Template for C++

class Solution {
 public:
  vector<int> lexicographicallyLargest(vector<int> &arr, int n) {
    // Code here
    // this question says as followed in example:
    // arr = [1, 3, 2, 8, 6, 4, 5, 7, 9]
    // so sort desc ods even no as [3, 1]
    // then even as : [8, 6, 4, 2]
    // then again odd ones as : [5, 7, 9]

    // final ans : [3, 1, 8, 6, 4, 2, 9, 7, 5];

    int i = 0;
    while (i < n) {
      int j = i;
      while (j + 1 < n && (arr[j] % 2 == arr[j + 1] % 2))
        j++;
      sort(arr.begin() + i, arr.begin() + j + 1, greater<int>());
      i = j + 1;
    }
    return arr;
  }
};
// 7 : sort(v.begin(), v.end(), greater<int>())                                       // sort in decesding
//     8 : So when you write : sort(nums.begin(), nums.begin() + 3, greater<int>());  // when nums.begin() + 3 comes at second place it is exclusive
// You are sorting : [ nums[0], nums[1], nums[2] ] = [ 1, 2, 3 ] In descending order → becomes : [ 3, 2, 1 ]