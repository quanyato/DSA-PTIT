// ĐẢO TỪ
// Cho xâu ký tự S. Nhiệm vụ của bạn là đảo ngược các từ trong S.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
// T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.

// Ví dụ:
// Input:                              Output:
// 2
// I like this program very much       much very program this like I
// Go to school                        school to Go

#include<bits/stdc++.h>
using namespace std;

void solve() {
    stack<string> st;
    string s, tmp;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> tmp) {
        st.push(tmp);
    }
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
        cout << '\n';
    }
}