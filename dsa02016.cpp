// SAP XEP QUAN HAU - 1
// Cho một bàn cờ vua có kích thước n * n, ta biết ràng quân hậu có thể
// di chuyển theo chiều ngang, dọc, chéo. Vấn đề đặt ra rằng, có n
// quân hậu, bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho
// với 2 quân hậu bất kì, chúng không “ăn” nhau.

// Input: Dòng đầu ghi số bộ test T (T<5). Mỗi bộ test ghi một số nguyên
// dương n duy nhất (không quá 10)
// Output:  Ghi kết quả mỗi bộ test trên một dòng. Số cách đặt quân hậu.

// Ví dụ:
// Input           Output
// 1               2
// 4

#include <bits/stdc++.h>
using namespace std;

int n, dem;
int cot[30], cheochinh[30], cheophu[30];

void solve(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!cot[j] && !cheochinh[i - j + n] && !cheophu[i + j - 1])
        {
            cot[j] = cheochinh[i - j + n] = cheophu[i + j - 1] = 1;
            if (i == n)
            {
                dem++;
            }
            else
            {
                solve(i + 1);
            }
            cot[j] = cheochinh[i - j + n] = cheophu[i + j - 1] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        dem = 0;
        cin >> n;
        solve(1);
        cout << dem << endl;
    }
}