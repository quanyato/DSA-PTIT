#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

void testCase() {
    int n, k;
    cin >> n >> k;
    long long tmp = 0;
    vector<long long> f(1e5 + 1, 0);
    for (int i = 1; i <= k; ++i) {
        f[i] = tmp + 1;
        f[i] %= M;
        tmp += f[i];
        tmp %= M;
    }
    for (int i = k + 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            f[i] += f[i - j];
            f[i] %= M;
        }
    }
    cout << f[n];
}

int main() {
    int T = 1; cin >> T;
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}