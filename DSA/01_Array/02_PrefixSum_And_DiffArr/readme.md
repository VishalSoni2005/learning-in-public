# Sub patterns in this topics

1 Basic Prefix Sum
2 Prefix Sum + Hash Map

3 Difference Array (1D)
4 2D Prefix Sum

5 Prefix Sum + Modulo
6 Prefix Sum + Binary Search

7 prefix XOR
8 Prefix GCD / Prefix Min/Max

## key important i noticed

1 in prefix Sum and HashMap
note that ** [[(prefix Sum)ridx - (prefix Sum)lidx === (arr)lidx + (arr)ridx - 1]] **
and based on rhs condition we evaluate situation of question

productArr(i, j) = prefixProd[j] / prefixProd[i-1]

