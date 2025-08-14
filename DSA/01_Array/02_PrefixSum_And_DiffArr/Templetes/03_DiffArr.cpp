// diff array approach
vector<int> diff(n + 1, 0);
auto update = [&](int l, int r, int val) {
  diff[l] += val;
  if (r + 1 < diff.size()) diff[r + 1] -= val;
};

// After all updates
vector<int> arr(n);
arr[0] = diff[0];
for (int i = 1; i < n; i++) arr[i] = arr[i - 1] + diff[i];
