#include <bits/stdc++.h>
using namespace std;

int n, k;

void insertSort(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}
void formatSrcArray(int a[])
{
    insertSort(a, 0, n - 1);
    int i = 0;
    while (i < n)
    {
        if (a[i] == a[i + 1])
        {
            for (int j = i + 1; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
        i++;
    }
}

int main()
{
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    formatSrcArray(a);
}