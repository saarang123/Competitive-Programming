#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 100 * 1000 + 4;
vector<array<int, 2>> g[mxn];
int dt[mxn], p[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int u, v, w, _ = 0; _ < m; _++) {
    	cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    memset(dt, 0x7f, sizeof dt);
    memset(p, -1, sizeof p);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, 1});
    dt[1] = 0;
    while(!pq.empty()) {
    	int v = pq.top()[1], wt = pq.top()[0];
    	pq.pop();
    	if(dt[v] < wt)
    		continue;
    	for(auto tx : g[v]) {
    		int u = tx[0], w = tx[1];
    		if(dt[v] + w < dt[u]) {
    			dt[u] = dt[v] + w;
    			p[u] = v;
    			pq.push({dt[u], u});
    		}
    	}
    }
    if(dt[n] >= dt[0])
    	return cout << -1 << '\n', 0;
    vector<int> path;
    int to = n;
    while(to != -1) {
    	path.push_back(to);
    	to = p[to];
    }
    reverse(path.begin(), path.end());
    for(int node : path)
    	cout << node << ' ';
    cout << '\n';
    return 0;
}