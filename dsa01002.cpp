// Tap con ke tiep
// Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N.
// Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử tiếp theo của X[].
// Ví dụ N=5, K=3, X[] ={2, 3, 4} thì tập con tiếp theo của X[] là {2, 3, 5}.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
// T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input               Output
// 2
// 5  3
// 1  4  5             2 3 4
// 5  3
// 3  4  5             1 2 3

#include <bits/stdc++.h>
using namespace std;

void sinhth(int n, int k, int a[1000])
{
    int i = k;
    while (a[i] == n - k + i)
    {
        i--;
    }
    if (i == 0)
    {
        for (int j = 1; j <= k; j++)
        {
            a[j] = j;
        }
    }
    else
    {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
    for (int j = 1; j <= k; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
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
        sinhth(n, k, a);
    }
}