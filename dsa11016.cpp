#include<bits/stdc++.h>
using namespace std;

void testcase() {
    int n, u, v;
    char x;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        s.insert(u);
        s.insert(v);
    }
    set<int>::iterator it = s.begin();
    while (it != s.end()) {
        cout << *it << ' ';
        it++;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
        cout << '\n';
    }
}