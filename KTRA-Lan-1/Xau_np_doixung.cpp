#include <bits/stdc++.h>
using namespace std;

void sinh_np(int n)
{
    int a[n] = {};
    for (int i = 1; i <= n; i++)
    { // sinh cau hinh dau
        a[i] = 0;
    }

    while (1)
    {
        // in ra cau hinh
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        for (int i = n; i > 0; i--)
        {
            cout << a[i];
        }
        cout << " ";

        // sinh cau hinh ke
        int i = n;
        while (a[i] == 1)
        {
            i--;
        }
        if (i == 0)
        {
            break;
        }
        else
        {
            a[i] = 1;
            for (int j = i + 1; j <= n; j++)
            {
                a[j] = 0;
            }
        }
    }
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int m = 1; m <= n / 2; m++)
        {
            sinh_np(m);
        }
        cout << endl;
    }
}