vector<int> pgcd(n), sgcd(n);
pgcd[0] = nums[0];
for (int i = 1; i < n; i++) pgcd[i] = gcd(pgcd[i - 1], nums[i]);

sgcd[n - 1] = nums[n - 1];
for (int i = n - 2; i >= 0; i--) sgcd[i] = gcd(sgcd[i + 1], nums[i]);

// GCD of array except index k:
int gcdExceptK = gcd((k > 0 ? pgcd[k - 1] : 0), (k < n - 1 ? sgcd[k + 1] : 0));
