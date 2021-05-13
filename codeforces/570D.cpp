#include <bits/stdc++.h>
using namespace std;
using node = map<int, int>;
const int N = 500 * 1000 + 3;
vector<int> g[N];
int a[N];
bool ans[N];
vector<array<int, 2>> q[N];

node dfs(int v, int p, int d) {
	node on;
	on[d] = (1 << a[v]);
	for(int u : g[v]) if(u != p) {
		node child = dfs(u, v, d + 1);
		if(child.size() > on.size()) swap(child, on);
		for(auto &[depth, count] : child)
			on[depth] ^= count;
	}
	for(auto &[h, id] : q[v]) {
		if(__builtin_popcount(on[h]) <= 1)
			ans[id] = true;
	}
	return on;
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
    for(int i = 2, x; i <= n; i++) {
    	cin >> x;
    	g[x].push_back(i);
    	g[i].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
    	char c; cin >> c;
    	a[i] = c - 'a';
    }
    for(int _ = 0; _ < m; _++) {
    	int v, h;
    	cin >> v >> h;
    	q[v].push_back({h, _});
    }
    dfs(1, -1, 1);
    for(int i = 0; i < m; i++)
    	cout << (ans[i] ? "Yes" : "No") << '\n';
    return 0;
}