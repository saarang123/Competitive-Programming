#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3;
vector<int> g[mxn];
multiset<int> p[mxn];
long long sum[mxn];
int c[mxn], a[mxn], n, m;
long long ans;

void dfs(int v) {
	p[v].insert(c[v]);
	sum[v] = c[v];
	for(int u : g[v]) {
		dfs(u);
		if(p[u].size() > p[v].size())
			swap(p[v], p[u]);
		for(int x : p[u])
			p[v].insert(x);
		sum[v] += sum[u];
	}
	while(sum[v] > m) {
		sum[v] -= *(--p[v].end());
		p[v].erase(--p[v].end());
	}
	ans = max(ans, (long long) p[v].size() * a[v]);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int x, i = 1; i <= n; i++) {
    	cin >> x >> c[i] >> a[i];
    	if(i > 1) 
    		g[x].push_back(i);
    }
    dfs(1);
    cout << ans << '\n';
    return 0;
}