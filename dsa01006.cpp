// HOAN VI NGUOC

// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị
// của 1, 2, .., N theo thu tu nguoc.
// Ví dụ với N = 3 ta có kết quả: 321, 312, 231, 213, 132, 123.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T, N≤10.

// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input               Output
// 2
// 2                   21 12
// 3                   321 312 231 213 132 123

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
            cout << a[j];
        }
        cout << " ";

        // sinh cau hinh tiep
        int i = n - 1;
        while (a[i] < a[i + 1])
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
            while (a[i] < a[j])
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
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[20] = {};
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        a[0] = 50;
        DaoNguoc(a, 1, n);
        sinhhv(n, a);
        cout << endl;
    }
}