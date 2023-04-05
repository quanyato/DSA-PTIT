// Xâu con chung dài nhất
// Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu
// này (các phần tử không nhất thiết phải liên tiếp nhau).

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ
// dài không quá 1000 và chỉ gồm các chữ cái in hoa.
// Output:  Với mỗi test, in ra độ dài dãy con chung dài
// nhất trên một dòng.

// Ví dụ:
// Input           Output
// 2               4
// AGGTAB          0
// GXTXAYB
// AA
// BB

// Giải thích test 1: Dãy con chung là G, T, A, B.

#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b)
{
    int n = a.size(), m = b.size();
    int table[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else
            {

                if (a[i - 1] == b[j - 1])
                {
                    table[i][j] = table[i - 1][j - 1] + 1;
                }
                else
                {
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }
    }
    return table[n][m];
}

int main()
{
    string a, b;
    int t;
    cin >> t;

    while (t--)
    {
        cin.ignore();
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}