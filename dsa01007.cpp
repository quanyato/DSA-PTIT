// Xau AB co do dai n

// Xâu ký tự str được gọi là xâu AB nếu mỗi ký tự trong xâu hoặc là ký tự ‘A’ hoặc là
// ký tự ‘B’. Ví dụ xâu str=”ABBABB” là xâu AB độ dài 6. Nhiệm vụ của bạn là hãy
// liệt kê tất cả các xâu AB có độ dài n.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên n.
// T, n thỏa mãn ràng buộc: 1≤T≤10; 1≤n≤10.

// Output:
// Đưa ra kết quả mỗi test theo từng dòng. Mỗi xâu cách nhau 1 khoảng trống.

// Input           Output
// 2
// 2               AA AB BA BB
// 3               AAA AAB ABA ABB BAA BAB BBA BBB

#include <bits/stdc++.h>
using namespace std;

void sinh_np(int n)
{
    char a[11];
    for (int i = 1; i <= n; i++)
    { // sinh cau hinh dau
        a[i] = 'A';
    }

    while (1)
    {
        // in ra cau hinh
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << " ";

        // sinh cau hinh ke
        int i = n;
        while (a[i] == 'B')
        {
            i--;
        }
        if (i == 0)
        {
            break;
        }
        else
        {
            a[i] = 'B';
            for (int j = i + 1; j <= n; j++)
            {
                a[j] = 'A';
            }
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
        sinh_np(n);
        cout << endl;
    }
}