// Hoan vi ke tiep
// Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. Nhiệm vụ của bạn là đưa ra
// hoán vị tiếp theo của X[]. Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo
// của X[] là {1, 2, 3, 5, 4}.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số N;
// dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.
// T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input               Output

// 2
// 5
// 1 2 3 4 5           1 2 3 5 4
// 5
// 5 4 3 2 1           1 2 3 4 5

#include <bits/stdc++.h>
using namespace std;

void sinhhv(int n, int a[1000])
{
    int i = n - 1, k;
    if (n % 2 == 0)
    {
        k = n / 2;
    }
    else
    {
        k = n / 2 + 1;
    }
    while (a[i] > a[i + 1])
    {
        i--;
    }
    if (i == 0)
    {
        for (int j = 1; j <= k; j++)
        {
            swap(a[j], a[n - j + 1]);
        }
    }
    else
    {
        int j = n;
        while (a[i] > a[j])
        {
            j--;
        }
        swap(a[i], a[j]);
        for (j = i + 1; j <= k; j++)
        {
            swap(a[j], a[n - j + 1]);
        }
    }
    // in ra man hinh
    for (int j = 1; j <= n; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[1000] = {};
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sinhhv(n, a);
    }
}