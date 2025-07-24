#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    cout << "Fill" << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // BUBBLE SORTING
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true; // i.e. SORTED
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
            break;
    }

    // printing
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}