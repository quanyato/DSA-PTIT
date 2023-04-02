#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, x, y;
    cin >> n >> q;
    int a[n + 1] = {0};
    while (q--)
    {
        cin >> x >> y;
        for (int i = x; i <= y; i++)
        {
            if (a[i] == 0)
            {
                a[i] = 1;
            }
            else if (a[i] == 1)
            {
                a[i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}