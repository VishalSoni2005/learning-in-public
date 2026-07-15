# 🎯 Kadane's Algorithm — Pattern Guide

> Maximum sum contiguous subarray in O(n). Core idea: extend or restart at every index.

---

## 📌 Sub-Patterns

### 1️⃣ Standard Kadane's

Basic max sum contiguous subarray.

- [ ] Maximum Subarray — **LeetCode #53**
- [ ] Maximum Subarray Sum — **GfG**
- [ ] Largest Sum Contiguous Subarray — **GfG**

_Template → [Standard Kadane's](#-standard-kadanes)_

---

### 2️⃣ Circular Kadane's

Subarray can wrap around the end of the array.

- [ ] Maximum Sum Circular Subarray — **LeetCode #918**
- [ ] Maximum Circular Subarray Sum — **GfG**

_Template → [Circular Kadane's](#-circular-kadanes)_

---

### 3️⃣ Product Kadane's

Track both max and min (negatives flip the sign).

- [ ] Maximum Product Subarray — **LeetCode #152**
- [ ] Maximum Product Subarray — **GfG**

_Template → [Product Kadane's](#-product-kadanes)_

---

### 4️⃣ Constrained Kadane's

Kadane's + one allowed deletion/skip (extra DP state).

- [ ] Maximum Subarray Sum with One Deletion — **LeetCode #1186**
- [ ] Maximum Sum Subarray Removing at Most One Element — **GfG**

_Template → [Constrained Kadane's](#-constrained-kadanes)_

---

### 5️⃣ 2D Kadane's

Fix row pairs, collapse columns via prefix sum, run 1D Kadane's.

- [ ] Maximum Sum Rectangle in a 2D Matrix — **GfG**
- [ ] Max Sum Rectangle No Larger Than K — **LeetCode #363**

_Template → [2D Kadane's](#-2d-kadanes)_

---

### 6️⃣ Disguised Kadane's

Problem doesn't look like Kadane's — derive an array first, then apply it.

- [ ] Best Time to Buy and Sell Stock — **LeetCode #121**
- [ ] Maximum Difference Between Increasing Elements — **GfG**

_Template → [Disguised Kadane's](#-disguised-kadanes)_

---

## 🗺️ Quick Map

```
Standard Kadane's (sum)
   ├── Circular      → wrap-around subarray
   ├── Product       → track max & min together
   ├── Constrained   → allow one deletion/skip
   ├── 2D            → row-collapse + 1D Kadane's
   └── Disguised     → transform problem into a sum array
```

---

---

## 🧩 Templates (C++)

### 🔹 Standard Kadane's

```cpp
int kadane(vector<int>& arr) {
    int maxEndingHere = arr[0], maxSoFar = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
```

### 🔹 Circular Kadane's

```cpp
int maxSubarraySumCircular(vector<int>& arr) {
    int total = 0, maxSum = arr[0], curMax = 0;
    int minSum = arr[0], curMin = 0;

    for (int x : arr) {
        curMax = max(x, curMax + x);
        maxSum = max(maxSum, curMax);

        curMin = min(x, curMin + x);
        minSum = min(minSum, curMin);

        total += x;
    }

    if (maxSum < 0) return maxSum;          // all elements negative
    return max(maxSum, total - minSum);
}
```

### 🔹 Product Kadane's

```cpp
int maxProduct(vector<int>& arr) {
    int maxEndHere = arr[0], minEndHere = arr[0], result = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < 0) swap(maxEndHere, minEndHere);

        maxEndHere = max(arr[i], maxEndHere * arr[i]);
        minEndHere = min(arr[i], minEndHere * arr[i]);

        result = max(result, maxEndHere);
    }
    return result;
}
```

### 🔹 Constrained Kadane's (one deletion allowed)

```cpp
int maximumSum(vector<int>& arr) {
    int n = arr.size();
    int noDelete = arr[0], oneDelete = 0, result = arr[0];

    for (int i = 1; i < n; i++) {
        oneDelete = max(oneDelete + arr[i], noDelete);   // delete arr[i] or carry forward
        noDelete  = max(arr[i], noDelete + arr[i]);       // standard Kadane's

        result = max({result, noDelete, oneDelete});
    }
    return result;
}
```

### 🔹 2D Kadane's

```cpp
int maxSumRectangle(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int best = INT_MIN;

    for (int top = 0; top < rows; top++) {
        vector<int> colSum(cols, 0);

        for (int bottom = top; bottom < rows; bottom++) {
            for (int c = 0; c < cols; c++)
                colSum[c] += matrix[bottom][c];

            best = max(best, kadane(colSum));   // reuse standard Kadane's
        }
    }
    return best;
}
```

### 🔹 Disguised Kadane's (Buy/Sell Stock example)

```cpp
int maxProfit(vector<int>& prices) {
    int maxEndingHere = 0, maxSoFar = 0;

    for (int i = 1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i - 1];
        maxEndingHere = max(0, maxEndingHere + diff);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}
```

---

_Track your progress by checking off problems above. Revisit templates whenever stuck._ ✅
