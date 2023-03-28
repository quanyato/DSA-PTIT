// Ngày đặc biệt
// Liệt kê tất cả các ngày hợp lệ chỉ gồm số 0 và 2 tính từ
// năm 2000. In ra mỗi ngày trên một dòng theo đúng format
// 02/02/2000 và sắp xếp theo thứ tự từ điển.

// Input           Output
//                 02/02/2000
//                 02/02/2002
//                 02/02/2020
//                 02/02/2022
//                 02/02/2200
//                 02/02/2202
//                 02/02/2220
//                 02/02/2222
//                 20/02/2000
//                 20/02/2002
//                 20/02/2020
//                 20/02/2022
//                 20/02/2200
//                 20/02/2202
//                 20/02/2220
//                 20/02/2222
//                 22/02/2000
//                 22/02/2002
//                 22/02/2020
//                 22/02/2022
//                 22/02/2200
//                 22/02/2202
//                 22/02/2220
//                 22/02/2222

#include <bits/stdc++.h>
using namespace std;

string pre[3] = {"02/02/2", "20/02/2", "22/02/2"};
vector<string> specialDay;

void backtrack(int index)
{
    for (int i = 0; i <= 2; i += 2)
    {
        for (int j = 0; j < 3; j++)
        {
            pre[j] += (char)48 + i;
        }
        if (index == 3)
        {
            for (int j = 0; j < 3; j++)
            {
                specialDay.push_back(pre[j]);
            }
        }
        else
        {
            backtrack(index + 1);
        }
        for (int j = 0; j < 3; j++)
        {
            pre[j].pop_back();
        }
    }
}

int main()
{
    backtrack(1);
    sort(specialDay.begin(), specialDay.end());
    int n = specialDay.size();
    for (int i = 0; i < n; i++)
    {
        cout << specialDay[i] << endl;
    }
}