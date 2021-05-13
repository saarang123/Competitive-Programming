#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3, lgn = 18;
vector<int> g[mxn];
int ans[mxn], sz[mxn], par[mxn], up[mxn][lgn], dt[mxn];
bool cent[mxn], conn[mxn];
int n, m, cnt;

void dfs(int v, int p = 1) {
    up[v][0] = p;
    for(int i = 1; i < lgn; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for(int u : g[v]) if(u != p) {
        dt[u] = dt[v] + 1;
        dfs(u, v);
    }
}

int kth(int v, int diff) {
    for(int i = 0; i < lgn; i++)
        if(diff >> i & 1)
            v = up[v][i];
    return v;
}

int lca(int a, int b) {
    if(dt[a] > dt[b]) swap(a, b);
    b = kth(b, dt[b] - dt[a]);
    if(a == b) return a;
    for(int i = lgn - 1; i >= 0; i--)
        if(up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
    return up[a][0];
}

int dist(int a, int b) {
    return dt[a] + dt[b] - 2 * dt[lca(a, b)];
}

int dfssz(int v, int p = -1) {
    sz[v] = 1;
    for(int u : g[v]) if(u != p && !cent[u])
        sz[v] += dfssz(u, v);
    return sz[v];
}

int fcent(int v, int p = -1) {
    for(int u : g[v]) if(u != p && !cent[u])
        if(sz[u] > cnt / 2)
            return fcent(u, v);
    return v;
}

void decompose(int v, int p = -1) {
    cnt = dfssz(v);
    int centroid = fcent(v);
    par[centroid] = p;
    cent[centroid] = true;
    for(int u : g[centroid]) if(u != p && !cent[u])
        decompose(u, centroid);
}

void upd(int v) {
    for(int p = v; p != -1; p = par[p])
        ans[p] = max(ans[p], dist(p, v));
}

int qry(int v) {
    int res = ans[0];
    for(int p = v; p != -1; p = par[p])
        res = max(res, ans[p] + dist(v, p));
    return res;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    freopen("newbarn.in", "r", stdin);
    freopen("newbarn.out", "w", stdout);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> m;
    vector<array<int, 2>> q(m);
    n = 0;
    for(auto &[t, v] : q) {
    	char c; cin >> c;
    	int p; cin >> p;
    	t = (c == 'Q');
    	if(!t) {
    		++n;
    		if(p > 0) {
    			g[p].push_back(n);
    			g[n].push_back(p);
    		}
    		v = n;
    	} else v = p;
    }
    for(int i = 1; i <= n; i++)
    	if(!dt[i])
    		dfs(i);
    for(int i = 1; i <= n; i++)
    	if(!par[i])
    		decompose(i);
    memset(ans, -0x7f, sizeof ans);
    for(auto &[t, v] : q) {
    	//cout << "Query: " << t << ' ' << v << endl;
    	if(t)
    		cout << qry(v) << '\n';
    	else
    		upd(v);
    }
    return 0;
}