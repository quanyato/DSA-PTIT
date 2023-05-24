#include<bits/stdc++.h>
using namespace std;

void testcase() {
    int v, e;
    vector<int> u[1005];
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        u[x].push_back(y);
        u[y].push_back(x);
    }
    for (int i = 1; i <= v; i++) {
        cout << i << ':';
        for (auto x : u[i]) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
}