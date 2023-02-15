// Xau nhi phan co k bit 1
// Hãy in ra tất cả các xâu nhị phân độ dài N, có K bit 1 theo thứ tự từ điển tăng dần.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm 2 số nguyên N, K (1 ≤ K ≤ N ≤ 16).
// Output:  Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.

// Ví dụ:
// Input               Output
// 2
// 4 2                 0011
//                     0101
//                     0110
//                     1001
//                     1010
//                     1100
// 3 2                 011
//                     101
//                     110

#include <bits/stdc++.h>
using namespace std;

void out(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void daonguoc(int a[], int stap, int endp)
{
    while (stap < endp)
    {
        swap(a[stap], a[endp]);
        stap++;
        endp--;
    }
}

void sinh_hv(int a[], int n)
{
    while (1)
    {
        out(a, n);
        int i = n - 1;
        while (a[i] >= a[i + 1])
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
            while (a[j] == 0)
            {
                j--;
            }
            swap(a[i], a[j]);
            daonguoc(a, i + 1, n);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a[20] = {};
        cin >> n >> k;
        for (int i = n; i > 0; i--)
        {
            if (k > 0)
            {
                a[i] = 1;
            }
            else
            {
                a[i] = 0;
            }
            k--;
        }
        sinh_hv(a, n);
    }
}