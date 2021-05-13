#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int mxn = 100 * 1000 + 2;
vector<int> g[mxn], gt[mxn], order;
bool used[mxn];
map<int, int> cnt;
int mn, n, m, a[mxn];

void topo(int v) {
	used[v] = true;
	for(int u : g[v])
		if(!used[u])
			topo(u);
	order.push_back(v);
}

void dfs(int v) {
	used[v] = true;
	cnt[a[v]]++;
	mn = min(mn, a[v]);
	for(int u : gt[v])
		if(!used[u])
			dfs(u);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    cin >> m;
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	gt[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    	if(!used[i])
    		topo(i);
    reverse(order.begin(), order.end());
    for(int i = 1; i <= n; i++)
    	used[i] = false;
    long long sum = 0, ans = 1;
    for(int v : order) {
    	if(!used[v]) {
    		mn = mod;
    		cnt.clear();
    		dfs(v);
    		sum += mn;
    		(ans *= cnt[mn]) %= mod;
    	}
    }
    cout << sum << ' ' << ans << '\n';
    return 0;
}