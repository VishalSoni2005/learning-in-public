## Topics: 
Array
string 
sorting

## Questions were :
1: compare btw sorted and non sorted arr (easy, solved)
2: Even Swaps (Mediun, not solved)
3: K palindron (Hard, Not solved)

## MCQ Notes: 
1: mutable and unmutable strings
2: string stream
3: Count all distinct pairs (i, j) such that:
    1 ≤ i < j ≤ n
    (i + j) % 2 == 0 → i + j is even. ans=> ✔ n*(n - 1)/4
4: quick sort unstable
5: selection sort and insertion sort
6: greater<int> is a functor (also called a function object) provided by C++ STL in the <functional> header.
7: sort(v.begin(), v.end(), greater<int>()) // sort in decesding
8: So when you write:
    sort(nums.begin(), nums.begin() + 3, greater<int>()); // when nums.begin() + 3 comes at second place it is exclusive
    You are sorting:
    [nums[0], nums[1], nums[2]] = [1, 2, 3]
    In descending order → becomes: [3, 2, 1]