class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    // NOTE : THE PEEK WILL NEVER BE AT FIRST  AND LAST INDEX . PROPERTY OF MOUNTAIN
    //  AT EDGE CASES EITHER THE PEAK IS AT SECOND PLACE OR AT LAST SECOND PLACE
    int n = arr.size();
    int lo = 1;
    int hi = n - 2;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
        return mid;
      else if (arr[mid] > arr[mid - 1])
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    return -1;
  }
};