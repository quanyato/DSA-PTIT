// PHAT LOC
// Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc”
// nếu thỏa mãn các điều kiện sau:

// Độ dài xâu ít nhất là 6
// Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6
// Không có 2 chữ số 8 nào ở cạnh nhau
// Không có nhiều hơn 3 chữ số 6 ở cạnh nhau.
// Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.

// Input
// Chỉ có 1 dòng ghi số N (5 < N < 16).
// Output
// Ghi ra các xâu ký tự phát lộc độ dài N, mỗi xâu trên một dòng.

// Ví dụ
// Input               Output
// 6                   866686
//                     866866
//                     868666
//                     868686

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
            cout << 8;
        }
        else
        {
            cout << 6;
        }
    }
    cout << endl;
}

void checkCase()
{
    int numOfSix = 0;
    if (gArray[1] != 1)
    {
        return;
    }
    if (gArray[N] != 0)
    {
        return;
    }
    for (int index = 1; index <= N; index++)
    {
        if (gArray[index] == 1)
        {
            numOfSix = 0;
            if (gArray[index + 1] == 1)
            {
                return;
            }
        }
        else
        {
            numOfSix++;
        }
        if (numOfSix > 3)
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
    cin >> N;
    tryCase(1);
}