#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    stack<int> st;
    int n = s.length(), dem = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            ++dem;
            st.push(dem);
            cout << dem << ' ';
        }
        else if (s[i] == ')' && !st.empty()) {
            cout << st.top() << ' ';
            st.pop();
        }
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