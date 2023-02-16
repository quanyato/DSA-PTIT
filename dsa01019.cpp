// HAHAHA
// Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA để thể hiện sự sảng khoái.
// Đôi khi cũng có thể gõ HAHAAAAA chẳng hạn cho thêm phần nhấn mạnh.

// Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:
// Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A
// Không có hai chữ H nào liền nhau
// Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA theo thứ tự từ điển.

// Input
// Dòng đầu ghi số bộ test T (không quá 10)
// Mỗi bộ test ghi độ dài N (2 <= N < 16)
// Output
// Với mỗi bộ test, ghi ra tất cả các xâu HAHA tìm được theo thứ tự từ điển, mỗi xâu viết trên một dòng.

// Ví dụ
// Input                   Output
// 2                       HA
// 2                       HAAA
// 4                       HAHA

#include <bits/stdc++.h>
using namespace std;

int N;
int gArray[20];

void printOut()
{
    for (int index = 1; index <= N; index++)
    {
        if (gArray[index] == 1)
        {
            cout << "H";
        }
        else
        {
            cout << "A";
        }
    }
    cout << endl;
}

void checkCase()
{
    if (gArray[1] != 1)
    {
        return;
    }
    if (gArray[N] != 0)
    {
        return;
    }
    for (int index = 1; index < N; index++)
    {
        if ((gArray[index] == 1) && (gArray[index + 1] == 1))
        {
            return;
        }
    }
    printOut();
}

void tryCase(int index)
{
    for (int j = 0; j <= 1; j++)
    {
        gArray[index] = j;
        if (index == N)
        {
            checkCase();
        }
        else
        {
            tryCase(index + 1);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N;
        tryCase(1);
    }
}