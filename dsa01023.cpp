// Số thứ tự tổ hợp
// Cho một tổ hợp chập K của N số nguyên dương đầu tiên (2 < K < N < 15).
// Hãy xác định xem đó là tổ hợp thứ bao nhiêu nếu liệt kê tất cả các tổ
// hợp theo thứ tự tăng dần (tính từ 1).

// Input:
// Dòng đầu ghi số T là số bộ test (T < 10)
// Mỗi bộ test gồm 2 dòng:
// Dòng đầu ghi 2 số nguyên dương N và K (2 < K < N < 15)
// Dòng tiếp theo ghi một tổ hợp chập K của các số nguyên dương từ 1 đến N.
// Output:
// Với mỗi bộ test, ghi ra trên một dòng số thứ tự của tổ hợp (tính từ 1,
// theo thứ tự liệt kê tăng dần).

// Ví dụ:
// Input                   Output
// 2                       9
// 6 4                     12
// 1 3 5 6
// 6 4
// 2 3 4 6

#include <bits/stdc++.h>
using namespace std;

int n, k;
int combinationArray[20] = {};

int compare(int firstCombination[], int seccondCombination[]);
int detectCombination();
void generation(int combination[]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> combinationArray[i];
        }
        cout << detectCombination() << endl;
    }
}

int detectCombination()
{
    int ordinalNumber = 0;
    bool combinationDetected = false;
    int newCombination[k + 1];
    for (int i = 1; i <= k; i++)
    {
        newCombination[i] = i;
    }

    while (not combinationDetected)
    {
        ordinalNumber++;
        if (compare(combinationArray, newCombination) == true)
        {
            combinationDetected = true;
        }
        else
        {
            generation(newCombination);
        }
    }
    return ordinalNumber;
}

int compare(int firstCombination[], int seccondCombination[])
{
    for (int i = 1; i <= k; i++)
    {
        if (firstCombination[i] != seccondCombination[i])
        {
            return 0;
        }
    }
    return 1;
}

void generation(int combination[])
{
    int i = k;
    while (combination[i] == n - k + i)
    {
        i--;
    }
    combination[i]++;
    for (int j = i + 1; j <= k; j++)
    {
        combination[j] = combination[j - 1] + 1;
    }
}