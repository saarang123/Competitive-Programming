#include <bits/stdc++.h>
using namespace std;
const int MXN = 200 * 1000 + 3;
vector<int> g[MXN];
int sz[MXN], a[MXN];
int n;
vector<int> centroids;

int init(int v = 1, int p = -1) {
	sz[v] = 1;
	for(int u : g[v]) if(u != p)
		sz[v] += init(u, v);
	return sz[v];
}

void fcent(int v = 1, int p = -1) {
	bool flag = 1;
	for(int u : g[v]) if(u != p)
		flag = flag && 2 * sz[u] <= n;
	if(p != -1)
		flag = flag && 2 * (n - sz[v]) <= n;
	if(flag)
		centroids.push_back(v);
	for(int u : g[v]) if(u != p)
		fcent(u, v);
}

void dfs(int v, int p, int root, int no) {
	a[v] = root;
	for(int u : g[v]) if(u != p && u != no) 
		dfs(u, v, root, no);
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
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    init();
    fcent();
    vector<array<int, 2>> paths(n / 2);
    for(auto &[u, v] : paths)
    	cin >> u >> v;
    int ans = MXN * 100;
    for(int c : centroids) {
    	for(int i = 1; i <= n; i++)
    		a[i] = 0;
    	for(int u : g[c])
    		dfs(u, c, u, c);
    	vector<int> cnt(n + 1);
    	for(auto &[u, v] : paths)
    		if(a[u] == a[v])
    			cnt[a[u]]++;
    	int mx = 0, sum = 0;
    	for(int i = 1; i <= n; i++)
    		sum += cnt[i], mx = max(mx, cnt[i]);
    	ans = min(ans, max((sum + 1) / 2, mx));
    }
    cout << ans << '\n';
    return 0;
}