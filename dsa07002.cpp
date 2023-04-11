// NGĂN XẾP 2

// Yêu cầu bạn xây dựng một stack với các truy vấn sau đây:
// “PUSH x”: Thêm phần tử x vào stack (0 ≤ x ≤ 1000).
// “PRINT”: In ra phần tử trên cùng của stack. Nếu stack rỗng, in ra “NONE”.
// “POP”: Xóa phần tử đầu tiên của stack. Nếu stack rỗng, không làm gì cả.

// Input:
// Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).
// Mỗi truy vấn có dạng như trên.
// Output: 
// Với mỗi truy vấn “PRINT”, hãy in ra phần tử đầu tiên của stack.
// Nếu stack rỗng, in ra “NONE”.

// Ví dụ:
// Input:          Output
// 9               1
// PUSH 1          3
// PUSH 2          NONE
// POP
// PRINT
// PUSH 3
// PRINT
// POP
// POP
// PRINT

#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    int q, x;
    string s;
    cin >> q;
    while (q--) {
        cin.ignore();
        cin >> s;
        if (s == "PUSH") {
            cin >> x;
            st.push(x);
        }
        else if (s == "POP" && !st.empty()) {
            st.pop();
        }
        else if (s == "PRINT") {
            if (st.empty()) {
                cout << "NONE" << '\n';
            }
            else {
                cout << st.top() << '\n';
            }
        }
    }
}