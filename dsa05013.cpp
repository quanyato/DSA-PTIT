#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;
int tinh(int n, int k)
{
    int i, j, f[100005] = {0};
    f[0] = 1;
    f[1] = 1;
    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= min(i, k); j++)
        {
            f[i] = (f[i] + f[i - j]) % M;
        }
    }
    return f[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << tinh(n, k) << endl;
    }
}