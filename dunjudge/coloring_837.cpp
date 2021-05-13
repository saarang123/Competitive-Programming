#include <bits/stdc++.h>
using namespace std;
const int N = 50 * 1000 + 2;
vector<int> g[N];
bool a[N], vis[N];
int parent[N], sz[N], par[N];
vector<vector<int>> ans;

void init(int n) {
	for(int i = 0; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int fin(int v) { return parent[v] == v ? v : parent[v] = fin(parent[v]); }

bool join(int x, int y) {
	x = fin(x); y = fin(y);
	if(x == y)
		return false;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	parent[y] = x;
	return true;
}

int dfs(int v, int p) {
	par[v] = p;
	vis[v] = 1;
	vector<int> child;
	for(int u : g[v]) if(!vis[u]) {
		int c = dfs(u, v);
		if(c != -1) child.push_back(c);
	}
	if(a[v]) child.push_back(v);
	for(int i = 1; i < child.size(); i += 2) {
		int one = child[i - 1], two = child[i];
		vector<int> first, second;
		while(one != v) {
			first.push_back(one);
			one = par[one];
		}
		first.push_back(v);
		while(two != v) {
			second.push_back(two);
			two = par[two];
		}
		reverse(second.begin(), second.end());
		for(int u : second) first.push_back(u);
		ans.push_back(first);
	}
	if(child.size() % 2) return child.back();
	return -1;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    init(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    for(int u, v, _ = 0; _ < m; _++) {
    	cin >> u >> v;
    	if(join(u, v)) {
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    }
    for(int i = 0; i < n; i++) if(!vis[i]) {
    	dfs(i, -1);
    }
    cout << ans.size() << '\n';
    for(auto path : ans) {
    	cout << path.size() << ' ';
    	for(int v : path) cout << v << ' '; cout << '\n';
    }
    return 0;
}