#include<bits/stdc++.h>
using namespace std;

int n, chuaxet[1005];
vector<int> List[1005];

void DFS(int index) {
    chuaxet[index] = 0;
    for (auto x : List[index]) {
        if (chuaxet[x]) {
            chuaxet[x] = 0;
            DFS(index + 1);
        }
    }
}


int main() {
    memset(chuaxet, 1, 1005);
    int t, x, y;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            List[x].push_back(y);
            List[y].push_back(x);
        }
        DFS(1);
        bool check = true;
        for (int i = 2; i <= n; i++) {
            if (chuaxet[i]) {
                check = false;
            }
        }
        if (check) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}