// DOI CHO IT NHAT
// Cho mảng A[] gồm n phần tử. Hãy tìm số phép đổi chỗ ít nhất giữa các
// phần tử của mảng để mảng A[] được sắp xếp. Ví dụ với A[] = {4, 3, 2, 1}
// ta cần thực hiện ít nhất 2 phép đổi chỗ: Swap(A[0], A[3]),
// Swap(A[1], A[2]).

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng n và X; dòng tiếp theo là n số A [i] của mảng A [];các số được viết cách nhau một vài khoảng trống.
// T, n thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input:              Output:
// 2                   2
// 4                   2
// 4 3 2 1
// 5
// 1 5 4 3 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, dem = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            int min = a[i];
            int m = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < min)
                {
                    min = a[j];
                    m = j;
                }
            }
            if (a[i] > min)
            {
                swap(a[i], a[m]);
                dem++;
            }
        }
        cout << dem << endl;
    }
}