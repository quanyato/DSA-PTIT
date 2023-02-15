// Thuat toan sinh
// Một xâu nhị phân độ dài n được gọi là thuận nghịch hay đối xứng nếu đảo ngược xâu
// nhị phân đó ta vẫn nhận được chính nó. Cho số tự nhiên n (n nhập từ bàn phím).
// Hãy viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n.
// Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một khoảng trống.

// Input	   Output
// 4           0 0 0 0
//             0 1 1 0
//             1 0 0 1
//             1 1 1 1

#include <bits/stdc++.h>
using namespace std;

int _a[10000], _n;

void out()
{
    cout << _a[1];
    for (int i = 2; i <= _n; i++)
    {
        cout << " " << _a[i];
    }
    cout << endl;
}

void sinhnp(int n)
{
    for (int i = 0; i <= n; i++)
    {
        _a[i] = 0;
    }
    while (1)
    {
        out();
        int k;
        if (n % 2 == 0)
        {
            k = n / 2;
        }
        else
        {
            k = n / 2 + 1;
        }
        int i = k;
        while (_a[i])
        {
            i--;
        }
        _a[i] = 1;
        _a[n - i + 1] = 1;
        for (int j = i + 1; j <= k; j++)
        {
            _a[j] = 0;
            _a[n - j + 1] = 0;
        }
        if (i == 0)
        {
            break;
        }
    }
}

int main()
{
    cin >> _n;
    sinhnp(_n);
}