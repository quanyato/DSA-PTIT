// Di chuyển trong mê cung 1
// Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị
// phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến
// ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:
// Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
// Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
// Hãy đưa ra một hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột
// không thể đi đến đích.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần:
// phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo
// đưa vào ma trận nhị phân A[N][N].
// T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤10; 0≤A[i][j] ≤1.
// Output:
// Đưa ra tất cả đường đi của con chuột trong mê cung theo thứ tự từ điển.
// Đưa ra -1 nếu chuột không đi được đến đích.

// Input                   Output
// 2                       DRDDRR
// 4                       DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD DRRRRDDD
// 1  0  0  0
// 1  1  0  1
// 0  1  0  0
// 1  1  1  1
// 5
// 1 0 0 0 0
// 1 1 1 1 1
// 1 1 0 0 1
// 0 1 1 1 1
// 0 0 0 1 1

#include <bits/stdc++.h>
using namespace std;

int n, numOfPath;
int a[11][11];
vector<string> path;

void selectionSort()
{
    for (int i = 1; i < numOfPath; i++)
    {
        string temp = path[i];
        int j = i - 1;
        while (j >= 0 && path[j] > temp)
        {
            path[j + 1] = path[j];
            j--;
        }
        path[j + 1] = temp;
    }
}

void init()
{
    path.clear();
    numOfPath = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void startWalk(int i, int j, string s)
{
    if (a[i][j] == 0)
    {
        return;
    }
    if (i == n && j == n)
    {
        numOfPath++;
        path.push_back(s);
    }
    else
    {
        if (a[i + 1][j] == 1 && i + 1 <= n)
        {
            startWalk(i + 1, j, s + "D");
        }
        if (a[i][j + 1] == 1 && j + 1 <= n)
        {
            startWalk(i, j + 1, s + "R");
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        startWalk(1, 1, "");
        if (numOfPath == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            selectionSort();
            for (int i = 0; i < numOfPath; i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }
    }
}