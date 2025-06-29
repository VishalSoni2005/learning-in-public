## HASHING

-> Hashing is a technique to map a data in cretain order using hash function to reduce time complexities to average T.C.=> O(1)

-> Seperate Chaining : Instead of searching for another index, Separate Chaining stores multiple elements at the same index using a linked list (or vector, or other structures).
hash_table[index] = linked list of values

-> Linear probing: it is a collision resolution technique used in hash tables (including some implementations of unordered_map). When a hash collision occurs (two different keys hash to the same index), linear probing searches sequentially for the next available slot. its major con is it faces primary cluster .
hash formula: h(k, i) = h(h(k) + i) % size;

-> Quadratic Probing: it is a collision resolution technique used in hash tables.
When two keys hash to the same index (a collision), instead of placing the new key right next to it (as in linear probing), quadratic probing searches for the next available slot using a quadratic formula.
formula: h(k, i) = (h(k) + i^2) % table_size
main challenge of this probing is secondary clustering (elements with same initial hash follow same probe sequence).

-> Double Hashing: Double Hashing uses a second hash function to calculate the probe step size when a collision occurs.
h(k, i) = (h1(k) + i \* h2(k)) % table_size

## Which hashing is used in hashmap and how?
Ans: Open Addressing + Separate Chaining