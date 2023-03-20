// LUY THUA DAO
// Cho mảng số N. Ta gọi số đảo của N là R. Hãy tìm lũy thừa R của N.
// Đưa ra kết quả của bài toán dưới dạng modulo với 1e9 + 7.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm là số N được
// ghi trên một dòng.
// T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1010.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Ví dụ:
// Input           Output
// 2               4
// 2               864354781
// 12

#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;

long long rev(long long n)
{
    long long res = 0;
    while (n > 0)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

long long powMod(long long n, long long k)
{
    if (k == 0)
    {
        return 1;
    }
    long long x = powMod(n, k / 2);
    if (k % 2 == 0)
    {
        return x * x % M;
    }
    return n * (x * x % M) % M;
}

int main()
{
    long long t, n, r;
    cin >> t;
    while (t--)
    {
        cin >> n;
        r = rev(n);
        cout << powMod(n, r) << endl;
    }
}