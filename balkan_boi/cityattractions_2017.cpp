#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 2;
const int inf = 2e9;
vector<int> g[N];
int up[2][N], a[N], par[N];
array<int, 2> dp[N], dp_up[N];

void dfs(int v, int p) {
	par[v] = p;
	dp[v] = {-inf, -1};
	for(int u : g[v]) if(u != p) {
		dfs(u, v);
		dp[v] = max(dp[v], {dp[u][0] - 1, dp[u][1]});
		dp[v] = max(dp[v], {a[u] - 1, -u});
	}
}

void dfs_up(int v, int p) {
	dp_up[v] = {-inf, -1};
	if(p > 0) {
		dp_up[v] = max(dp_up[v], {dp_up[p][0] - 1, dp_up[p][1]});
		dp_up[v] = max(dp_up[v], {a[p] - 1, -p});
		for(int u : g[p]) if(u != v && u != par[p]) {
			dp_up[v] = max(dp_up[v], {dp[u][0] - 2, dp[u][1]});
			dp_up[v] = max(dp_up[v], {a[u] - 2, -u});
		}
	}
	for(int u : g[v]) if(u != p)
		dfs_up(u, v);
}

void fix(int n) {
	for(int i = 1; i <= n; i++)
		dp[i] = max(dp[i], dp_up[i]);
	for(int i = 1; i <= n; i++)
		up[0][i] = -dp[i][1];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n;
    long long k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
    	cin >> a[i];
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1, -1);
    dfs_up(1, -1);
    fix(n);
    int end = 1;
    if(k & 1)
    	end = up[0][end], k--;
    for(int i = 1; i <= 60 && k > 0; i++) {
    	for(int j = 1; j <= n; j++)
    		up[i & 1][j] = up[(i & 1) ^ 1][up[(i & 1) ^ 1][j]];
    	if(k >> i & 1LL)
    		end = up[i & 1][end], k -= (1LL << i);
    }
    cout << end << '\n';
    return 0;
}