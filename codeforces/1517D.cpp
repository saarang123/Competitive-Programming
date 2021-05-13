#include <bits/stdc++.h>
using namespace std;
const int mxn = 503;
vector<array<int, 3>> g[mxn][mxn];
int ans[23][mxn][mxn];
int n, m, k;

void out() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cout << ans[k][i][j] << ' ';
        cout << '\n';
    }
    exit(0);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m >> k;
    memset(ans, -1, sizeof ans);
    if(k & 1)
        out();
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j < m; j++) {
            int x; cin >> x;
            g[i][j].push_back({i, j + 1, x});
            g[i][j + 1].push_back({i, j, x});
        }
    for(int i = 1; i < n; i++)
         for(int j = 1; j <= m; j++) {
            int x; cin >> x;
            g[i][j].push_back({i + 1, j, x});
            g[i + 1][j].push_back({i, j, x});
        }
    memset(ans, 0x7f, sizeof ans);
    memset(ans[0], 0, sizeof ans[0]);
    for(int x = 2; x <= k; x += 2) 
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= m; j++) 
                for(auto &[p, q, w] : g[i][j])
                    ans[x][i][j] = min(ans[x][i][j], 2 * w + ans[x - 2][p][q]);
    out();
    return 0;
}