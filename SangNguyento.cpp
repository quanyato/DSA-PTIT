#include <bits/stdc++.h>
using namespace std;

bool isAPrimeNumber = 0;
bool a[25] = {};

void sangNT()
{
    a[0] = not isAPrimeNumber;
    a[1] = not isAPrimeNumber;
    for (int i = 2; i <= sqrt(25); i++)
    {
        if (a[i] == isAPrimeNumber)
        {
            for (int j = i * i; j <= 25; j = j + i)
            {
                a[j] = not isAPrimeNumber;
            }
        }
    }
}

int main()
{
    sangNT();

    if (a[7] == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    int n;
    cin >> n;
}