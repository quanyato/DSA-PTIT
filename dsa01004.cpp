// SINH TO HOP
// Cho hai số nguyên dương N và K. Nhiệm vụ của bạn là hãy liệt kê tất cả các
// tập con K phần tử của 1, 2, .., N. Ví dụ với N=5, K=3 ta có 10 tập con của
// 1, 2, 3, 4, 5 như sau: {1, 2, 3}, {1, 2, 4},{1, 2, 5},{1, 3, 4},{1, 3, 5},
// {1, 4, 5},{2, 3, 4},{2, 3, 5},{2, 4, 5},{3, 4, 5}.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một cặp số tự nhiên N, K được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T≤100; 1≤k ≤ n≤15.

// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input:                Output:
// 2
// 4  3                 123 124 134 234
// 5  3                 123 124 125 134 135 145 234 235 245 345

#include <bits/stdc++.h>
using namespace std;

void sinhth(int n, int k, int a[1000])
{
    while (1)
    {
        for (int j = 1; j <= k; j++) // in ra to hop
        {
            cout << a[j];
        }
        cout << " ";

        // sinh to hop ke tiep
        int i = k;
        while (a[i] == n - k + i)
        {
            i--;
        }
        if (i == 0)
        {
            break;
        }
        else
        {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
            {
                a[j] = a[j - 1] + 1;
            }
        }
    }
}

int main()
{
    int n, k, t;
    cin >> t;
    while (t--)
    {
        int a[50] = {};
        cin >> n >> k;
        for (int i = 0; i <= k; i++)
        {
            a[i] = i;
        }
        sinhth(n, k, a);
        cout << endl;
    }
}