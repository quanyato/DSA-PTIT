#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n) {
    int dientich = 0;
    stack<int> st;
    int i = 0;
    while (i < n) {
        if (st.empty() || a[i] > a[st.top()]) {
            st.push(i);
            i++;
        }
        else {
            int index = st.top();
            st.pop();
            if (st.empty()) {
                dientich = max(dientich, i * a[index]);
            }
            else {
                dientich = max(dientich, a[index] * (i - st.top() - 1));
            }
        }
    }
    while (!st.empty()) {
        int index = st.top();
        st.pop();
        if (st.empty()) {
            dientich = max(dientich, i * a[index]);
        }
        else {
            dientich = max(dientich, a[index] * (i - st.top() - 1));
        }
    }
    return dientich;
}

int main() {
    int n, m;
    cin >> m >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = m - a[i];
    }
    int dientich = 0;
    dientich = max(dientich, solve(a, n));
    dientich = max(dientich, solve(b, n));
    cout << dientich;
}