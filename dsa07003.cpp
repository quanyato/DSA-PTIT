// Kiem tra bieu thuc so hoc
// Cho biểu thức số học, hãy cho biết biểu thức số học có
// dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test.
// Mỗi bộ test là một biểu thức.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:
// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.

// Ví dụ:
// Input                   Output
// 3                       Yes
// ((a+b))                 Yes
// (a + (b)/c)             No
// (a + b*(c-d))

#include<bits/stdc++.h>
using namespace std;

void solve() {
    cin.ignore();
    string s;
    cin >> s;
    int n = s.length(), tmp;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (s[i + 2] == ')') {
                cout << "Yes";
                return;
            }
            else {
                st.push(i);
            }
        }
        else if (s[i] == ')') {
            tmp = st.top();
            st.pop();
            if (s[i + 1] == ')' && tmp - st.top() == 1) {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}