// Cho hai số N và M với 0 < M ≤ N < 10;

// Hãy liệt kê các hoán vị của N số nguyên dương đầu tiên mà số M luôn đứng cuối

// Các hoán vị thỏa mãn cần liệt kê theo thứ tự từ điển.

// Input

// Chỉ có một dòng ghi hai số N và M

// Output

//             Liệt kê lần lượt các hoán vị thỏa mãn. Mỗi hoán vị trên một dòng.

// Ví dụ

// Input

// Output

// 4 2

// 1 3 4 2

// 1 4 3 2

// 3 1 4 2

// 3 4 1 2

// 4 1 3 2

// 4 3 1 2

#include <bits/stdc++.h>
using namespace std;

int n, m;

void DaoNguoc(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void sinhhv(int a[20])
{
    while (1)
    {
        // in ra cau hinh
        if (a[n] == m)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }

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

int main()
{
    cin >> n >> m;
    int a[20] = {};
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    sinhhv(a);
    cout << endl;
}