#include <bits/stdc++.h>
using namespace std;

int a[7] = {};
int binArray[7] = {};

void printOut(int n)
{
    for (int j = 1; j <= n; j++)
    {
        int tmp = 64 + a[j];
        cout << (char)tmp;
    }
    for (int j = 1; j <= n; j++)
    {
        cout << binArray[j];
    }
    cout << endl;
}

void sinhth(int n)
{
    for (int i = 1; i <= n; i++)
    {
        binArray[i] = 1;
    }
    while (1)
    {
        printOut(n);
        int i = n;
        while (binArray[i] == n)
        {
            i--;
        }
        if (i == 0)
        {
            break;
        }
        else
        {
            binArray[i]++;
            for (int j = i + 1; j <= n; j++)
            {
                binArray[j] = binArray[j - 1];
            }
        }
    }
}

void DaoNguoc(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void sinhhv(int n)
{
    while (1)
    {
        sinhth(n);

        int i = n - 1;
        while (a[i] > a[i + 1])
        {
            i--;
        }
        if (i == 0)
        {
            break;
        }
        else
        {
            int j = n;
            while (a[i] > a[j])
            {
                j--;
            }
            swap(a[i], a[j]);
            DaoNguoc(a, i + 1, n);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    sinhhv(n);
    cout << endl;
}