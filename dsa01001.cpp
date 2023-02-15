// Xau nhi phan ke tiep
// Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân tiếp theo của X[].
// Ví dụ X[] =”010101” thì xâu nhị phân tiếp theo của X[] là “010110”.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
// T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Input               Output
// 2
// 010101              010110
// 111111              000000

#include <bits/stdc++.h>

using namespace std;

void sinhnp(string text)
{
    string s = '0' + text;
    int n = s.length();
    int i = n - 1;
    while (s[i] == '1')
    {
        i--;
    }
    s.replace(i, 1, "1");
    for (int j = i + 1; j < n; j++)
    {
        s.replace(j, 1, "0");
    }
    s.erase(0, 1);
    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        sinhnp(s);
    }
}