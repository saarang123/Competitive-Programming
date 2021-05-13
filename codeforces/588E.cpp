#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
const int mxn = 100 * 1000 + 3, lgn = 18;
int dt[mxn], up[mxn][lgn];
vector<int> g[mxn], par[mxn][lgn];
int n, m, q;

vector<int> merge(vector<int> f, vector<int> gg) {
	if(f.size() < gg.size())
		swap(f, gg);
	for(int x : gg)
		f.push_back(x);
	sort(all(f));
	while(f.size() > 10)
		f.pop_back();
	return f;
}

void dfs(int v, int p = 1) {
	up[v][0] = p;
	for(int i = 1; i < lgn; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		par[v][i] = merge(par[v][i - 1], par[up[v][i - 1]][i - 1]);
	}
	for(int u : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		dfs(u, v);
	}
}

int kth(int a, int diff) {
	for(int i = 0; i < lgn; i++)
		if(diff >> i & 1)
			a = up[a][i];
	return a;
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

vector<int> fix(int v, int d) {
	vector<int> ret;
	for(int i = 0; i < lgn; i++) {
		if(d >> i & 1) {
			ret = merge(ret, par[v][i]);
			v = up[v][i];
		}
	}
	return ret;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m >> q;
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for(int c, i = 1; i <= m; i++) {
    	cin >> c;
    	par[c][0].push_back(i);
    	sort(all(par[c][0]));
    	while(par[c][0].size() > 10)
    		par[c][0].pop_back();
    }
    dfs(1);
    while(q--) {
    	int u, v, a;
    	cin >> u >> v >> a;
    	int l = lca(u, v);
    	vector<int> ans = merge(fix(u, dt[u] - dt[l]), fix(v, dt[v] - dt[l]));
    	ans = merge(ans, par[l][0]);
    	while(ans.size() > a)
    		ans.pop_back();
    	cout << ans.size() << ' ';
    	for(int x : ans)
    		cout << x << ' ';
    	cout << '\n';
    }
    return 0;
}