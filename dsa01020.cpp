// Xau nhi phan truoc
// Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân trước của X[].
// Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”. Với xâu X[] =“000001”
// thì xâu nhị trước của X[] là “000000”. Chú ý: nếu xâu dữ liệu trong input là xâu đầu
// tiên thì trước nó sẽ là xâu cuối cùng.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
// T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤10^3.

// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Ví dụ:
// Input           Output
// 2
// 010101           010100
// 111111           111110

#include <bits/stdc++.h>
using namespace std;

void sinh_np(string str)
{
    string x = '1' + str;
    int n = str.length();
    int i = n;
    while (x[i] == '0')
    {
        i--;
    }
    x[i] = '0';
    for (int j = i + 1; j <= n; j++)
    {
        x[j] = '1';
    }
    x.erase(0, 1);
    cout << x << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string x;
        getline(cin, x);
        sinh_np(x);
    }
}