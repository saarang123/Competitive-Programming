#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;

int n, m, items;
vector<vector<long long>> g, best, buy, sell;

bool check(long long x) {
	vector<vector<long long>> dist(n, vector<long long>(n, -inf));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) 
			if(g[i][j] < inf)
				dist[i][j] = best[i][j] - g[i][j] * x;

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);

	for(int i = 0; i < n; i++)
		if(dist[i][i] >= 0)
			return true;
	return false;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> m >> items;
    g.assign(n, vector<long long>(n, inf));
    best.assign(n, vector<long long>(n));
    buy.resize(n, vector<long long>(items));
    sell.resize(n, vector<long long>(items));

    for(int i = 0; i < n; i++) 
    	for(int j = 0; j < items; j++)
    		cin >> buy[i][j] >> sell[i][j];

    while(m--) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	g[--u][--v] = w;
    }

    for(int k = 0; k < n; k++)
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < n; j++)
    			g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++) if(g[i][j] < inf)
    		for(int k = 0; k < items; k++) 
    			if(~buy[i][k] && ~sell[j][k])
    				best[i][j] = max(best[i][j], sell[j][k] - buy[i][k]);

    long long l = 0, r = 1000 * 1000 * 1000 + 3;
    while(l < r) {
    	long long mid = (l + r + 1) >> 1;
    	if(check(mid))
    		l = mid;
    	else
    		r = mid - 1;
    }

    cout << l << '\n';
    return 0;
}