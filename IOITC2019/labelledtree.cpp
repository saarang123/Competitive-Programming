#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int mxn = 100 * 1000 + 3;
vector<int> g[mxn];
int a[mxn];

int dfs(int v, int p, int d, int c) {
	if(a[v] <= c)
		return 0;
	int ans = d;
	for(int u : g[v]) if(u != p) {
		(ans += dfs(u, v, d + 1, c)) %= mod;
	}
	return ans;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
    	long long cnt = 0;
    	for(int u : g[i]) {
    		long long cur = dfs(u, i, 1, a[i]);
    		(ans += (cnt * cur)) %= mod;
    		(cnt += cur) %= mod;
    	}
    }
    (ans *= 2) %= mod;
    cout << ans << '\n';
    return 0;
}