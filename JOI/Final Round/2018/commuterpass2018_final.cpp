#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 100 * 1000 + 3, inf = 1e18;
vector<array<int, 2>> g[mxn];
vector<int> par[mxn], dpchild[mxn];
int n, m;

vector<int> dij(int src) {
	vector<int> dt(n + 1, inf);
	dt[src] = 0;
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
	pq.push({0, src});
	while(!pq.empty()) {
		auto [wt, u] = pq.top();
		pq.pop();
		if(dt[u] != wt) continue;
		for(auto [v, w] : g[u]) {
			if(dt[u] + w < dt[v]) {
				dt[v] = dt[u] + w;
				pq.push({dt[v], v});
			}
		}
	}
	return dt;
}

vector<int> dijk(int src) {
	vector<int> dt(n + 1, inf);
	dt[src] = 0;
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
	pq.push({0, src});
	while(!pq.empty()) {
		auto [wt, v] = pq.top(); pq.pop();
		if(dt[v] != wt) continue;
		for(auto [u, w] : g[v]) {
			if(dt[v] + w < dt[u]) {
				dt[u] = dt[v] + w;
				pq.push({dt[u], u});
				par[u].clear(); par[u].push_back(v);
			} else if(dt[v] + w == dt[u])
				par[u].push_back(v);
		}
	}
	return dt;
}

vector<bool> reach(int src) {
	vector<bool> reachable(n + 1);
	queue<int> q; q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (!reachable[u]) {
            reachable[u] = true;
            for(int v : par[u]) {
                dpchild[v].push_back(u);
                q.push(v);
            }
        }
    }
	return reachable;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int s, t, u, v;
    cin >> n >> m >> s >> t >> u >> v;
    for(int u1, v1, w, i = 0; i < m; i++) {
    	cin >> u1 >> v1 >> w;
    	g[u1].push_back({v1, w});
    	g[v1].push_back({u1, w});
    }
    vector<int> du = dij(u), dv = dij(v), ds = dijk(s);
    vector<bool> reachable = reach(t);
    vector<int> memo(n + 1, -1), memo2(n + 1, -1);
    function<int(int v1)> dp = [&] (int v1) {
    	if(memo[v1] != -1) return memo[v1];
    	memo[v1] = dv[v1];
    	for(int u1 : par[v1])
    		memo[v1] = min(memo[v1], dp(u1));
    	return memo[v1];
    };
    function<int(int v1)> dpback = [&] (int v1) {
    	if(memo2[v1] != -1) return memo2[v1];
    	memo2[v1] = dv[v1];
    	for(int u1 : dpchild[v1])
    		memo2[v1] = min(memo2[v1], dpback(u1));
    	return memo2[v1];
    };
    int ans = du[v];
    for(int i = 1; i <= n; i++) 
    	if(reachable[i])
    		ans = min(ans, du[i] + min(dp(i), dpback(i)));
    cout << ans << '\n';
    return 0;
}