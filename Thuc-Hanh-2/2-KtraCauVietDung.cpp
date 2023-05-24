#include<bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> st;

    for (char i : s) {
        if (i == '(' || i == '[') {
            st.push(i);
        }
        else if (i == ')') {
            if (st.empty() || st.top() == '[') {
                return false;
            }
            else {
                st.pop();
            }
        }
        else if (i == ']') {
            if (st.empty() || st.top() == '(') {
                return false;
            }
            else {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        if (check(s)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}