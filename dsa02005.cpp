// HOAN VI XAU KY TU
// Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. Hãy đưa ra
// tất cả các hoán vị của xâu ký tự S. Ví dụ S=”ABC” ta có kết quả
// {ABC ACB BAC BCA CAB CBA}.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một xâu
// ký tự S được viết trên 1 dòng.
// T, S thỏa mãn ràng buộc: 1≤T≤10; 1≤length(S) ≤10;
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input               Output
// 2
// AB                  AB BA
// ABC                 ABC ACB BAC BCA CAB CBA

#include <bits/stdc++.h>
using namespace std;

vector<int> check;
vector<int> a;
string s;
int n;

void printOut()
{
    for (int i = 1; i <= n; i++)
    {
        cout << s[a[i] - 1];
    }
    cout << " ";
}
void backtrack(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (check[j] == 0)
        {
            a[i] = j;
            check[j] = 1;
            if (i == n)
            {
                printOut();
            }
            else
            {
                backtrack(i + 1);
            }
            check[j] = 0;
        }
    }
}

void init()
{
    cin >> s;
    n = s.length();
    a.resize(n + 1);
    check.resize(n + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        backtrack(1);
        cout << endl;
    }
}