#include <bits/stdc++.h>
using namespace std;

int n, x, thereIsACombination = 0;
vector<int> a;
int combination[101];

void printOut(int m)
{
    cout << "[";
    for (int i = 1; i < m; i++)
    {
        cout << combination[i] << " ";
    }
    cout << combination[m] << "]";
}
void backtrack(int i, int s)
{
    for (int j = 1; j <= n; j++)
    {
        if (a[j] >= combination[i - 1] && s + a[j] <= x)
        {
            combination[i] = a[j];
            s = s + a[j];
            if (s == x)
            {
                thereIsACombination++;
                printOut(i);
            }
            else
            {
                backtrack(i + 1, s);
            }
            s = s - a[j];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        backtrack(1, 0);
        if (thereIsACombination > 0)
        {
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}