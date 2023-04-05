// Tinh gia tri bieu thuc hau to
// Hãy viết chương trình chuyển tính toán giá trị của biểu thức hậu tố.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là 
// một biểu thức hậu tố exp. Các số xuất hiện trong biểu thức là các 
// số đơn có 1 chữ số.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.
// Ràng buộc:
// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.

// Ví dụ:
// Input           Output
// 2               -4
// 231*+9-         34
// 875*+9-

#include<bits/stdc++.h>
using namespace std;

int calculation(int a, int b, char x) {
    if (x == '+') {
        return a + b;
    }
    else if (x == '-') {
        return a - b;
    }
    else if (x == '*') {
        return a * b;
    }
    else if (x == '/') {
        return a / b;
    }
    return 0;
}

void solve() {
    string s;
    cin.ignore();
    cin >> s;
    stack<int> st;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            st.push(s[i] - 48);
        }
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(calculation(a, b, s[i]));
        }
    }
    if (!st.empty()) {
        cout << st.top();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}