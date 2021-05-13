#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 502;
const int inf = 1e16;
vector<array<int, 2>> g[N];
int dp[N][N], n;

void dfs(int v, int p) {
    for(int i = 0; i <= n; i++) dp[v][i] = inf;
    for(auto tx : g[v]) if(tx[0] != p) {
        dfs(tx[0], v);
    }
    dp[v][0] = 0;
    int x = g[v].size();
    vector<vector<int>> curdp(x + 1, vector<int>(n + 1, inf));
    curdp[0][0] = 0;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) curdp[i][j] = curdp[i - 1][j];
        int u = g[v][i - 1][0], w = g[v][i - 1][1];
        if(u == p) continue;
        for(int j = 1; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(j - k - 1 >= 0)
                    curdp[i][j] = min(curdp[i][j], 2 * w + dp[u][k] + curdp[i - 1][j - k - 1]);
            }
        }
    }
    for(int i = 1; i < n; i++) dp[v][i] = curdp[x][i];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    dfs(1, -1);
    for(int i = 1; i < n; i++) cout << dp[1][i] << '\n';
    return 0;
}
