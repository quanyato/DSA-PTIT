#include<bits/stdc++.h>
using namespace std;

long long calculation(long long a, long long b, char x) {
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
    int k;
    cin >> k; cin.ignore();
    string s, tmp;
    getline(cin, s);
    stringstream ss(s);
    stack<long long> st;

    for (int i = 0; i < k; i++) {
        ss >> tmp;
        if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") {
            long long b = st.top();
            st.pop();
            long long a = st.top();
            st.pop();
            st.push(calculation(a, b, tmp[0]));
        }
        else {
            st.push(stoll(tmp));
        }
    }
    cout << st.top();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}