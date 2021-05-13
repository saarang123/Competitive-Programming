#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int mxn = 500 * 1000 + 3;
vector<int> g[mxn];
ll pre[mxn][12];
array<int, 2> dp[mxn];
int n, k;

void dfs(int v, int p) {
	dp[v] = {0, 1};
	for(int u : g[v])
}
void solve() {
	cin >> n >> k;
	for(int u, v, i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    for(int i = 0; i < mxn; i++)
    	pre[i][0] = 1;
    for(int i = 0; i < mxn; i++)
    	for(int j = 1; j < 11; j++) {
    		pre[i][j] = pre[i][j - 1] * i;
    		if(pre[i][j] >= mod)
    			pre[i][j] %= mod;
    	}
    int tc; cin >> tc;
    while(tc--)
    	solve();
    return 0;
}