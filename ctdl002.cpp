// Tong day con = k
// Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K. Hãy viết chương trình liệt kê tất
// cả các dãy con của dãy số A[] sao cho tổng các phần tử trong dãy con đó đúng bằng K.

// Input: Dữ liệu vào trên bàn phím (n=5, K=50), 5 số dòng thứ 2 là các phần tử dãy A:
// Output: Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:
// Mỗi dòng ghi lại một dãy con. Hai phần tử khác nhau của dãy con được viết cách nhau bởi một
// khoảng trống. Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.

// Input                   Output
// 5 50
// 5 10 15 20 25           10 15 25
//                         5 20 25
//                         5 10 15 20
//                         3

#include <bits/stdc++.h>
using namespace std;

void out(int a[], int x[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int sum(int a[], int x[], int n)
{
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            tong = tong + a[i];
        }
    }
    return tong;
}

int main()
{
    int n, k, i, dem = 0;
    cin >> n >> k;
    int a[n + 1], x[n + 1] = {};
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (1)
    {
        if (sum(a, x, n) == k)
        {
            out(a, x, n);
            dem++;
        }
        i = n;
        while (x[i] == 1)
        {
            i--;
        }
        if (i == 0)
        {
            break;
        }
        else
        {
            x[i] = 1;
            for (int j = i + 1; j <= n; j++)
            {
                x[j] = 0;
            }
        }
    }
    cout << dem;
}