#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200 * 1000 + 3, lgn = 20;
int up[mxn][lgn], d[mxn], dt[mxn], a[mxn];
int n, m;
vector<array<int, 2>> g[mxn];

void dfs(int v = 1, int p = 0, int w = 0) {
	up[v][0] = p;
	dt[v] = w;
	for(auto &[u, wt] : g[v]) if(u != p) {
		d[u] = d[v] + 1;
		dfs(u, v, w + wt);
	}
	for(int i = 1; i < lgn; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
}

void fix(int v, int p) {
	for(auto &[u, w] : g[v]) if(u != p) {
		fix(u, v);
		a[v] += a[u];
	}
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    freopen("runaway.in", "r", stdin);
    freopen("runaway.out", "w", stdout);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int u, w, i = 2; i <= n; i++) {
    	cin >> u >> w;
    	g[u].push_back({i, w});
    	g[i].push_back({u, w});
    }
    dfs();
    for(int i = 1; i <= n; i++) {
    	int x = i;
    	for(int j = lgn - 1; j >= 0; j--)
    		if(x != 1 && dt[i] - dt[up[x][j]] <= m)
    			x = up[x][j];
    	//cout << i << ' ' << x << ' ' << (d[x] - d[i]) << '\n';
    	a[i]++;	
    	a[up[x][0]]--;
    }
    fix(1, -1);
    for(int i = 1; i <= n; i++)
    	cout << a[i] << '\n';
    return 0;
}