#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    for (int i = 1; i <= 10; i++)
    {
        s.insert(i * 10);
    }

    for (auto element : s)
        cout << element << " ";
    cout << endl;

    // checking wheather 20 and 69 is present in set or not
    if (s.find(20) != s.end())
    { // this line means target exist
        cout << 20 << " Hain na Sir " << endl;
    }

    if (s.find(69) != s.end())
    {
        cout << 69 << " Hain na Sir " << endl;
    }
    else
    {

        cout << 69 << " Nahi hai Sir" << endl;
    }

    cout << s.count(10);
}