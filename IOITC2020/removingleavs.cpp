#include <bits/stdc++.h>
using namespace std;
const int mxn = 20;
vector<int> g[mxn];
vector<long long> dp;
vector<int> dt, leaf;
int n, mask;
long long sum = 0;

void dfs(int v) {
	int c = 0;
	sum += dt[v];
	for(int u : g[v]) if(mask >> u & 1) {
		c++;
		dt[u] = dt[v] + 1;
		dfs(u);
	}
	if(!c)
		leaf.push_back(v);
}

void solve() {
	cin >> n;
	for(int i = 0; i <= n; i++)
		g[i].clear();
	dp.assign(1 << n, 0);
	dt.assign(n, 0);
	for(int i = 1; i < n; i++) {
		int p; cin >> p; p--;
		g[p].push_back(i);
	}
	dp[0] = 0;
	for(mask = 1; mask < (1 << n); mask++) {
		if(!(mask >> 0 & 1))
			continue;
		dt.assign(n, -1);
		leaf.clear();
		dt[0] = 0; sum = 0;
		dfs(0);
		bool res = true;
		for(int i = 0; i < n; i++) if(mask >> i & 1)
			if(dt[i] < 0) {
				res = false; break;
			}
		if(!res) continue;
		dp[mask] = sum;
		for(int v : leaf)
			dp[mask] = max(dp[mask], sum + dp[mask ^ (1 << v)]);
	}
	// for(mask = 0; mask < (1 << n); mask++)
	// 	cout << bitset<10>(mask) << ' ' << dp[mask] << '\n';
	cout << dp[(1 << n) - 1] << '\n';
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tc; cin >> tc;
    while(tc--) {
    	solve();
    }
    return 0;
}