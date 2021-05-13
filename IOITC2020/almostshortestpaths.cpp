#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int mxn = 500 * 1000 + 5;
vector<int> g[mxn], p[mxn], same[mxn], dist[mxn];
int dt[mxn], dp[mxn][2];
int n, m;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    assert(n < mxn && m < mxn);
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    memset(dt, 0x7f, sizeof dt);
    queue<int> q;
    dt[1] = 0;
    q.push(1);
    while(!q.empty()) {
    	int u = q.front(); q.pop();
    	dist[dt[u]].push_back(u);
    	for(int v : g[u]) {
    		if(dt[v] == dt[u] - 1)
    			same[u].push_back(v);
    		else if(dt[v] == dt[u])
    			p[u].push_back(v);
    		else if(dt[v] > dt[u] + 1) {
    			dt[v] = dt[u] + 1;
    			q.push(v);
    		}
    	}
    }
    dp[1][0] = 1;
    for(int i = 1; i <= n; i++) {
    	if(dist[i].empty())
    		break;
    	for(int v : dist[i]) {
    		for(int u : same[v]) {
    			(dp[v][0] += dp[u][0]) %= mod;
    			(dp[v][1] += dp[u][1]) %= mod;
    		}
    	}
    	for(int v : dist[i]) {
    		for(int u : p[v])
    			(dp[v][1] += dp[u][0]) %= mod;
    	}
    }
    for(int i = 1; i <= n; i++) {
    	(dp[i][0] += dp[i][1]) %= mod;
    	cout << dp[i][0] << '\n';
    }
    return 0;
}