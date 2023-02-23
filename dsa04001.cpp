// LUY THUA
// Cho số nguyên dương N và K. Hãy tính N^K modulo 10^9+7.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 1 số nguyên N và K (1 ≤ N ≤ 1000, 1 ≤ K ≤ 109).
// Output:
// Với mỗi test, in ra đáp án trên một dòng.

// Ví dụ:
// Input:          Output
// 2               8
// 2 3             16
// 4 2

#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;
long long powMod(int n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    long long x = powMod(n, k / 2);
    if (k % 2 == 0)
    {
        return x * x % M;
    }
    return n * (x * x % M) % M;
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << powMod(n, k) << endl;
    }
}