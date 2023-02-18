// DAT TEN 2
// Vương quốc PTIT sử dụng bảng chữ cái gồm N chữ cái Latinh viết hoa.
// Quy tắc đặt tên của gia đình Hoàng gia  PTIT là chọn ra K chữ cái
// (không trùng nhau) và sắp xếp lại theo thứ tự từ điển.
// Hãy liệt kê tất cả các cái tên có thể có của gia đình Hoàng gia PTIT

// Input:
// Dòng đầu ghi số bộ test T (không quá 10)
// Mỗi bộ test ghi 2 số N và K (3 < K < N < 16)
// Output:
// Với mỗi bộ test, ghi ra tất cả các cái tên có thể được tạo ra, mỗi
// kết quả viết trên một dòng.

// Ví dụ:
// Input                   Output
// 1                       AB
// 4 2                     AC
//                         AD
//                         BC
//                         BD
//                         CD

#include <bits/stdc++.h>
using namespace std;

int n, k;

void output(int array[])
{
    for (int i = 1; i <= k; i++)
    {
        int asciiOfCharacter = 64 + array[i];
        cout << (char)asciiOfCharacter;
    }
    cout << endl;
}
void solve(int array[])
{
    while (1)
    {
        output(array);
        int i = k;
        while (array[i] == n - k + i)
        {
            i--;
        }
        if (i == 0)
        {
            break;
        }
        else
        {
            array[i]++;
            for (int j = i + 1; j <= k; j++)
            {
                array[j] = array[j - 1] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
        {
            a[i] = i;
        }
        solve(a);
    }
}