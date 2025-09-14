1️⃣ How XOR works and why (a ^ b) < 0 detects different signs

Bitwise XOR rule
XOR = 1 if the two input bits are different.
XOR = 0 if the two input bits are the same.

| Bit A | Bit B | A ^ B |
| ----- | ----- | ----- |
| 0     | 0     | 0     |
| 0     | 1     | 1     |
| 1     | 0     | 1     |
| 1     | 1     | 0     |

Sign representation in computers
Integers use two’s complement.

The most significant bit (MSB) is the sign bit:
0 → positive
1 → negative

Example (32-bit for clarity):

7 = 00000000 00000000 00000000 00000111
-2 = 11111111 11111111 11111111 11111110
