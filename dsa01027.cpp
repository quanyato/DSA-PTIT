// HOAN VI DAY SO
// Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một.
// Hãy liệt kê tất cả các hoán vị của dãy số A[] theo thứ tự tăng dần, tức là
// hoán vị đầu tiên có giá trị tăng dần từ trái qua phải, hoán vị cuối cùng
// giảm dần từ trái qua phải.

// Input
// Dòng đầu ghi số N (1 < N < 9)
// Dòng thứ 2 ghi N số của dãy A[] (0 < A[i] < 10000)
// Output
// Ghi mỗi hoán vị của dãy số trên một dòng

// Ví dụ
// Input               Output
// 3
// 88 77 99            77 88 99
//                     77 99 88
//                     88 77 99
//                     88 99 77
//                     99 77 88
//                     99 88 77

#include <bits/stdc++.h>
using namespace std;

void DaoNguoc(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void sinhhv(int n, int a[20])
{
    while (1)
    {
        // in ra cau hinh
        for (int j = 1; j <= n; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;

        // sinh cau hinh tiep
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

int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    insertSort(a, 1, n);
    sinhhv(n, a);
    cout << endl;
}