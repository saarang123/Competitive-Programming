#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, mxn = 300 * 1000 + 3, lgn = 20;
vector<int> g[mxn];
vector<array<int, 2>> adj[mxn];
int dt[mxn], up[mxn][lgn], cmin[mxn], col[mxn], sub[mxn];
int n, m;

void init(int v, int p = 1) {
	up[v][0] = p;
	for(int i = 1; i < lgn; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(int u : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		init(u, v);
	}
}

int kth(int v, int diff) {
	for(int i = 0; i < lgn; i++)
		if(diff >> i & 1)
			v = up[v][i];
	return v;
}

int lca(int a, int b) {
	if(dt[a] > dt[b]) 
		swap(a, b);
	b = kth(b, dt[b] - dt[a]);
	if(a == b)
		return a;
	for(int i = lgn - 1; i >= 0; i--)
		if(up[a][i] != up[b][i])
			a = up[a][i], b = up[b][i];
	return up[a][0];
}

int connect(int v, int p = -1) {
	sub[v] = cmin[v];
	for(int u : g[v]) if(u != p) {
		sub[v] = min(sub[v], connect(u, v));
		if(sub[u] < dt[v]) {
			adj[u].push_back({v, 0});
			adj[v].push_back({u, 0});
		}
	}
	return sub[v];
}

bool dfs(int v, int c = 0) {
	col[v] = c;
	for(auto &[u, i] : adj[v]) {
		if(col[u] != -1 && (c ^ i) != col[u])
			return false;
		else if(col[u] < 0)
			if(!dfs(u, c ^ i))
				return false;
	}
	return true;
}

long long fexpo(long long a, int b) {
	long long ans = 1;
	while(b > 0) {
		if(b & 1)
			(ans = ans * a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
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
    cin >> n >> m;
    memset(col, -1, sizeof col);
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    init(1);
    for(int i = 1; i <= n; i++) 
    	cmin[i] = dt[i];
    while(m--) {
    	int u, v;
    	cin >> u >> v;
    	int lc = lca(u, v);
    	cmin[u] = min(cmin[u], dt[lc]);
    	cmin[v] = min(cmin[v], dt[lc]);
    	if(u != lc && v != lc) {
    		adj[u].push_back({v, 1});
    		adj[v].push_back({u, 1});
    	}
    }
    connect(1);
    int cnt = 0;
    for(int i = 2; i <= n; i++) if(col[i] < 0) {
    	if(!dfs(i))
    		return cout << 0 << '\n', 0;
    	cnt++;
    }
    cout << fexpo(2, cnt) << '\n';
    return 0;
}