#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    int i, j, f[1005], kq = 0;
    for (i = 0; i < n; i++)
    {
        f[i] = a[i];
        for (j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
        kq = max(kq, f[i]);
    }
    return kq;
}

int main()
{
    int t, n, a[1005];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve(a, n) << endl;
    }
}