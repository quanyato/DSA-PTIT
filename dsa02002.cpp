// DÃY SỐ - 2
// Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt của dãy số A[] là
// tam giác được tạo ra bởi n hàng, trong đó hàng thứ n là dãy số A[], hàng i
// là tổng hai phần tử liên tiếp của hàng i+1 (1≤i≤n-1). Ví dụ
// A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:

// [48] [20, 28] [8, 12, 16] [3, 5, 7, 9 ] [1, 2, 3, 4, 5 ]

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng
// thứ nhất đưa vào N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa
// vào N số của mảng A[].
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10;
// Output:
// Đưa ra kết quả mỗi test theo từng dòng. Mỗi dòng của tam giác tổng được
// bao bởi ký tự [, ].

// Input           Output
// 1
// 5
// 1 2 3 4 5       [48] [20 28] [8 12 16] [3 5 7 9 ] [1 2 3 4 5 ]

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> out;
int outVectorIndex;

void printOut()
{
    for (outVectorIndex = 0; outVectorIndex < out.size(); outVectorIndex++)
    {

        cout << "[";
        for (int i = 0; i < out[outVectorIndex].size(); i++)
        {
            cout << out[outVectorIndex][i];
            if (i != out[outVectorIndex].size() - 1)
            {
                cout << " ";
            }
        }
        cout << "] ";
    }
    cout << endl;
}

void importToOutVector()
{
    out[outVectorIndex].resize(n);
    for (int i = 0; i < n; i++)
    {
        out[outVectorIndex][i] = a[i];
    }
    outVectorIndex--;
}
void backTrack()
{
    importToOutVector();
    n--;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i] + a[i + 1];
        }
        backTrack();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        out.resize(n);
        outVectorIndex = n - 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        backTrack();
        printOut();
    }
}