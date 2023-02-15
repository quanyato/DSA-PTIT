// Sap xep theo gia tri tuyet doi
// Cho mảng A[] gồm n phần tử và số X. Hãy đưa sắp xếp các phần tử của mảng theo trị tuyệt đối
// của |X - A[i] |. Ví dụ với A[] = {10, 5, 3, 9, 2} và X = 7 ta đưa ra mảng được sắp xếp theo
// nguyên tắc kể trên: A[] = {5, 9, 10, 3, 2} vì |7-10|=3, |7-5|=2, |7-3|=4, |7-9|=2, |7-2|=5.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử
// của mảng n và X; dòng tiếp theo là n số A [i] của mảng A [];các số được viết cách nhau một vài
// khoảng trống.
// T, n, X thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, X, A[i] ≤105.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input:                  Output:
// 2
// 5 7
// 10 5 3 9 2              5 9 10 3 2
// 5 6
// 1 2 3 4 5               5 4 3 2 1

#include <bits/stdc++.h>
using namespace std;

void insertSort(int a[], int l, int r, int x)
{
    for (int i = l; i <= r; i++)
    {
        int tmp = a[i];
        int abstmp = abs(x - a[i]);
        int j = i - 1;
        while (j >= 0 && abs(x - a[j]) > abstmp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        int a[100000];
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        insertSort(a, 0, n - 1, x);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}