#include <bits/stdc++.h>
using namespace std;
const int mxn = 20;
int dp[1 << mxn];
bool used[mxn];
vector<int> g[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for(int u, v, _ = 0; _ < m; _++) {
    	cin >> u >> v;
    	g[--u].push_back(--v);
    }
    for(int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = n * n;
        for(int i = 0; i < n; i++) if(mask >> i & 1) {
            int t = dp[mask ^ (1 << i)];
            for(int u : g[i]) if(mask >> u & 1)
                t++;
            dp[mask] = min(dp[mask], t);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}