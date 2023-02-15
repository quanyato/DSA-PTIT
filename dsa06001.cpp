// SAP XEP XEN KE
// Cho mảng A[] gồm n số nguyên khác nhau. Hãy đưa ra các phần tử của mảng theo khuôn dạng lớn nhất,
// nhỏ nhất, lớn thứ hai, nhỏ thứ 2, … Ví dụ với A[] = {9, 7, 12, 8, 6, 5}
// ta đưa ra : 12, 5, 9, 6, 8, 7.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng n; dòng tiếp theo là n số A [i] của mảng A [];các số được viết cách nhau một vài khoảng trống.
// T, n thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input:               Output:
// 2
// 7
// 7 1 2 3 4 5 6        7 1 6 2 5 3 4
// 8
// 1 6 9 4 3 7 8 2      9 1 8 2 7 3 6 4

#include <bits/stdc++.h>
using namespace std;

// Quick sort algorithm
int partition(int a[], int l, int r)
{
    int x = a[r], i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[r], a[i + 1]);
    return i + 1;
}
void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1, l1 = r - m;
    int N[n1], L[l1];
    for (int i = 0; i < n1; i++)
    {
        N[i] = a[i + l];
    }
    for (int i = 0; i < l1; i++)
    {
        L[i] = a[i + m + 1];
    }
    n1 = 0;
    l1--;
    for (int i = l; i <= r; i++)
    {
        if ((i % 2) == 0)
        {
            a[i] = L[l1--];
        }
        else
        {
            a[i] = N[n1++];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[1000];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        quickSort(a, 0, n - 1);
        int m = (n - 2) / 2;
        merge(a, 0, m, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}