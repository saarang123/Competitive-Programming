#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 3;
vector<array<int, 4>> g[N];
int dt[N], mn[N], mx[N], diff[N];

void dfs(int v, int p, int d) {
	dt[v] = d;
	if(p != -1) mn[v] = min(mn[v], mn[p]);
	if(p != -1) mx[v] = max(mx[v], mx[p]);
	for(auto tx : g[v]) {
		int u = tx[0], w = tx[1], s = tx[2], e = tx[3];
		if(u == p) continue;
		mn[u] = e - d;
		mx[u] = s - d;
		dfs(u, v, d + w);
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
    int n, q;
    cin >> n >> q;
    for(int u, v, w, s, e, i = 1; i < n; i++) {
    	cin >> u >> v >> w >> s >> e;
    	g[u].push_back({v, w, s, e});
    	g[v].push_back({u, w, s, e});
    }
    for(int i = 0; i < n; i++) mn[i] = 1e16, mx[i] = -1e16;
    dfs(0, -1, 0);
    while(q--) {
    	int t, v;
    	cin >> v >> t;
    	cout << ((mx[v] <= t && t <= mn[v]) ? "YES" : "NO") << '\n';
    }
    return 0;
}