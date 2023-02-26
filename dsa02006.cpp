// DÃY CON TỔNG BẰNG K
// Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K. Hãy đưa ra tất cả
// các dãy con của dãy số A[] sao cho tổng các phần tử của dãy con đó đúng
// bằng K. Các phần tử của dãy số A[] được giả thuyết là nguyên dương và
// không có các phần tử giống nhau. Ví dụ với dãy con
// A[] = {5, 10, 15, 20, 25}, K = 50 ta có 3 dãy con
// {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần:
// phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[] và số K;
// dòng tiếp theo đưa vào N phần tử của dãy số A[]. T, N, A[i] thỏa mãn
// ràng buộc: 1≤T ≤100; 1≤N≤10; 1≤ K, A[i] ≤100.
// Output:
// Đưa ra tất cả các dãy con của dãy số A[] thỏa mãn yêu cầu bài toán
// theo thứ tự từ điển, trong đó mỗi dãy con được bao bởi các ký tự [, ].
// Nếu không có dãy con nào thỏa mãn yêu cầu bài toán, hãy đưa ra -1.

// Input                           Output
// 2                               [5 10 15 20] [5 20 25] [10 15 25]
// 5 50                            [8 9 14 22] [8 14 15 16] [15 16 22]
// 5  10 15 20  25
// 8  53
// 15  22  14  26  32  9  16  8

#include <bits/stdc++.h>
using namespace std;

int n, k, numOfCombinations;
int a[11] = {}, combinations[11] = {};

int partition(int array[], int left, int right)
{
    int key = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (a[j] < key)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}
void quickSort(int array[], int left, int right)
{
    if (left < right)
    {
        int key = partition(array, left, right);
        quickSort(array, left, key - 1);
        quickSort(array, key + 1, right);
    }
}
void init()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    numOfCombinations = 0;
    combinations[0] = -1; // Khử trường hợp có phần tử A[i]=0
    quickSort(a, 1, n);   // Làm cho sinh thiếu tổ hợp chứa phần tử 0
}

void printOut(int m)
{
    cout << "[";
    for (int i = 1; i < m; i++)
    {
        cout << combinations[i] << " ";
    }
    cout << combinations[m] << "] ";
}
void backtrack(int index, int sum)
{
    for (int j = 1; j <= n; j++)
    {
        if (a[j] > combinations[index - 1])
        {
            if (sum + a[j] < k)
            {
                combinations[index] = a[j];
                backtrack(index + 1, sum + a[j]);
            }
            else if (sum + a[j] == k)
            {
                numOfCombinations++;
                combinations[index] = a[j];
                printOut(index);
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
        init();
        backtrack(1, 0);
        if (numOfCombinations == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << endl;
        }
    }
}