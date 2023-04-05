#include <bits/stdc++.h>
using namespace std;

int a[5001], b[5001], f[5001] = {};

int main()
{
    int n, s, m = 1e9, m1 = -1e9;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        m = min(m, a[i]);
    }
    if (s < m)
    {
        cout << 0;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = s; j >= a[i]; j--)
            {
                if (f[j - a[i]] || j - a[i] == 0)
                {
                    f[j] = max(f[j], f[j - a[i]] + b[i]);
                    m1 = max(m1, f[j]);
                }
            }
        }
        cout << m1;
    }
}