// To hop tiep theo
// Cho số nguyên dương (1<N<40) và số nguyên dương K<N. Với 1 tổ hợp chập K phần tử của N,
// hãy cho biết tổ hợp tiếp theo sẽ có bao nhiêu phần tử mới. Nếu tổ hợp đã cho là cuối cùng
// thì kết quả là K.

// Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai dòng
// Dòng 1: hai số nguyên dương N và K (K<N)
// Dòng 2 ghi K số của tổ hợp ban đầu. Theo đúng thứ tự tăng dần, không có số nào trùng nhau.
// Kết quả: Với mỗi bộ dữ liệu in ra số lượng phần tử mới.

// Ví dụ:
// INPUT                   OUTPUT
// 3                       1
// 5 3                     2
// 1 3 5                   4
// 5 3
// 1 4 5
// 6 4
// 3 4 5 6

#include <bits/stdc++.h>
using namespace std;

int sinhth(int n, int k, int a[])
{
    int arr[k + 1], i;
    for (i = 1; i <= k; i++)
    {
        arr[i] = a[i];
    }
    i = k;
    while (a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        return k;
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
    int dem = k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (arr[i] == a[j])
            {
                dem--;
            }
        }
    }
    return dem;
}

int main()
{
    int n, k, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a[k + 1] = {};
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        cout << sinhth(n, k, a) << endl;
    }
}