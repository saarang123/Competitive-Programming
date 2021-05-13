#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 2;
const int mod = 1e9 + 7;
int dp[N][11][3];
int ndp[11][3];
int n, m, k, x;
vector<int> g[N];

void dfs(int v, int p) {
    dp[v][0][0] = k - 1; //parent is highest vault
    dp[v][1][1] = 1;     //current is highest vault
    dp[v][0][2] = m - k; //none are highest vault
    for(int u : g[v]) if(u != p) {
        dfs(u, v);
        for(int i = 0; i <= x; i++) ndp[i][0] = ndp[i][1] = ndp[i][2] = 0;
        for(int i = 0; i <= x; i++) {
            for(int j = 0; i + j <= x; j++) {
                (ndp[i + j][0] += (dp[v][i][0] * dp[u][j][0]) % mod) %= mod; //0 -> 0
                (ndp[i + j][0] += (dp[v][i][0] * dp[u][j][1]) % mod) %= mod; //0 -> 1
                (ndp[i + j][0] += (dp[v][i][0] * dp[u][j][2]) % mod) %= mod; //0 -> 2
                (ndp[i + j][1] += (dp[v][i][1] * dp[u][j][0]) % mod) %= mod; //1 -> 0
                (ndp[i + j][2] += (dp[v][i][2] * dp[u][j][0]) % mod) %= mod; //2 -> 0
                (ndp[i + j][2] += (dp[v][i][2] * dp[u][j][2]) % mod) %= mod; //2 -> 2
            }
        }
        swap(dp[v], ndp);
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    cin >> k >> x;
    dfs(1, -1);
    int ans = 0;
    for(int i = 0; i <= x; i++)
        (ans += dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) %= mod;
    cout << ans << '\n';
    return 0;
}
