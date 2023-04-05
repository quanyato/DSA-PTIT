#include<bits/stdc++.h>
using namespace std;

int check(string s) {
    stack<char> st;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
            continue;
        }
        if (st.empty()) {
            return 0;
        }
        if (st.top() == '{') {
            if (s[i] == '}') {
                st.pop();
            }
        }
        else if (st.top() == '[') {
            if (s[i] == ']') {
                st.pop();
            }
        }
        else if (st.top() == '(') {
            if (s[i] == ')') {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (check(s) == 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}