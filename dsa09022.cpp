// DFS có hướng
// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh.
// Hãy viết thuật toán duyệt theo chiều sâu bắt đầu tại đỉnh u (DFS(u)=?)

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng:
// dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh,
// số cạnh và đỉnh bắt đầu duyệt; Dòng tiếp theo đưa vào các bộ đôi u,
// v tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra danh sách các đỉnh được duyệt theo thuật toán DFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.

// Ví dụ:
// Input:                                  Output:
// 1                                       5 4 3 1 2 6
// 6 9 5
// 1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 3

#include<bits/stdc++.h>
using namespace std;

int n, m, u;
int chuaxet[1005];
vector<int> List[1005];

void dfs(int u) {
    chuaxet[u] = false;
    cout << u << " ";
    for (int v : List[u]) {
        if (chuaxet[v]) {
            dfs(v);
        }
    }
}
int main()
{
    int t, u, x, y, i;
    cin >> t;
    while (t--) {
        memset(chuaxet, true, sizeof(chuaxet));
        for (i = 0; i < 1005; i++) {
            List[i].clear();
        }
        cin >> n >> m >> u;
        for (i = 1; i <= m; i++) {
            cin >> x >> y;
            List[x].push_back(y);
        }
        dfs(u);
        cout << '\n';
    }
    return 0;
}
