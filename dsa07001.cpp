// NGĂN XẾP 1
// Cho một ngăn xếp các số nguyên. Các thao tác gồm 3 lệnh: push, pop và show.
// Trong đó thao tác push kèm theo một giá trị cần thêm (không quá 1000).
// Hãy viết chương trình ghi ra kết quả của các lệnh show.

// Input: Gồm nhiều dòng, mỗi dòng chứa một lệnh push, pop hoặc show. Input
// đảm bảo số lượng phần tử trong stack khi nhiều nhất cũng không vượt quá 200.
// Output: Ghi ra màn hình các phần tử đang có trong stack theo thứ tự lưu trữ
// mỗi khi gặp lệnh show. Các số viết cách nhau đúng một khoảng trống.
// Nếu trong stack không còn gì thì in ra dòng “empty”.
// Chương trình dừng khi không nhập gì.

// Ví dụ:
// Input           Output
// push 3          3 5
// push 5          3 5 7
// show            3
// push 7
// show
// pop
// pop
// show

#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    string s;
    vector<int> v;
    while (cin >> s) {
        if (s == "push") {
            cin >> x;
            v.push_back(x);
        }
        else if (s == "pop") {
            if (!v.empty()) {
                v.pop_back();
            }
        }
        else if (s == "show") {
            if (v.empty())
                cout << "empty";
            else
                for (int i : v) cout << i << " ";
            cout << endl;
        }
    }
}