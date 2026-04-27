vector<int> pxor(n + 1, 0);
for (int i = 0; i < n; i++) pxor[i + 1] = pxor[i] ^ nums[i];

// XOR of range [l..r]
int xorLR = pxor[r + 1] ^ pxor[l];
