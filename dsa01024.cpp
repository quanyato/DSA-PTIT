// ĐẶT TÊN 1
// Kỳ thi ICPC có K đội của PTIT tham gia và đội tuyển đang rất đau đầu không
// biết chọn các cái tên như thế nào cho các đội. Yêu cầu phải đảm bảo tên
// không có khoảng trống và không được trùng nhau. Sau khi thảo luận, có N
// cái tên được đề xuất (có thể bị trùng nhau). Với K<15 và 4 < N < 30.
// Hãy liệt kê tất cả danh sách các tổ hợp K cái tên khác nhau có thể được
// tạo ra theo thứ tự từ điển.

// Input
// Dòng đầu ghi 2 số N và K.
// Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên có độ dài không quá 15
// và cách nhau một khoảng trống. Tất cả đều là ký tự in hoa.
// Output
// Ghi ra tất cả các tổ hợp tên có thể được lựa chọn theo thứ tự từ điển.
// Tức là các tên trong mỗi tổ hợp liệt kê theo thứ tự từ điển và các tổ
// hợp cũng được liệt kê theo thứ tự từ điển.

// Ví dụ
// Input                       Output
// 6 2                         BAC DONG
// DONG TAY NAM BAC TAY BAC    BAC NAM
//                             BAC TAY
//                             DONG NAM
//                             DONG TAY
//                             NAM TAY

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> a;
vector<int> combination;

void insertSort(int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        string tmp = a[i];
        int j = i - 1;
        while (j >= l && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}
void formatSrcArray()
{
    insertSort(1, n);
    int i = 1;
    while (i < n)
    {
        if (a[i] == a[i + 1])
        {
            n--;
            for (int j = i + 1; j <= n; j++)
            {
                a[j] = a[j + 1];
            }
        }
        else
        {
            i++;
        }
    }
}

void printOut()
{
    for (int i = 1; i <= k; i++)
    {
        cout << a[combination[i]] << " ";
    }
    cout << endl;
}
void backtrack(int index)
{
    for (int j = combination[index - 1] + 1; j <= n - k + index; j++)
    {
        combination[index] = j;
        if (index == k)
        {
            printOut();
        }
        else
        {
            backtrack(index + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    a.resize(n + 1);
    combination.resize(k + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    formatSrcArray();
    backtrack(1);
}