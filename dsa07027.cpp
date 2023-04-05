#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[i] >= st.top()) {
            st.pop();
        }
        if (st.empty()) {
            b[i] = -1;
        }
        else {
            b[i] = st.top();
        }
        st.push(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
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