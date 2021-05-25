#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const vector<array<int, 2>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int MXN = 302;
const int inf = 1e9;
const int CST = 610;
vector<array<int, 2>> g[MXN * MXN];
vector<array<int, 2>> islands[MXN * MXN];
char a[MXN][MXN];
int idx[MXN][MXN], ans[MXN * MXN], mx[MXN * MXN], dist[MXN][MXN], closest[MXN][MXN];
int dp[MXN * MXN][CST];
int n, xa, ya, id;

bool in(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void dfs(int x, int y) {
	idx[x][y] = id;
	islands[id].push_back({x, y});
	for(auto &[dx, dy] : dir) 
		if(in(x + dx, y + dy) && idx[x + dx][y + dy] == -1 && a[x + dx][y + dy] == '1')
			dfs(x + dx, y + dy);
}

void solve() {
	cin >> n;
	id = 0;
	for(int i = 0; i <= n * n; i++) {
		g[i].clear();
		islands[i].clear();
		mx[i] = inf;
		ans[i] = 0;
		for(int j = 0; j < 2 * n + 5; j++)
			dp[i][j] = -1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			idx[i][j] = -1;
			closest[i][j] = 0;
			cin >> a[i][j];
		}
	cin >> xa >> ya;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) if(a[i][j] == '1' && idx[i][j] < 0) {
			++id; dfs(i, j);
		}

	int need = 0;
	mx[idx[xa][ya]] = 0;
	for(int i = 1; i <= id; i++) if(i != idx[xa][ya]) {
		int dt = inf;
		for(auto &[x, y] : islands[idx[xa][ya]])
			for(auto &[p, q] : islands[i])
				dt = min(dt, abs(x - p) + abs(y - q));
		need = max(need, mx[i] = dt);
	}

    for(int i = 1; i <= id; i++) {
    	for(int j = 1; j < i; j++) {
    		int dt = inf;
    		for(auto &[x, y] : islands[i])
    			for(auto &[p, q] : islands[j])
    				dt = min(dt, abs(x - p) + abs(y - q));
    		g[i].push_back({j, dt});
    		g[j].push_back({i, dt});
    	}
    }

    queue<array<int, 3>> pq;
    pq.push({0, 0, idx[xa][ya]});
    dp[idx[xa][ya]][0] = 0;

    while(!pq.empty()) {
    	auto [bt, cost, v] = pq.front();
    	pq.pop();
    	if(dp[v][cost] != bt)
    		continue;
    	for(auto &[u, w] : g[v]) if(cost + w <= need) {
    		if(dp[u][cost + w] < bt + 1) {
    			dp[u][cost + w] = bt + 1;
    			pq.push({bt + 1, cost + w, u});
    		}
    	}
    }

    for(int i = 1; i <= id; i++)
    	for(int j = 0; j <= mx[i]; j++)
    		ans[i] = max(ans[i], dp[i][j]);
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= n; j++) 
    		cout << ans[idx[i][j]] << ' ';
    	cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int tc; cin >> tc;
    while(tc--) 
    	solve();
    return 0;
}