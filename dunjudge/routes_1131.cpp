#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 5e5 + 2;
vector<vector<int>> g;
vector<int> par, sz, dt, d, bi;
bool flag = 0;

void init(int n) {
	par.resize(n);
	iota(par.begin(), par.end(), 0);
	sz.assign(n, 1);
	dt.resize(n);
	bi.resize(n);
	d.assign(n, -1);
	g.assign(n, vector<int>());
}

int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }
bool same(int a, int b) { return fin(a) == fin(b); }

void join(int a, int b) {
	a = fin(a); b = fin(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
}

void dfs(int v, int p, int c) {
	if(d[v] != -1) {
		if(d[v] != c) flag = true;
		return;
	}
	d[v] = c;
	for(int u : g[v]) if(u != p) {
		dfs(u, v, c ^ 1);
	}
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    init(n);
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	g[u].push_back(v); g[v].push_back(u);
    	join(u, v);
    }
    for(int i = 0; i < n; i++) {
    	if(d[i] != -1) continue;
    	flag = 0; dfs(i, -1, 0);
    	bi[fin(i)] = flag;
    }
    while(q--) {
    	int u, v; cin >> u >> v;
    	if(!same(u, v)) cout << "none\n";
    	else if(bi[fin(u)]) cout << "both\n";
    	else {
    		cout << (d[u] == d[v] ? "even\n" : "odd\n");
    	}
    }
    return 0;
}