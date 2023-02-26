// TO HOP SO CO TONG BANG X
// Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của
// bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số
// trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của
// mảng A[] được in ra theo thứ tự không giảm các số. Ví dụ với
// A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:
// [2, 2, 2, 2], [2, 2, 4], [2, 6], [4, 4], [8].

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng. Mỗi đường tổ hợp được bao bởi cặp ký tự [, ]. Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.

// Input               Output
// 1                   [2 2 2 2] [2 2 4] [2 6] [4 4] [8]
// 4  8
// 2  4  6  8

#include <bits/stdc++.h>
using namespace std;

int n, x, thereIsACombination = 0;
vector<int> a;
int combination[101];

void printOut(int m)
{
    cout << "[";
    for (int i = 1; i < m; i++)
    {
        cout << combination[i] << " ";
    }
    cout << combination[m] << "]";
}
void backtrack(int i, int s)
{
    for (int j = 1; j <= n; j++)
    {
        if (a[j] >= combination[i - 1] && s + a[j] <= x)
        {
            combination[i] = a[j];
            s = s + a[j];
            if (s == x)
            {
                thereIsACombination++;
                printOut(i);
            }
            else
            {
                backtrack(i + 1, s);
            }
            s = s - a[j];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        backtrack(1, 0);
        if (thereIsACombination > 0)
        {
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}