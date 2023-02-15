// So thu tu hoan vi
// Cho một hoán vị của N số nguyên dương đầu tiên.
// Hãy xác định xem đó là hoán vị thứ bao nhiêu nếu liệt kê theo thứ tự tăng dần (tính từ 1).

// Input:
// Dòng đầu ghi số T là số bộ test (T < 10)
// Mỗi bộ test gồm 2 dòng
// Dòng đầu ghi số nguyên dương N (3 < N < 10)
// Dòng tiếp theo ghi một hoán vị của các số nguyên dương từ 1 đến N.
// Output:
// Với mỗi bộ test, ghi ra trên một dòng số thứ tự của hoán vị (tính từ 1, theo thứ tự liệt kê tăng dần).

// Ví dụ
// Input                   Output
// 2                       6
// 4                       1
// 1 4 3 2
// 4
// 1 2 3 4

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

int sinhhv(int n, int a[], int b[])
{
    int dem = 0;
    while (1)
    {
        // Dem cac cau hinh da so sanh
        dem++;
        // so sanh cau hinh
        int isTrue = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != b[i])
            {
                isTrue = 0;
                break;
            }
        }
        if (isTrue == 1)
        {
            return dem;
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
    return 0;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n + 1] = {}, arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            a[i] = i;
        }
        cout << sinhhv(n, a, arr);
        cout << endl;
    }
}