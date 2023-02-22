#include <bits/stdc++.h>
using namespace std;

vector<int> check;
vector<int> a;
string s;
int n;

void printOut()
{
    for (int i = 1; i <= n; i++)
    {
        cout << s[a[i] - 1];
    }
    cout << " ";
}
void backtrack(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (check[j] == 0)
        {
            a[i] = j;
            check[j] = 1;
            if (i == n)
            {
                printOut();
            }
            else
            {
                backtrack(i + 1);
            }
            check[j] = 0;
        }
    }
}

void init()
{
    cin >> s;
    n = s.length();
    a.resize(n + 1);
    check.resize(n + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        backtrack(1);
        cout << endl;
    }
}