// LIET KE TO HOP
// Cho dãy số A[] có N phần tử. Hãy liệt kê tất cả các tổ hợp chập K của tập
// các phần tử khác nhau trong A[]. Các tổ hợp cần liệt kê theo thứ tự từ điển
// (tức là trong mỗi tổ hợp thì giá trị từ nhỏ đến lớn, và tổ hợp sau lớn hơn
// tổ hợp trước).

// Input
// Dòng đầu ghi hai số N và K.
// Dòng thứ 2 ghi N số của mảng A[]. Các giá trị không quá 1000.
// Dữ liệu đảm bảo số phần tử khác nhau của A[] không quá 20 và K không quá 10.
// Output
// Ghi ra lần lượt các tổ hợp tìm được, mỗi tổ hợp trên một dòng.

// Ví dụ
// Input                   Output
// 8 3                     1 2 3
// 2 4 4 3 5 1 3 4         1 2 4
//                         1 2 5
//                         1 3 4
//                         1 3 5
//                         1 4 5
//                         2 3 4
//                         2 3 5
//                         2 4 5
//                         3 4 5

#include <bits/stdc++.h>
using namespace std;

int n, k;
int combinationIndex[11] = {};

void insertSort(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 1 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}
void formatSrcArray(int a[])
{
    insertSort(a, 1, n);
    int i = 1;
    while (i < n)
    {
        if (a[i] == a[i + 1])
        {
            n--;
            for (int j = i + 1; j <= n; j++)
            {
                a[j] = a[j + 1];
            }
        }
        else
        {
            i++;
        }
    }
}

void generateFirstCombin(int a[])
{
    for (int i = 1; i <= k; i++)
    {
        combinationIndex[i] = i;
    }
}

void generateNextCombin(int a[])
{
    while (1)
    {
        for (int j = 1; j <= k; j++) // in ra to hop
        {
            cout << a[combinationIndex[j]] << " ";
        }
        cout << endl;

        // sinh to hop ke tiep
        int i = k;
        while (combinationIndex[i] == n - k + i)
        {
            i--;
        }
        if (i == 0)
        {
            break;
        }
        else
        {
            combinationIndex[i]++;
            for (int j = i + 1; j <= k; j++)
            {
                combinationIndex[j] = combinationIndex[j - 1] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    formatSrcArray(a);
    generateFirstCombin(a);
    generateNextCombin(a);
}