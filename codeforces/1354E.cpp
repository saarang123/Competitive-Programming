#include <bits/stdc++.h>
using namespace std;
const int mxn = 5002;
vector<int> g[mxn];
int ns[3], n, m, k, tot, two;
bool f[mxn];
int col[mxn], dp[mxn][mxn];
vector<int> cc[mxn], cp;
vector<array<int, 2>> cost;

void dfs(int v, int c) {
	col[v] = c;
	f[v] = true;
	tot++;
	two += (col[v] == 2);
	cc[k].push_back(v);
	for(int u : g[v]) {
		if(!f[u])
			dfs(u, c ^ 3);
		else if(col[u] == c) {
			cout << "NO" << '\n';
			exit(0);
		}
	}
}

bool ff(int id, int w) {
	if(w < 0) return false;
	if(id < 0)
		return (w == 0);
	if(dp[id][w] != -1)
		return dp[id][w];
	dp[id][w] = 0;
	dp[id][w] = dp[id][w] || ff(id - 1, w - cost[id][0]);
	dp[id][w] = dp[id][w] || ff(id - 1, w - cost[id][1]);
	return dp[id][w];
}

void fix(int id, int w) {
	if(id == -1) {
		if(w != 0) {
			cout << "NO" << '\n';
			exit(0);
		}
		return;
	}
	if(ff(id - 1, w - cost[id][0])) {
		fix(id - 1, w - cost[id][0]);
	}
	else if(ff(id - 1, w - cost[id][1])) {
		for(int u : cc[id])
			col[u] ^= 3;
		fix(id - 1, w - cost[id][1]);
	}
	else { 
		cout << "NO" << '\n';
		exit(0);
	}
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < 3; i++)
    	cin >> ns[i];
    for(int u, v, _ = 0; _ < m; _++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) if(!f[i]) {
    	tot = two = 0;
    	dfs(i, 1); //bipartite check
    	cp.push_back(i);
    	cost.push_back({two, tot - two});
    	k++;
    }
    fix(k - 1, ns[1]);  //knapsack for ns[1];
    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++) {
    	if(col[i] & 1 && ns[2]) col[i] = 3, ns[2]--;
    	cout << col[i];
    }
    cout << '\n';
    return 0;
}